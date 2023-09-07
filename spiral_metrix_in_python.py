
# -*- coding: utf-8 -*-
"""
Created on Fri Oct  9 23:54:38 2020

@author: soura
"""

 
def spiral_matrix(matrix, i, j, x, y):
 
    #base case
    if (i >= x or j >= y):                # If i or j lies outside the matrix
        return
    for p in range(i, y):
        print(matrix[i][p], end=" ")         # Print First Row
    for p in range(i + 1, x):
        print(matrix[p][y- 1], end=" ")      # Print Last Column
    if ((x- 1) != i):
        for p in range(y- 2, j - 1, -1):
            print(matrix[x- 1][p], end=" ")  # Print Last Row, if Last and
                                          # First Row are not same
    if ((y - 1) != j):
        for p in range(x - 2, i, -1):     # Print First Column, if Last and
            print(matrix[p][j], end=" ")     # First Column are not same
    #recursive case
    spiral_matrix(matrix, i + 1, j + 1, x- 1, y - 1)
 
 
# Driver code
rows = int(input("enter the number of row "))
cols=  int(input("enter the number of column"))
matrix = [] 
 
      # For user input 
for i in range(rows):          # A for loop for row entries 
    a =[] 
    for j in range(cols):      # A for loop for column entries 
         a.append(int(input())) 
    matrix.append(a) 
# Function Call
spiral_matrix(matrix, 0, 0, rows, cols)