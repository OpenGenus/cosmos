/* Part of Cosmos by OpenGenus Foundation */

//Number of insertion required to make a string palindrome using dynamic programming
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int LCS(char *s, string r, int n, int m)
{
    int d[n + 1][m + 1];//d[i][j] contains length of LCS of s[0..i-1] and r[0..j-1]

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                d[i][j] = 0;
            else if (s[i - 1] == r[j - 1])
                d[i][j] = d[i - 1][j - 1] + 1;
            else
                d[i][j] = max(d[i - 1][j], d[i][j - 1]);
        }
    return d[n][m];
}
int MinInsertion(char s[], int n)
{   //Store reverse of given string
    string rev(s, n);
    reverse(rev.begin(), rev.end());

    return n - LCS(s, rev, n, n);
}
int main()
{
    char s[] = "abcd";
    cout << MinInsertion(s, strlen(s));
    return 0;
}
