'''
Part of Cosmos by OpenGenus Foundation
'''
 
def search(arr, x):
 
    for i in range(len(arr)):
 
        if arr[i] == x:
            return i
 
    return -1



arr = []
elem = int(raw_input("insert how many elements you want:"))
for i in range(0, elem):
    arr.append(int(raw_input("Enter next no :")))
  
find = input("Enter the number you want to find")
position = search(arr, find)
if( position >= 0):
	print("Position of ", find, " is ", position)
else:
	print(find," not found")
