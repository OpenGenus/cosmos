import random


# Part of Cosmos by OpenGenus Foundation
def bogo_sort(l):
    while not in_order(l):
        random.shuffle(l)
    return l


def in_order(l):
    if not l:
        return True
    last = l[0]
    for x in l[1:]:
        if x < last:
            return False
        last = x
    return True


if __name__ == "__main__":
    print(bogo_sort([5, 2, 3, 4, 1]))
