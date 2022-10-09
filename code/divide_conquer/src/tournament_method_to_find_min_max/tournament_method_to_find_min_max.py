from math import nan

def getMinMax(arr, low, high):

    minmax = [nan,nan]
    
    if low == high:
        minmax[1] = arr[low]
        minmax[0] = arr[low]   
        return minmax

    if high == low + 1: 
        if arr[low] > arr[high]:
            minmax[1] = arr[low]
            minmax[0] = arr[high]
         
        else:
            minmax[1] = arr[high]
            minmax[0] = arr[low]
        return minmax

    mid = int((low + high) / 2)
    mml = getMinMax(arr, low, mid)
    mmr = getMinMax(arr, mid + 1, high)

    if mml[0] < mmr[0]:
        minmax[0] = mml[0]
    else:
        minmax[0] = mmr[0]

    if mml[1] > mmr[1]:
        minmax[1] = mml[1]
    else:
        minmax[1] = mmr[1]

    return minmax

arr_size = int(input("Enter size of the Array:"))
arr = []
print(f"Enter {arr_size} Integers:-")
for i in range(arr_size):
    arr.append(int(input()))

minmax = getMinMax(arr, 0, arr_size - 1)
print(f"Minimum element is {minmax[0]}")
print(f"Maximum element is {minmax[1]}")

