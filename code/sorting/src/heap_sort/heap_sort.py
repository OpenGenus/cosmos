# Part of Cosmos by OpenGenus Foundation
import math


def heap_root(arr, i, length):
    left = 2 * i + 1
    right = 2 * i + 2
    max_index = i

    if left < length and arr[left] > arr[max_index]:
        max_index = left

    if right < length and arr[right] > arr[max_index]:
        max_index = right

    if max_index != i:
        swap(arr, max_index, i)
        heap_root(arr, max_index, length)


def swap(arr, a, b):
    arr[a], arr[b] = arr[b], arr[a]


# sorting is in the ascending order
def heap_sort(arr):
    # form a max heap
    for i in range(math.floor(len(arr) / 2), -1, -1):
        heap_root(arr, i, len(arr))

    length = len(arr)
    # remove the root and reform the heap
    for i in range(len(arr) - 1, 0, -1):
        swap(arr, 0, i)
        length -= 1
        heap_root(arr, 0, length)
