# Part of Cosmos by OpenGenus Foundation

# The Hamming distance between two integers is the number of positions
# at which the corresponding bits are different.


def hammingDistance(x, y):
    res = x ^ y
    ans = 0
    while res:
        ans += 1
        res = res & (res - 1)
    return ans


print(hammingDistance(2, 1))
