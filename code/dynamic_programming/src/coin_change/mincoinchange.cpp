// dynamic programming | coin change | C++
// Part of Cosmos by OpenGenus Foundation

// A C++ program to find the minimum number of coins required from the list of given coins to make a given value
// Given a value V, if we want to make change for V cents, and we have infinite supply of each of C = { C1, C2, .. , Cm}
// valued coins, what is the minimum number of coins to make the change?
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t; // no. of test cases
    while (t--)
    {
        int v, n;
        cin >> v >> n;  // v is value to made and n is the number of given coins
        int c[n + 1];
        for (int i = 0; i < n; i++)
            cin >> c[i];                // c[i] holds denomination or value of different coins
        long long int dp[v + 1];
        long long int m = 100000000;
        dp[0] = 0;
        for (int i = 1; i <= v; i++)
            dp[i] = m;
        for (int i = 0; i <= n - 1; i++)
            for (int j = 1; j <= v; j++)
                if (c[i] <= j)
                    if (1 + dp[j - c[i]] < dp[j])
                        dp[j] = 1 + dp[j - c[i]];

        if (dp[v] == m)
            cout << "-1" << endl;     // prints -1 if it is not possible to make given amount v
        else
            cout << dp[v] << endl; // dp[v] gives the min coins required to make amount v
    }
}
