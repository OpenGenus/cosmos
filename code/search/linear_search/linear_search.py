'''
Part of Cosmos by OpenGenus Foundation
'''
def linear_search(arr, x):
    for i in range(len(arr)):
        if arr[i] == x:
            return i
    return -1
arr = []
num_elems = int(raw_input("Enter how many elements do you want: "))
for i in range(num_elems):
    num = int(raw_input("Enter next no :"))
    arr.append(num)
  
find = int(raw_input("Enter the number you want to find: "))
print("Position of ", find, " is ", linear_search(arr, find))
