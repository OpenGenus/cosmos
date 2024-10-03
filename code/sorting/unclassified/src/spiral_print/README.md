# cosmos
> Your personal library of every algorithm and data structure code that you will ever encounter

# Spiral Printing

The aim is to print a given 2D array in spiral form.

We take the dimensions of the array and the array as an input from the user. Dimensions of matrix are taken as mxn where m are the number of rows and n are the number of columns of the matrix.

To print the matrix in spiral form we first keep a variable direction which can take 4 possible values : 0,1,2,3. 0 means we will print the first row from top which is not printed yet , 1 means first column from right, 2 means first rwo from bottom and 3 means first column from left. We will also be keeping four variables top,bottom,left and right initialised with 0,m-1,0,n-1 respectively which will give us the index of the extremes to be printed.

-When direction = 0 , we print the top row from index left to right
and we increment top by 1

-When direction = 1 , we print the right column from index top to bottom
and we decrement right by 1

-When direction = 2 , we print the bottom row from index right to left
and we decrement bottom by 1

-When direction = 3 , we print the left column from index bottom to top
and we increment left by 1

# Example 

Input:
 1  2  3  4  5  6
 7  8  9 10 11 12
13 14 15 16 17 18

Output: 
1 2 3 4 5 6 12 18 17 16 15 14 13 7 8 9 10 11

---

<p align="center">
	A massive collaborative effort by <a href="https://github.com/OpenGenus/cosmos">OpenGenus Foundation</a> 
</p>

---
