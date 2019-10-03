# Part of Cosmos by OpenGenus Foundation
# Dynamic Programming Python implementation of Matrix Chain Multiplication.
import sys
import numpy as np

# Matrix Ai has dimension p[i-1] x p[i] for i = 1..n
def MatrixChainOrder(p, n):
    m = [[0 for x in range(n)] for x in range(n)]
    for i in range(1, n):
        m[i][i] = 0

    for L in range(2, n):
        for i in range(1, n - L + 1):
            j = i + L - 1
            m[i][j] = sys.maxint
            for k in range(i, j):
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j]
                if q < m[i][j]:
                    m[i][j] = q

    return m[1][n - 1]


arr = [1, 2, 3, 4]
size = len(arr)

print("Minimum number of multiplications is " + str(MatrixChainOrder(arr, size)))


# This Code is contributed by Debajyoti Halder in the repo
