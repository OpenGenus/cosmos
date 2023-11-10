# Part of Cosmos by Open Genus Foundation
# Code contributed by Shamama Zehra

# A dynamic programming solution for no Conseuctive Ones in Binary String problem


def noConsecOnes(n):
    a = [0 for x in range(n)]  # number of strings ending with 0
    b = [0 for x in range(n)]  # number of strings ending with 1

    a[0], b[0] = 1, 1

    for i in range(1, n):
        # number of strings ending with 0 is the previous ending with 0
        # plus the previous ending with 1 with a 0 added
        a[i] = a[i - 1] + b[i - 1]

        # number of strings ending with 1 is the previous ones ending with
        # 0 plus a 0
        b[i] = a[i - 1]

    return a[n - 1] + b[n - 1]


# Driver program to test above function
print(
    "Number of binary strings of length 5 with no consecutive ones is "
    + str(noConsecOnes(5))
)
