# Part of Cosmos by OpenGenus Foundation


def can_get_sum(items, target):
    dp = (target + 1) * [False]
    reachable = (target + 1) * [0]

    reachable[0] = 0
    dp[0] = True

    reachable[1] = 1

    i = 0
    q = 1

    while i < len(items) and not dp[target]:
        aux = q

        for j in range(0, aux):
            x = reachable[j] + items[i]
            if x <= target and not dp[x]:
                reachable[q] = x
                q += 1
                dp[x] = True
        i += 1

    return dp[target]


print(can_get_sum([1, 2, 3], 6))
print(can_get_sum([1, 2, 3], 7))
