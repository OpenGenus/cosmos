# Python Program to Find nth Magic Number.
# A magic number is defined as a number which can be expressed as a power of 5 or sum of unique powers of 5
# Part of Cosmos by OpenGenus Foundation
# Function to find nth magic numebr
def nthMagicNo(n):
    pow = 1
    ans = 0
    while n:
        pow = pow * 5

        # If last bit of n is set
        if n & 1:
            ans += pow

        # proceed to next bit
        n >>= 1
    return ans


n = int(input())
print(nthMagicNo(n))
