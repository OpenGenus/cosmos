import random
 # Part of Cosmos by OpenGenus Foundation
def bogosort(l):
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


print(bogosort([5, 2, 3, 4, 1]))
