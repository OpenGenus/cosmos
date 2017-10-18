## Binary Indexed Tree

The idea is based on the fact that all positive integers can be represented as sum of powers of 2. For example 19 can be represented as 16 + 2 + 1. Every node of BI Tree stores sum of n elements where n is a power of 2. For example, in the above first diagram for query(), sum of first 12 elements can be obtained by sum of last 4 elements (from 9 to 12) plus sum of 8 elements (from 1 to 8). The number of set bits in binary representation of a number n is O(Logn). Therefore, we traverse at-most O(Logn) nodes in both query() and update() operations. Time complexity of construction is O(nLogn) as it calls update() for all n elements. 

[Credits](http://www.geeksforgeeks.org/binary-indexed-tree-or-fenwick-tree-2/)

## Problem 

#INVCNT - Inversion Count

Let A[0...n - 1] be an array of n distinct positive integers. If i < j and A[i] > A[j] then the pair (i, j) is called an inversion of A. Given n and an array A your task is to find the number of inversions of A.

Input

The first line contains t, the number of testcases followed by a blank space. Each of the t tests start with a number n (n <= 200000). Then n + 1 lines follow. In the ith line a number A[i - 1] is given (A[i - 1] <= 10^7). The (n + 1)th line is a blank space.

Output

For every test output one line giving the number of inversions of A.

Example

Input:
2

3
3
1
2

5
2
3
8
6
1


Output:
2
5

[Link](http://www.spoj.com/problems/INVCNT/)




