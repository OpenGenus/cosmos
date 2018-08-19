# Matrix Total Paths

## Description

Count all the possible paths from top left to bottom right of an `m x n` matrix with the constraints that from each cell you can either move only to right or down. The cell is represented by Zeros and Ones, 0 means that there is path possible and 1 means it is an obstacle and there is no path possible through it.

## Example

Given `3 x 3` Matrix,
```
0 1 0
0 0 0
1 0 0
```
The number of possible paths from top left to bottom right will be `2`.

## Solution

We will have to look for the subproblems to apply the dynamic programming approach. Can this problem be divided into subproblems so that each of those problems can be solved easily? The answer is, yes. You can find the value of number of paths to reach a particular cell by using the number of paths to reach the upper and left cell.

1. **Optimal Substructure**
    - there are two possibilities for every cell X, either X is a valid path or it's a obstacle. If X is a valid path, then the value of total paths to reach X is the sum of total paths to reach the upper and left cell. If X is an obstacle, then the we can't reach that cell ever so the number of paths to reach that cell would be zero.
    - let PATHS(X) indicate the number of paths to reach cell X.
      ```markdown
      PATHS(X) = PATHS(X.UP) + PATHS(X.LEFT) if X is zero
               = 0                           if X is one
      ```
      here X.UP indicates upper cell of cell X and X.LEFT indicates cell to the left of X.

2. **Overlapping Subproblems**
    - While solving the subproblems, we encounter that we have to find the solutions of the same subproblems again and again. When we have to calculate total number of paths to reach a particular cell, we would have to calculate the number of paths to reach to the cell left of it and the upper cell. We will need to calculate the number of paths to reach a cell multiple times i.e. when we are calculating the number of paths for the right cell and bottom cell of it. This is shows that overlapping subproblems exist.

Since Optimal Substructure and Overlapping Subproblems exist, we can use Dynamic Programming to derive an efficient solution.

Using memoization or tabulation to store the results of the subproblems, the time complexity of above approach is `O(mn)`.

---

<p align="center">
A massive collaborative effort by <a href="https://github.com/opengenus/cosmos">OpenGenus Foundation</a>
</p>

---
