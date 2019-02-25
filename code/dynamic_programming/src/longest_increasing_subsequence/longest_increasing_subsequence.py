"""LIS implementation in Python"""
# Part of Cosmos by OpenGenus Foundation

# Time Complexity: O(nlogn)
def length_of_lis(nums):
    """Return the length of the Longest increasing subsequence"""
    tails = [0] * len(nums)
    size = 0
    for x in nums:
        i, j = 0, size
        while i != j:
            m = int((i + j) / 2)
            if tails[m] < x:
                i = m + 1
            else:
                j = m
        tails[i] = x
        size = max(i + 1, size)
    return size
