# Part of Cosmos by OpenGenus Foundation

# Swaps two given numbers making use of xor

# Works for both python 2 and python 3


def xorswap(n, m):
    n = m ^ n
    m = n ^ m
    n = m ^ n
    return n, m


n = 10
m = 15
print("Earlier A was equal to ", n, " and B was equal to ", m)
n, m = xorswap(n, m)
print("Now A is equal to ", n, " and B is equal to ", m)
