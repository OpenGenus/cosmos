# dynamic programming | binomial coefficient | Python
# Part of Cosmos by OpenGenus Foundation
import numpy as np

# implementation using dynamic programming
def binomialCoefficient(n, k, C=None):
    if k < 0 or n < 0:
        raise ValueError("n,k must not be less than 0")

    if k > n:
        return 0

    k = min(k, n - k)

    if C is None:
        C = np.zeros((n + 1, k + 1))

    if k == 0:
        C[n, k] = 1

    if C[n, k] == 0:
        C[n, k] = binomialCoefficient(n - 1, k, C=C) + binomialCoefficient(
            n - 1, k - 1, C=C
        )

    return C[n, k]


# test
# print(binomialCoefficient(10,3))
# print(binomialCoefficient(10,6))
# print(binomialCoefficient(10,4))
# print(binomialCoefficient(1,1))
# print(binomialCoefficient(0,0))
# print(binomialCoefficient(0,1))
# print(binomialCoefficient(-1,1))
