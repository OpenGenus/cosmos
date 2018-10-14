# Part of Cosmos by OpenGenus Foundation
# By: Shamama Zehra (https://github.com/shamamaz)

# How many numbers x are there in the range a to b
# where the digit d occurs exactly k times in x?
# dp[pos][count][f] = Number of valid numbers <= b from this state
# pos = current position from left side (zero based)
# count = number of times we have placed the digit d so far
# f = the prefix of the number we are building is smaller than prefix in b [0 = no, 1 = yes]
import numpy as np

def digit_dp(num, pos, count, f):
    global dp
    global k
    global d

    if (count > k):
        return 0

    if (pos == len(str(num))):
        if (count == k):
            return 1
        return 0

    if (dp[pos][count][f] != -1):
        return dp[pos][count][f]

    result = 0

    if (f == 0):
        string_num = str(num)
        limit = int(string_num[pos])
    else:
        limit = 9

    # Try to place all the valid digits such that the number doesn't exceed b
    for dgt in range(0, limit+1):
        fNext = f
        countNext = count

        # The number is getting smaller at this position
        if (f == 0 and dgt < limit):
            fNext = 1
        if (dgt == d):
            countNext += 1
        if (countNext <= k):
            result += digit_dp(num, pos + 1, countNext, fNext)

    dp[pos][count][f] = result
    return dp[pos][count][f]

def solve(numb):
    global dp
    dp = np.zeros((25, 25, 2), dtype=int)
    dp.fill(-1)
    return digit_dp(numb, 0, 0, 0)

def check(numb):
    count = 0
    numb = str(numb)
    for i in range (0, len(numb)):
        if (int(numb[i]) == d):
            count += 1

    if (count == k):
        return 1
    return 0

if __name__ == "__main__":
    a = 100
    b = 100000000
    d = 3
    k = 5
    ans = solve(b) - solve(a) + check(a)
    print(ans)
