# Part of Cosmos by OpenGenus Foundation

# Split array in half, sort the 2 halves and merge them.
# When merging we pick the smallest element in the array.
# The "edge" case is when one of the arrays has no elements in it
# To avoid checking and breaking the look, finding which array has elements and then
# Starting another loop, we simply alias the arrays. This abstracts the issue without
# Creating a mess of code. When we alias, we decide with Xor which array to pick,
# Since we cover 0 ^ 0 case in the beginning of the loop,
# while bool(a) or bool(b) makes 0^0 is impossible to happen, Xor has 3 cases, 1 ^ 0, 0 ^ 1, 1^1 to evaluate.
# Since the 2 first cases are the edge we go inside the loop and alias the array that has elements in it.
# If it's 1^1 we simply pick the array with the smallest element.

from random import randint


def merge_sort(array):

    if len(array) == 1:
        return array

    left = merge_sort(array[: (len(array) // 2)])
    right = merge_sort(array[(len(array) // 2) :])
    out = []

    while bool(left) or bool(right):
        if bool(left) ^ bool(right):
            alias = left if left else right
        else:
            alias = left if left[0] < right[0] else right

        out.append(alias[0])
        alias.remove(alias[0])

    return out


randomized: list = [randint(0, 1000) for x in range(10000)]
clone = [x for x in randomized]
assert sorted(clone) == merge_sort(randomized)
