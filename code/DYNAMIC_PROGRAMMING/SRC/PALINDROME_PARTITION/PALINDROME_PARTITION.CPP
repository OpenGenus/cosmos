/* Part of Cosmos by OpenGenus Foundation */

#include <iostream>
#include <cstring>
#include <string>

#define MAX 1010

using namespace std;

int isPal[MAX][MAX], memo[MAX];

/*
 *  Checks if s[i...j] is palindrome
 *  in a top-down fashion. Result is
 *  stored in isPal matrix.
 *  Time complexity: O(n^2)
 */
int isPalindrome(const string &s, int i, int j)
{

    if (i > j)
        return isPal[i][j] = 0;

    if (isPal[i][j] > -1)
        return isPal[i][j];

    if (j - i <= 1 && s[i] == s[j])
        return isPal[i][j] = 1;

    if (s[i] == s[j])
        return isPal[i][j] = isPalindrome(s, i + 1, j - 1);

    return isPal[i][j] = 0;
}

/*
 *  Compute the minimum number of cuts
 *  necessary to partition the string
 *  s[0...i] in a set of palindromes.
 *  Time complexity: O(n^2)
 */
int minPalPartition(const string &s, int i)
{

    if (isPal[0][i])
        return memo[i] = 0;

    if (memo[i] > -1)
        return memo[i];

    int ans = i + 1;
    for (int j = 0; j < i; ++j)
        if (isPal[j + 1][i] == 1)
            ans = min(ans, 1 + minPalPartition(s, j));

    return memo[i] = ans;
}

// Helper function
int solve(const string  &s)
{

    memset(isPal, -1, sizeof isPal);
    memset(memo, -1, sizeof memo);

    int n = s.length();
    for (int i = 0; i < n; ++i)
        for (int j = i; j < n; ++j)
            isPalindrome(s, i, j);

    return minPalPartition(s, n - 1);
}

int main()
{

    cout << solve("aaabba") << '\n'; // 1:  aa | abba
    cout << solve("ababbbabbababa") << '\n'; // 3: a | babbbab | b | ababa
    return 0;
}
