// Part of Cosmos by OpenGenus Foundation

//dynamic programming || Longest repeating subsequence

#include <iostream>
#include <string>
#include <vector>

int longestRepeatingSubsequence(std::string s)
{
    int n = s.size();  // Obtaining the length of the string
    std::vector<std::vector<int>>dp(n + 1, std::vector<int>(n + 1, 0));

    // Implementation is very similar to Longest Common Subsequence problem
    for (int x = 1; x <= n; ++x)
        for (int y = 1; y <= n; ++y)
        {
            if (s[x - 1] == s[y - 1] && x != y)
                dp[x][y] = 1 + dp[x - 1][y - 1];
            else
                dp[x][y] = std::max(dp[x - 1][y], dp[x][y - 1]);
        }

    // Returning the value of the result
    return dp[n][n];
}
