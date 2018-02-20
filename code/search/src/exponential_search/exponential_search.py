'''

Exponential Search

'''


def binarySearch(arr, left, right, element):
    if right >= left:
        mid = left + (right - left) // 2

        if arr[mid] == element:
            return mid

        elif arr[mid] > element:
            return binarySearch(arr, left, mid - 1, element)

        else:
            return binarySearch(arr, mid + 1, right, elment)

    return -1


def exponentialSearch(arr, element):
    if arr[0] == element:
        return 0

    i = 1
    arrLength = len(arr)
    while i < arrLength and arr[i] <= element:
        i *= 2

    return binarySearch(arr, i / 2, min(i, arrLength), element)
