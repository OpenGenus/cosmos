# Part of Cosmos by OpenGenus Foundation


def catalan(n):

    if n <= 1:
        return 1
    res = 0
    for i in range(n):
        res += catalan(i) * catalan(n - i - 1)
    return res


for i in range(10):
    print(catalan(i), emd=" ")
