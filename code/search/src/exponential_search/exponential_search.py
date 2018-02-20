'''

Exponential Search

'''


def _binary_search(arr, element, left, right):
    if right > left:
        mid = left + (right - left) // 2

        if arr[mid] == element:
            return mid

        elif arr[mid] > element:
            return _binary_search(arr, element, left, mid - 1)

        else:
            return _binary_search(arr, element, mid + 1, right)

    return left if left >= 0 and left < len(arr) and arr[left] == element else -1


def exponential_search(arr, element):
    if len(arr) == 0:
        return -1

    if arr[0] == element:
        return 0

    i = 1
    arrLength = len(arr)
    while i < arrLength and arr[i] <= element:
        i *= 2

    return _binary_search(arr, elment, i / 2, min(i, arrLength))
