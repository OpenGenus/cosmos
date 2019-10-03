# Part of Cosmos by OpenGenus Foundation

# shortest common supersequence using dp
def min(a, b):
    if a > b:
        return b
    else:
        return a


def superSeq(X, Y, m, n):
    dp = []
    for i in range(m + 1):
        l2 = []
        for j in range(n + 1):
            if not (i):
                l2.append(j)

            elif not (j):
                l2.append(i)

            elif X[i - 1] == Y[j - 1]:
                l2.append(1 + dp[i - 1][j - 1])

            else:
                l2.append(1 + min(dp[i - 1][j], l2[j - 1]))
        dp.append(l2)
    return dp[m][n]


X = "FABCDF"
Y = "HBABCDEF"
# longest supersequence can be HBFABCDEF
print("Length of the shortest supersequence = ", superSeq(X, Y, len(X), len(Y)))
