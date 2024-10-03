// Part of Cosmos by OpenGenus Foundation
#include <iostream>
#include <cstring>

using namespace std;

// Returns the maximum value with knapsack of
// W capacity
int unboundedKnapsack(int W, int n, int val[], int wt[])
{
    // dp[i] is going to store maximum value
    // with knapsack capacity i.
    int dp[W + 1];
    memset(dp, 0, sizeof dp);

    int ans = 0;

    // Fill dp[] recursively
    for (int i = 0; i <= W; i++)
        for (int j = 0; j < n; j++)
            if (wt[j] <= i)
                dp[i] = max(dp[i], dp[i - wt[j]] + val[j]);

    return dp[W];
}
