'''
Part of Cosmos by OpenGenus Foundation
'''
def linear_search(arr, x):
    for i in range(len(arr)):
        if arr[i] == x:
            return i
    return -1

arr = []
while True:
    inp = raw_input("Enter a number (non number to stop):")
    if not inp.isdigit():
        break
    arr.append(int(inp))
  
find = int(raw_input("Enter the number you want to find: "))
print "Position of " + str(find) + " is " + str(linear_search(arr, find))
