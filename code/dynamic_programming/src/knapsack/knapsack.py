#######################################
# Part of Cosmos by OpenGenus Foundation
#######################################


def knapsack(weights, values, W):

    n = len(weights)
    # create 2d DP table with zeros to store intermediate values
    tab = [[0 for i in range(W + 1)] for j in range(n + 1)]

    # no further init required as enitre table is already inited

    for i in range(1, n + 1):
        # check all possible maxWeight values from 1 to W
        for j in range(1, W + 1):
            if weights[i - 1] <= j:
                # if current item weighs < j then we have two options,
                # take max of them
                tab[i][j] = max(
                    tab[i - 1][j], values[i - 1] + tab[i - 1][j - weights[i - 1]]
                )
            else:
                tab[i][j] = tab[i - 1][j]

    return tab[n][W]


def main():

    values = [12, 1000, 30, 10, 1000]  # values of each item
    weights = [19, 120, 20, 1, 120]  # weights of each item in same order
    W = 40

    # Call knapsack routine to compute value
    print("Result - {}".format(knapsack(weights, values, W)))

    return


if __name__ == "__main__":
    main()
