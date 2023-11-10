import sys
import os

sys.path.insert(0, os.path.realpath(__file__ + "/../../"))
import bisect
import random
import src.linear_search.linear_search
import src.binary_search.binary_search
import src.fibonacci_search.fibonacci_search
import src.ternary_search.ternary_search
import src.jump_search.jump_search
import src.interpolation_search.interpolation_search
import src.exponential_search.exponential_search

search_func = None
search_funcs = []
search_funcs += [src.linear_search.linear_search.linear_search]
search_funcs += [src.binary_search.binary_search.binary_search_recursive]
search_funcs += [src.binary_search.binary_search.binary_search_interactive]
search_funcs += [src.fibonacci_search.fibonacci_search.fibonacci_search]
search_funcs += [src.ternary_search.ternary_search.ternary_search]
search_funcs += [src.jump_search.jump_search.jump_search]
search_funcs += [src.interpolation_search.interpolation_search.interpolation_search]
search_funcs += [src.exponential_search.exponential_search.exponential_search]


COMPARE_MODE = "ANY_SAME_NODE"
'COMPARE_MODE = "LOWER_BOUND"'


ELEM_MODE = "ALLOW_DUPLICATE"
'ELEM_MODE = "UNIQUE"'


def index(a, x):
    "Locate the leftmost value exactly equal to x"
    i = bisect.bisect_left(a, x)
    if i != len(a) and a[i] == x:
        return i
    return -1


def fill(arr, size):
    i = 0
    if ELEM_MODE == "ALLOW_DUPLICATE":
        while len(arr) < size:
            arr.extend([i])
            if random.randint(0, 2) % 2:
                arr.extend([i])
            i += 1

    elif ELEM_MODE == "UNIQUE":
        while len(arr) < size:
            arr.extend([i])
            i += 1


def testSizeByTimes(size, times):
    for t in range(times):
        arr = []
        fill(arr, size)
        for i in range(-30, len(arr) * 2):
            expect = index(arr, i)
            actual = search_func(arr, i)
            same = expect == actual
            diff = expect in range(0, len(arr)) and arr[expect] == arr[actual]

            if COMPARE_MODE == "ANY_SAME_NODE":
                assert same or diff
            elif COMPARE_MODE == "LOWER_BOUND":
                assert same


if __name__ == "__main__":
    for func in search_funcs:
        search_func = func
        print(search_func)
        testSizeByTimes(0, 1)
        testSizeByTimes(1, 1)
        testSizeByTimes(2, 1000)
        testSizeByTimes(3, 1000)
        testSizeByTimes(random.randint(1e4, 1e5), 1)

    print("passed")
