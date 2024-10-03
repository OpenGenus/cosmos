#include <iostream>

// O(n^2) bottom-up dynamic programming solution
long long solveDP(int n)
{
    long long dp[n+1][n+1];

    for (int i = 0; i <= n; ++i)
        dp[i][0] = dp[0][i] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            dp[i][j] = dp[i-1][j] + dp[i][j-1];

    return dp[n][n];
}

// O(n) combinatorial solution
long long solveCombinatorics(int n)
{
    long long ans = 1;
    for (int i = 1; i <= n; ++i)
        ans = ans * (n + i) / i;
    return ans;
}

int main()
{
    std::cout << "Solution using DP: " << solveDP(20) << std::endl;
    std::cout << "Solution using combinatorics: " << solveCombinatorics(20) << std::endl;
    return 0;
}
