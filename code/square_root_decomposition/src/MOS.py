from functools import partial
import math


def compare(block_size, x, y):
    """The heart of the Mo's algorithm - determines if a range preceeds another."""
    _, (x_left, x_right) = x
    _, (y_left, y_right) = y

    if x_left / block_size != y_left / block_size:
        return x_left / block_size < y_left / block_size

    return x_right < y_right


def get_expected_result(a, queries):
    """Calculates given queries as sums of given ranges."""
    return {key: sum(a[left:right + 1]) for key, (left, right) in queries.items()}


def mos_algorithm(a, queries):
    """Mo's algorithm implementation."""
    block_size = math.sqrt(len(a))

    cur_sum, cur_left, cur_right = 0, 0, -1
    result = {}
    for key, (left, right) in sorted(queries.items(), cmp=partial(compare, block_size)):
        while cur_right < right:
            cur_right += 1
            cur_sum += a[cur_right]

        while cur_right > right:
            cur_sum -= a[cur_right]
            cur_right -= 1

        while cur_left < left:
            cur_sum -= a[cur_left]
            cur_left += 1

        while cur_left > left:
            cur_left -= 1
            cur_sum += a[cur_left]

        result[key] = cur_sum

    return result


if __name__ == '__main__':
    a = [1, 1, 2, 1, 3, 4, 5, 2, 8]
    queries = {0: [0, 5], 1: [5, 8], 2: [2, 4], 3: [5, 6]}

    result = mos_algorithm(a, queries)
    expected_result = get_expected_result(a, queries)

    print(result)
    print(expected_result)
