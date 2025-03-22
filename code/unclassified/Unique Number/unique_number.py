def findUniqueNumber(arr):
    store = arr[0]
    for i in range(len(arr)):
        store = store ^ arr[i]
    return store


a = [1, 2, 3, 3, 2, 4]
print(findUniqueNumber(a))
