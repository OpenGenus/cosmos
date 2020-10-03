"""
Part of Cosmos by OpenGenus Foundation
The Lonely Integer Problem
Given an array in which all the no. are present twice except one, find that lonely integer.
"""


def LonelyInteger(a):
    lonely = 0
    # finds the xor sum of the array.
    for i in a:
        lonely ^= i
    return lonely


a = [2, 3, 4, 5, 3, 2, 4]
print(LonelyInteger(a))
