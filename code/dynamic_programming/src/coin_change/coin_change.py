#################
##  dynamic programming | coin change | Python
##  Part of Cosmos by OpenGenus Foundation
#################


def coin_change(coins, amount):

    # init the dp table
    tab = [0 for i in range(amount + 1)]
    tab[0] = 1  # base case

    for j in range(len(coins)):
        for i in range(1, amount + 1):
            if coins[j] <= i:
                # if coins[j] < i then add no. of ways -
                # - to form the amount by using coins[j]
                tab[i] += tab[i - coins[j]]

                # final result at tab[amount]
    return tab[amount]


def main():

    coins = [1, 2, 3, 8]  # coin denominations
    amount = 3  # amount of money

    print("No. of ways to change - {}".format(coin_change(coins, amount)))

    return


if __name__ == "__main__":
    main()
