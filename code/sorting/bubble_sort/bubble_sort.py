'''

Part of Cosmos by OpenGenus Foundation

'''


def bubbleSort(arr):
    for i in range(len(arr)):
        for j in range(1, len(arr)):
            if arr[j - 1] > arr[j]:
                arr[j - 1], arr[j] = arr[j], arr[j - 1]

arr = [5, 1, 3, 9, 2]
bubbleSort(arr)
print('Sorted array after Bubble Sort:', arr)
