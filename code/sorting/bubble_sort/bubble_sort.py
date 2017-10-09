# Part of Cosmos by OpenGenus Foundation


def bubble_sort(arr):
    '''
    >>> arr = [5, 1, 3, 9, 2]
    >>> bubble_sort(arr)
    >>> arr
    [1, 2, 3, 5, 9]
    '''
    for i in range(len(arr)):
        for j in range(i + 1, len(arr)):
            if arr[i] > arr[j]:
                arr[i], arr[j] = arr[j], arr[i]
