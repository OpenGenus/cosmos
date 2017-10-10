# Knuth's Algorithm X

"Algorithm X" is the name Donald Knuth used in his paper "Dancing Links" 
to refer to "the most obvious trial-and-error approach" for 
finding all solutions to the exact cover problem. Technically, 
Algorithm X is a recursive, nondeterministic, 
depth-first, backtracking algorithm. 
While Algorithm X is generally useful as a 
succinct explanation of how the exact cover 
problem may be solved, Knuth's intent in 
presenting it was merely to demonstrate the 
utility of the dancing links technique via an 
efficient implementation he called DLX. ([Source](https://en.wikipedia.org/wiki/Knuth%27s_Algorithm_X))

The algorithm is as follows (for a matrix A containing 0s and 1s):
1. If the matrix A has no columns, the current partial solution is a valid solution; terminate successfully.
2. Otherwise choose a column c (deterministically).
3. Choose a row r such that A<sub>r, c</sub> = 1 (nondeterministically).
4. Include row r in the partial solution.
5. For each column j such that A<sub>r, j</sub> = 1,
    1. for each row i such that A<sub>i, j</sub> = 1,
        1. delete row i from matrix A.
    2. delete column j from matrix A.
6. Repeat this algorithm recursively on the reduced matrix A.