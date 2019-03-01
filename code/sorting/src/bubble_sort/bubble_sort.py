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


# Less elegant solution, but easier to follow along:
def bubble_sort(alist):
    is_sorted = False
    while is_sorted == False:
        num_swaps = 0
        blist = []
        for i in range(len(alist)-1):
            if alist[i] > alist[i+1]:
                a = alist.pop(i+1)
                alist.insert(i, a)
                num_swaps += 1
        if num_swaps == 0:
                is_sorted = True
    return alist
