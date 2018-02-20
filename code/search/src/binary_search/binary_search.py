'''
Part of Cosmos by OpenGenus Foundation
'''


def _binary_search_recursive_impl(arr, l, r, x):
    if r >= l:

        mid = l + int((r - l) / 2)

        if arr[mid] == x:
            return mid

        elif arr[mid] > x:
            return _binary_search_recursive_impl(arr, l, mid - 1, x)

        else:
            return _binary_search_recursive_impl(arr, mid + 1, r, x)

    else:
        return -1

def binary_search_recursive(arr, x):
    return _binary_search_recursive_impl(arr, 0, len(arr), x)

def _binary_search_interactive_impl(arr, l, r, x):
    while l <= r:
        mid = l + int((r - l) / 2)

        if arr[mid] == x:
            return mid
        elif arr[mid] > x:
            r = mid - 1
        else:
            l = mid + 1

    return -1

def binary_search_interactive(arr, x):
    return _binary_search_interactive_impl(arr, 0, len(arr), x)

binary_search = binary_search_interactive
