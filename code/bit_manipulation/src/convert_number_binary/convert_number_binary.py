# part of Cosmos by OpenGenus Foundation

import math


def intToBinary(i):
    if i == 0:
        return "0"
    s = ""
    while i:
        if i % 2 == 1:
            s = "1" + s
        else:
            s = "0" + s
        i /= 2
    return s


# sample test
n = 741
print(intToBinary(n))
