# Part of Cosmos by the Open Genus Foundation


# A Dynamic Programming based Python Program for the Egg Dropping Puzzle
INT_MAX = 32767


def eggDrop(n, k):
    eggFloor = [[0 for x in range(k + 1)] for x in range(n + 1)]
    for i in range(1, n + 1):
        eggFloor[i][1] = 1
        eggFloor[i][0] = 0

    # We always need j trials for one egg and j floors.
    for j in range(1, k + 1):
        eggFloor[1][j] = j

    for i in range(2, n + 1):
        for j in range(2, k + 1):
            eggFloor[i][j] = INT_MAX
            for x in range(1, j + 1):
                res = 1 + max(eggFloor[i - 1][x - 1], eggFloor[i][j - x])
                if res < eggFloor[i][j]:
                    eggFloor[i][j] = res

    return eggFloor[n][k]


n = 2
k = 36
print(
    "Minimum number of trials in worst case with"
    + str(n)
    + "eggs and "
    + str(k)
    + " floors is "
    + str(eggDrop(n, k))
)
