# Part of Cosmos by OpenGenus Foundation

import copy

# returns the longest increasing sequence
def longest_increasing_seq(numbers):
    # longest increasing subsequence
    lis = []
    # base case
    lis.append([numbers[0]])

    # start filling using dp - forwards

    for i in range(1, len(numbers)):
        lis.append([])
        for j in range(i):
            if numbers[j] < numbers[i] and len(lis[j]) > len(lis[i]):
                lis[i] = copy.copy(lis[j])
        lis[i].append(numbers[i])
    return lis


# returns longest decreasing sequence
def longest_decreasing_seq(numbers):
    # longest decreasing subsequence
    lds = []

    # to make an n sized list
    lds = [[] for _ in range(len(numbers))]

    # base case
    lds[-1].append(numbers[-1])

    # start filling using dp backwards
    for i in range(len(numbers) - 2, -1, -1):
        for j in range(len(numbers) - 1, i, -1):
            if numbers[j] < numbers[i] and len(lds[j]) > len(lds[i]):
                lds[i] = copy.copy(lds[j])

        lds[i].append(numbers[i])
    return lds


def longest_bitonic_seq(numbers):
    lis = longest_increasing_seq(numbers)
    lds = longest_decreasing_seq(numbers)

    # now let's find the maxmimum
    maxi = len(lis[0] + lds[0])
    output = lis[0][:-1] + lds[0][::-1]

    for i in range(1, len(numbers)):
        if len(lis[i] + lds[i]) > maxi:
            maxi = len(lis[i] + lds[i])
            output = lis[i][:-1] + lds[i][::-1]

    return output


# you can use any input format
# format the input such that the array of numbers looks like below
numbers = [1, 11, 2, 10, 4, 5, 2, 1]

output = longest_bitonic_seq(numbers)

print(output)
