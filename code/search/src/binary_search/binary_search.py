"""
Part of Cosmos by OpenGenus Foundation
"""


def _binary_search_recursive_impl(arr, x, left, right):
    if right > left:
        mid = left + int((right - left) / 2)

        if arr[mid] == x:
            return mid

        elif arr[mid] > x:
            return _binary_search_recursive_impl(arr, x, left, mid - 1)

        else:
            return _binary_search_recursive_impl(arr, x, mid + 1, right)

    else:
        return left if left in range(0, len(arr)) and arr[left] == x else -1


def binary_search_recursive(arr, x):
    return _binary_search_recursive_impl(arr, x, 0, len(arr))


def _binary_search_iterative_impl(arr, x, left, right):
    while left < right:
        mid = left + int((right - left) / 2)

        if arr[mid] == x:
            return mid
        elif arr[mid] > x:
            right = mid - 1
        else:
            left = mid + 1

    return left if left in range(0, len(arr)) and arr[left] == x else -1


def binary_search_iterative(arr, x):
    return _binary_search_iterative_impl(arr, x, 0, len(arr))


binary_search = binary_search_iterative
