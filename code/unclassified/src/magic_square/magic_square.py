# MAgic Square generation for odd numbered squares
import numpy as np

print "Enter the dimension. Note that it should be odd : "
N = input()
magic_square = np.zeros((N, N), dtype=int)

n = 1
i, j = 0, N // 2

while n <= N**2:
    magic_square[i, j] = n
    n += 1
    newi, newj = (i - 1) % N, (j + 1) % N
    if magic_square[newi, newj]:
        i += 1
    else:
        i, j = newi, newj

print(magic_square)
