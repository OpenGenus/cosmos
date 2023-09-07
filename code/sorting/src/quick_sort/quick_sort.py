"""
Part of Cosmos by OpenGenus Foundation
"""

# The idea behind quick sort is to pick an element and partition
# the remaining array into two arrays: the left one containing elements
# smaller (or larger if the sort is in descending order) and the right
# one containing elements larger (or smaller if the sort is in descending order).
# These partitioned arrays are then sorted recursively in a similar fashion.

# This is a classic divide-and-conquer algorithm where the divide step (partitioning)
# takes up the majority of the time and the conquer step (combining the left and right
# halves with the helper function) is trivial. Generally, the algorithm runs in O(nlogn)
# except in the case where the input provided is already sorted in the opposite order.

# In this case, the algorithm runs in O(n^2) if the first element is chosen as a pivot,
# because each time during partition the entire array on the right gets shifted to the left.
# This then becomes similar to running selection sort.

from random import randint

def quick_sort(arr, asc=True):
    quick_sort_helper(arr, 0, len(arr) - 1, asc)


def quick_sort_helper(arr, first, last, asc=True):
    condition = lambda x, y: x < y if asc else x > y
    if first <= last:
        splitpoint = partition(arr, first, last, asc)

        quick_sort_helper(arr, first, splitpoint - 1, asc)
        quick_sort_helper(arr, splitpoint + 1, last, asc)


def partition(arr, first, last, asc=True):
    condition = lambda x, y: x <= y if asc else x >= y
    pivot = arr[first]

    left = first + 1
    right = last

    done = False
    while not done:

        while left <= right and condition(arr[left], pivot):
            left = left + 1

        while condition(pivot, arr[right]) and right >= left:
            right = right - 1

        if right < left:
            done = True
        else:
            temp = arr[left]
            arr[left] = arr[right]
            arr[right] = temp

    temp = arr[first]
    arr[first] = arr[right]
    arr[right] = temp

    return right

randomized = [randint(0, 1000) for x in range(100)]
clone = randomized.copy()
quick_sort(randomized)
assert sorted(clone) == randomized

new_randomized = [randint(0, 1000) for x in range(100)]
new_clone = new_randomized.copy()
quick_sort(new_randomized, False)
assert sorted(new_clone, reverse=True) == new_randomized