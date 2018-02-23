// Part of Cosmos by OpenGenus Foundation

//dynamic programming || Longest repeating subsequence

#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 1010;

int dp[MAX][MAX];

int longestRepeatingSubsequence(string s)
{
    int n = s.size();  // Obtaining the length of the string

    //Initializing the table
    for (int x = 0; x <= n; x++)
    {
        for (int y = 0; y <= n; y++)
        {
            dp[x][y] = 0;
        }
    }

    for (int x = 1; x <= n; x++)
    {
        for (int y = 1; y <= n; y++)
        {
            if (s[x-1] == s[y-1] && x != y)
            {
                dp[x][y] = 1 + dp[x-1][y-1];
            }
            else
            {
                dp[x][y] = max(dp[x-1][y], dp[x][y-1]);
            }
        }
    }

    // Returning the value of the result
    return dp[n][n];
}

int main()
{
    string str;
    getline(cin, str);
    cout << longestRepeatingSubsequence(str);
}
