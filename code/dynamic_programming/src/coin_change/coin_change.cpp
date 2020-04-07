// dynamic programming | coin change | C++
// Part of Cosmos by OpenGenus Foundation

#include <iostream>
#include <vector>

const int MAX = 100;

int coinWays(int amt, std::vector<int>& coins)
{
    // init the dp table
    std::vector<int> dp(MAX, 0);
    int n = coins.size();
    dp[0] = 1; // base case
    for (int j = 0; j < n; ++j)
        for (int i = 1; i <= amt; ++i)
            if (i - coins[j] >= 0)
                // if coins[j] < i then add no. of ways -
                // - to form the amount by using coins[j]
                dp[i] += dp[i - coins[j]];

    //final result at dp[amt]
    return dp[amt];
}
int main()
{
    std::vector<int> coins = {1, 2, 3}; // coin denominations
    int amount = 4;  // amount
    std::cout << coinWays(amount, coins) << "\n";
    return 0;
}
