#!/usr/bin/env python3
#-*- coding: utf-8 -*-

"""
Given an Array A[0..N-1] of length N and Q queries over subarrays A[L_i:R_i].
Answer all queries. For example, calculate the sum in each intervals [L_i, R_i).

Runtime:
- naive: O(Q * N) to compute Q queries of max length N independently
- Mo's Algorithm: O((Q + N) * sqrt(N) * F) where F is the time to calculate
  query [L, R) from [L, R-1) etc.

Mo's algorithm sorts the queries in a smart way and answers them sequentially
reusing the previous answer.
"""

import math


class MoOperations:
    """
    Subclass this to implements the required operations for expanding/shrinking
    an interval as well as a function to calculate the answer to the initial
    query.

    The upper bound of the runtime of all expand/shrink functions
    is called O(F).
    """
    def evaluate(self, arr, l, r):
        raise NotImplementedError('Implement evaluation function')

    def expand_left(self, current, new_left):
        raise NotImplementedError('Implement expand')

    def shrink_left(self, current, old_left):
        raise NotImplementedError('Implement shrink')

    def expand_right(self, current, new_right):
        # Default implementation in case the operation is commutative.
        return self.expand_left(current, new_right)

    def shrink_right(self, current, old_right):
        # Default implementation in case the operation is commutative.
        return self.shrink_left(current, old_right)


class IntervalSum(MoOperations):
    """Example operations for the subset"""
    def evaluate(self, arr, l, r):
        return sum(arr[l:r])

    def expand_left(self, current, new_left):
        return current + new_left

    def shrink_left(self, current, old_left):
        return current - old_left


def mo_sort(arr, queries):
    """Sort the query intervals for Mo's Algorithm."""
    # Sort by starting block, then ending block.
    block_size = int(math.sqrt(len(arr)))

    return sorted(queries,
                  key=lambda i: (i[0]//block_size, i[1]//block_size))


def mos_algorithm(arr, queries, ops):
    """
    Args:
        arr (list): The input array.
        queries (list[(int, int)]): List of queried intervals.
        ops (MoOperations): Operations to evaluate, shrink and
            expand an interval.
    Returns:
        Mapping of query interval to answer.
    """
    mos_order = mo_sort(arr, queries)
    print(arr)
    print(mos_order)

    # Calculate queries incrementally.
    # We want that the queries are as similar as possible, i.e. start
    # in the same block.
    answers = {}

    # Incrementally shrink/expand the starting interval to match
    # the next query.
    mo_left = 0
    mo_right = 0
    current = ops.evaluate(arr, mo_left, mo_right)

    for l, r in mos_order:
        while l < mo_left:
            mo_left -= 1
            current = ops.expand_left(current, arr[mo_left])

        while l > mo_left:
            current = ops.shrink_left(current, arr[mo_left])
            mo_left += 1

        while r < mo_right:
            mo_right -= 1
            current = ops.shrink_right(current, arr[mo_right])

        while r > mo_right:
            current = ops.expand_right(current, arr[mo_right])
            mo_right += 1

        answers[(l, r)] = current

    return answers


if __name__ == '__main__':
    import unittest

    class TestMosAlgorithm(unittest.TestCase):
        def setUp(self):                
            self.arr = list(range(0, 10))
            self.queries = [(1, 1), (2, 3), (5, 9), (0, 9), (2, 5), (3, 7)]

        def test_mo_sort(self):
            self.assertListEqual(mo_sort(self.arr, self.queries),
                [(1, 1), (2, 3), (2, 5), (0, 9), (3, 7), (5, 9)])

        def test_sum(self):
            answers = mos_algorithm(self.arr, self.queries, IntervalSum())

            for (l, r) in self.queries:
                print(answers[(l, r)], sum(self.arr[l:r]),
                      'Interval [{},{})'.format(l, r))

    unittest.main()
