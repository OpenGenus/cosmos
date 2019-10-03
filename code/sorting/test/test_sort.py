"""
Part of Cosmos by OpenGenus Foundation
"""


import random
import copy

# import bead_sort # result error
# import bead_sort_numpy # error
# import bucket_sort # error
# import circle_sort # error, tried
# import counting_sort # error, tried
# import radix_sort # error

# sort_func = bead_sort.bead_sort
# sort_func = bead_sort_numpy.bead_sort
# sort_func = bogo_sort.bogo_sort
# sort_func = bubble_sort.bubble_sort
# sort_func = bucket_sort.bucket_sort
# sort_func = circle_sort.circle_sort
# sort_func = counting_sort.counting_sort
# sort_func = cycle_sort.cycle_sort
# sort_func = gnome_sort.gnome_sort
# sort_func = heap_sort.heap_sort
# sort_func = merge_sort.merge_sort
# sort_func = quick_sort.quick_sort
# sort_func = radix_sort.radix_sort
# sort_func = selection_sort.selection_sort
# sort_func = shaker_sort.shaker_sort


ELEM_MODE = "ALLOW_DUPLICATE"
# ELEM_MODE = "UNIQUE"


print(sort_func)


def fill(arr, size):
    i = 0

    # elems may not be continuous
    if ELEM_MODE == "ALLOW_DUPLICATE":
        while len(arr) < size:
            if random.randint(0, 2) % 2:
                arr.extend([i])
            if random.randint(0, 2) % 2:
                arr.extend([i])
            i += 1

        if len(arr) > size:
            del arr[len(arr) - 1]

    elif ELEM_MODE == "UNIQUE":
        while len(arr) < size:
            if random.randint(0, 2) % 2:
                arr.extend([i])
            i += 1


def randomize(arr):
    LENGTH = len(arr)

    for i in range(LENGTH):
        r = random.randint(0, LENGTH - 1)
        arr[i], arr[r] = arr[r], arr[i]


def is_same(expect, actual):
    assert len(expect) == len(actual)

    for i in range(len(expect)):
        assert expect[i] == actual[i]


def test_size_by_times(size, times):
    for i in range(times):
        # GIVEN
        expect = []
        fill(expect, size)
        actual = copy.copy(expect)
        randomize(actual)

        # WHEN
        sort_func(actual)

        # THEN
        is_same(expect, actual)


test_size_by_times(0, 1)
test_size_by_times(1, 1)
test_size_by_times(2, 1000)
test_size_by_times(3, 1000)
test_size_by_times(random.randint(1e4, 1e5), 1)
print("passed")
