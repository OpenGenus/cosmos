'''
Part of Cosmos by OpenGenus Foundation
'''


def binarySearchRecursive(arr, l, r, x):
    if r >= l:

        mid = l + int((r - l) / 2)

        if arr[mid] == x:
            return mid

        elif arr[mid] > x:
            return binarySearchRecursive(arr, l, mid - 1, x)

        else:
            return binarySearchRecursive(arr, mid + 1, r, x)

    else:
        return -1


def binarySearchLoop(arr, l, r, x):
    while l <= r:
        mid = l + int((r - l) / 2)

        if arr[mid] == x:
            return mid
        elif arr[mid] > x:
            r = mid - 1
        else:
            l = mid + 1

    return -1


arr = [1, 2, 3, 5]
find = 3

print("Position of ", find, " is ", binarySearchLoop(arr, 0, len(arr) - 1, find))
print("Position of ", find, " is ", binarySearchRecursive(arr, 0, len(arr) - 1, find))