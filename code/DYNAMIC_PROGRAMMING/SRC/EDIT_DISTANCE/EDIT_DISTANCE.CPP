// dynamic programming | edit distance | C++
// Part of Cosmos by OpenGenus Foundation

#include <iostream>

#define MAX 1010

using namespace std;

int memo[MAX][MAX];

/*
 *  A recursive approach to the edit distance problem.
 *  Returns the edit distance between a[0...i] and b[0...j]
 *  Time complexity: O(n*m)
 */
int editDistance(string& a, string& b, int i, int j)
{

    if (i < 0)
        return j + 1;
    if (j < 0)
        return i + 1;

    if (memo[i][j] > -1)
        return memo[i][j];

    if (a[i] == b[j])
        return memo[i][j] = editDistance(a, b, i - 1, j - 1);

    int c1 = editDistance(a, b, i - 1, j - 1); // replacing
    int c2 = editDistance(a, b, i - 1, j);   // removing
    int c3 = editDistance(a, b, i, j - 1);   // inserting

    return memo[i][j] = 1 + min(c1, min(c2, c3));
}

int main()
{

    string a = "opengenus", b = "cosmos";

    for (size_t i = 0; i < MAX; ++i)
        for (size_t j = 0; j < MAX; ++j)
            memo[i][j] = -1;
    // memset(memo, -1, sizeof memo);
    cout << editDistance(a, b, a.length() - 1, b.length() - 1) << '\n';
}
