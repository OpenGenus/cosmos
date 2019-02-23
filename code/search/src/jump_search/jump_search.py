"""
Part of Cosmos by OpenGenus Foundation
"""


import math


def jump_search(arr, x):
    n = len(arr)
    jump = int(math.sqrt(n))
    left, right = 0, 0
    while left < n and arr[left] <= x:
        right = min(n - 1, left + jump)
        if arr[left] <= x and arr[right] >= x:
            break
        left += jump

    if left >= n or arr[left] > x:
        return -1

    right = min(n - 1, right)

    temp = left
    while temp <= right and arr[temp] <= x:
        if arr[temp] == x:
            return temp
        temp += 1

    return -1
