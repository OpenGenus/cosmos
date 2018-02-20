'''
Part of Cosmos by OpenGenus Foundation
'''


def _binary_search_recursive_impl(arr, x, l, r):
    if r > l:
        mid = l + int((r - l) / 2)

        if arr[mid] == x:
            return mid

        elif arr[mid] > x:
            return _binary_search_recursive_impl(arr, x, l, mid - 1)

        else:
            return _binary_search_recursive_impl(arr, x, mid + 1, r)

    else:
        return l if l >= 0 and l < len(arr) and arr[l] == x else -1


def binary_search_recursive(arr, x):
    return _binary_search_recursive_impl(arr, x, 0, len(arr))


def _binary_search_interactive_impl(arr, x, l, r):
    while l < r:
        mid = l + int((r - l) / 2)

        if arr[mid] == x:
            return mid
        elif arr[mid] > x:
            r = mid - 1
        else:
            l = mid + 1

    return l if l >= 0 and l < len(arr) and arr[l] == x else -1


def binary_search_interactive(arr, x):
    return _binary_search_interactive_impl(arr, x, 0, len(arr))


binary_search = binary_search_interactive
