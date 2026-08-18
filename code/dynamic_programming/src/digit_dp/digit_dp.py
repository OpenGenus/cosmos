# Part of Cosmos by OpenGenus Foundation

"""
How many numbers x are there in the range a to b
where the digit d occurs exactly k times in x?
"""

d = 3
k = 5


def digit_dp(num, pos, count, smaller, dp):
    # If digit d occurs more than k times
    if count > k:
        return 0

    # All digits have been processed
    if pos == len(num):
        return 1 if count == k else 0

    # Return already computed result
    if dp[pos][count][smaller] != -1:
        return dp[pos][count][smaller]

    # Decide the maximum digit we can place
    if smaller == 0:
        limit = int(num[pos])
    else:
        limit = 9

    result = 0

    # Try all possible digits
    for digit in range(limit + 1):
        next_smaller = smaller
        next_count = count

        # The number becomes smaller than the upper bound
        if smaller == 0 and digit < limit:
            next_smaller = 1

        # Count occurrences of digit d
        if digit == d:
            next_count += 1

        if next_count <= k:
            result += digit_dp(num, pos + 1, next_count, next_smaller, dp)

    dp[pos][count][smaller] = result
    return result


def solve(num):
    dp = [[[-1 for _ in range(2)] for _ in range(25)] for _ in range(25)]
    return digit_dp(num, 0, 0, 0, dp)


def check(num):
    count = 0

    for digit in num:
        if int(digit) == d:
            count += 1

    return 1 if count == k else 0


if __name__ == "__main__":
    a = "100"
    b = "100000000"

    ans = solve(b) - solve(a) + check(a)

    print(ans)
