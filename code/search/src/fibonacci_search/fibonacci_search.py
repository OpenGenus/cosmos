"""
Part of Cosmos by OpenGenus Foundation
"""


def fibonacci_search(arr, x):
    length = len(arr)
    fib_m2 = 0
    fib_m1 = 1
    fib_m = fib_m2 + fib_m1

    while fib_m < length:
        fib_m2 = fib_m1
        fib_m1 = fib_m
        fib_m = fib_m2 + fib_m1

    offset = -1
    while fib_m > 1:
        i = min(offset + fib_m2, length - 1)

        if arr[i] < x:
            fib_m = fib_m1
            fib_m1 = fib_m2
            fib_m2 = fib_m - fib_m1
            offset = i
        elif arr[i] > x:
            fib_m = fib_m2
            fib_m1 = fib_m1 - fib_m2
            fib_m2 = fib_m - fib_m1
        else:
            return i

    if fib_m1 and offset < length - 1 and arr[offset + 1] == x:
        return offset + 1

    return -1
