# Part of Cosmos by OpenGenus Foundation

from math import sqrt


def __mean(array):
    return float(sum(array)) / max(len(array), 1)


def __variance(array):
    mean = __mean(array)

    return __mean(map(lambda x: (x - mean) ** 2, array))


def std(array):
    return sqrt(variance(array))


print(std([]))  # 0.0
print(std([12, 65, 91, 52, 18, 72]))  # 28.41...
