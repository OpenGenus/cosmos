/* Part of Cosmos by OpenGenus Foundation */

#include <iostream>
#include <string>
#include <cstring>

#define MAX 1010

using namespace std;

int memo[MAX][MAX];

/*  Compute the longest common subsequence
 *  of strings a[0...n] and b[0...m]
 *  Time complexity: O(n*m)
 */
int lcs(const string& a, const string& b, int n, int m)
{

    if (n < 0 || m < 0)
        return 0;

    if (memo[n][m] > -1)
        return memo[n][m];

    if (a[n] == b[m])
        return memo[n][m] = 1 + lcs(a, b, n - 1, m - 1);

    return memo[n][m] = max( lcs(a, b, n - 1, m), lcs(a, b, n, m - 1) );
}

// Helper method
int get_lcs(const string& a, const string& b)
{

    memset(memo, -1, sizeof memo);
    return lcs(a, b, a.length() - 1, b.length() - 1);
}

int main()
{

    cout << get_lcs("cosmos", "opengenus") << '\n';
    cout << get_lcs("ABCDGH", "AEDFHR") << '\n';

    return 0;
}
