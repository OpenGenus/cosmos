/* Part of Cosmos by OpenGenus Foundation */

#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 1010;

int memo[MAX][MAX]; // used for memoization

// Function to find length of shortest common supersequence
// between sequences X[0..m-1] and Y[0..n-1]
int SCSLength(string& X, string& Y, int m, int n)
{
    // if we have reached the end of either sequence, return
    // length of other sequence
    if (m == 0 || n == 0)
        return n + m;

    // if we have already computed this state
    if (memo[m - 1][n - 1] > -1)
        return memo[m - 1][n - 1];

    // if last character of X and Y matches
    if (X[m - 1] == Y[n - 1])
        return memo[m - 1][n - 1] = SCSLength(X, Y, m - 1, n - 1) + 1;
    else
        // else if last character of X and Y don't match
        return memo[m - 1][n - 1] = 1 + min(SCSLength(X, Y, m, n - 1),
                                            SCSLength(X, Y, m - 1, n));
}

// helper function
int findSCSLength(string& X, string& Y)
{
    memset(memo, -1, sizeof memo);
    return SCSLength(X, Y, X.length(), Y.length());
}

// main function
int main()
{
    string X = "ABCBDAB", Y = "BDCABA";

    cout << "The length of shortest common supersequence is "
         << findSCSLength(X, Y) << '\n';

    return 0;
}
