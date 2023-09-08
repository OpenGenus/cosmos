'''
Part of Cosmos by OpenGenus Foundation
'''

def binarySearch (arr, l, r, x):
 
    if r >= l:
 
        mid = l + (int)((r - l)/2)
 
        if arr[mid] == x:
            return mid
         
        elif arr[mid] > x:
            return binarySearch(arr, l, mid-1, x)
 
        else:
            return binarySearch(arr, mid+1, r, x)
 
    else:
        return -1
 
arr = [ 1, 2, 3, 5 ]
find = 3
 
print("Position of ",find," is ",binarySearch(arr, 0, len(arr)-1, find))
