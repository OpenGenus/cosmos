# Part of Cosmos by OpenGenus Foundation
def russian_peasant(a, b):
    res = 0
    while b > 0:
        if b % 2 == 1:
            res += a
        a *= 2
        b //= 2
    return res


print(russian_peasant(18, 24))
print(russian_peasant(20, 12))
