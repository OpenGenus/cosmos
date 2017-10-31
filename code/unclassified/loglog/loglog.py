# Part of Cosmos by OpenGenus Foundation
#
# Estimate number of distinct elements in a large sequence
#
# For more details about log log algorithm, please refer to
# http://algo.inria.fr/flajolet/Publications/DuFl03-LNCS.pdf


import random


hash_length = 32
k = 8  # number of bits use to determine bucket index
m = 2 ** k  # number of buckets


def ffs(x):
    """Find the rank of least significiant set bit
    """
    if x == 0:
        return hash_length - k

    return (x & -x).bit_length() - 1


def alpha(m):
    return 0.7213 / (1 + 1.079 / m)


def estimate_unique(nums):
    """Estimate number of unique elements given a stream of element's hash
    """

    buckets = [0 for i in range(m)]

    for value in nums:
        index = value & (m - 1)
        value = value >> k

        buckets[index] = max(buckets[index], ffs(value))

    return int(alpha(m) * m * 2 ** (sum(buckets) / m))


def count_unique(nums):
    return len(set(nums))


# Example

if __name__ == '__main__':
    # Generate sample hash sequence
    nums = [random.randint(1, 2 ** hash_length) for x in range(2 ** 20)]

    print("Estimate:", estimate_unique(nums))
    print("Expected:", count_unique(nums))
