'''
Part of Cosmos by OpenGenus Foundation
'''
 
def search(arr, x):
 
    for i in range(len(arr)):
 
        if arr[i] == x:
            return i
 
    return -1

arr = [2,3,1,4]
find = 1
print("Position of ", find, " is ", search(arr, find))