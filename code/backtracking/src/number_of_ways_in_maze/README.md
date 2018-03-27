# Number Of Ways in Maze

The problem aims to count of paths to reach row number m and column number n in the matrix starting from 0,0

## Explanation

Given a maze of dimensions mxn we need to find the number of distinct ways possible from which we can reach the cell (m,n) from (0,0).
We can only move in any of the 4 directions.

Example:

000x
0x00

Here x signifies the bloacked cells and 0 the opposite. Hence number of ways of going from 0,0 to 1,3 is 1 ((0,0),(0,1),(0,2),(1,2),(1,3)). Hence the answer is 1.

## Algorithm

From a starting cell, we keep on going in all the four directions possible where the path is not bloacked. If we reach our desired block, we increment our counter with 1. Else, if all the paths are blocked we backtrack and check in other directions.

---
<p align="center">
	A massive collaborative effort by <a href="https://github.com/OpenGenus/cosmos">OpenGenus Foundation</a> 
</p>

---
