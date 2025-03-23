#For Hacktoberfest 2021
import numpy as np

rows = int(input("Enter number of rows "))
cols = int(input("Enter number of columns "))
arr = np.zeros([7,16],dtype = int)
num = 0
flag = 0
i = 0
j = 0

while j <= cols-1:
    if i<=rows-1 and flag == 0:
        num = num + 1
        arr[i][j] = num
        if i == rows - 1 :
            i = i - 1
            j = j + 1
            flag = 1
        else:
            i = i + 1
            j = j + 1

    elif (i<rows-1 and i>=0) and flag == 1:
        num = num + 1
        arr[i][j] = num
        if i == 0:
            i = i + 1
            j = j + 1
            flag = 0
        else:
            i = i - 1
            j = j + 1 

for i in range(rows):
    for j in range(cols):
        if(arr[i][j] == 0):
            print(" ",end =" ")
        else:
            print(arr[i][j],end =" ")
    print()
