# MAgic Square generation for odd numbered squares
import numpy as np

N = input("Enter the dimension. Note that it should be odd : ")
magic_square = np.zeros((N, N), dtype=int)

n = 1
i, j = 0, N // 2

while n <= N ** 2:
    magic_square[i, j] = n
    n += 1
    new_i, new_j = (i - 1) % N, (j + 1) % N
    if magic_square[new_i, new_j]:
        i += 1
    else:
        i, j = new_i, new_j

print(magic_square)
