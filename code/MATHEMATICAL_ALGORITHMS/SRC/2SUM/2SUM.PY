# Part of Cosmos by OpenGenus Foundation
# Given an array of integers, return the indices of the two numbers such that they add up to a specific target.


def two_sum(array, target):
    indices = {}
    for i, n in enumerate(array):
        if target - n in indices:
            return (indices[target - n], i)
        indices[n] = i
    return (None, None)


print(two_sum([3, 5, 7, 0, -3, -2, -3], 4))
print(two_sum([3, 5, 0, -3, -2, -3], 4))
