/* Part of Cosmos by OpenGenus Foundation */

#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 1010;

int memo[MAX][MAX]; // used to store subproblems answers

/**
 *  Return the longest palindromic subsequence
 *  in s[i...j] in a top-down approach.
 *  Time complexity: O(n^2), n = length of s
 */
int lps(const string& s, int i, int j)
{

    // if out of range
    if (i > j)
        return 0;

    // if already computed
    if (memo[i][j] > -1)
        return memo[i][j];

    // if first and last characters are equal
    if (s[i] == s[j])
    {
        // number of equal characters is 2 if i != j, otherwise 1
        int equalCharacters = 2 - (i == j);
        return memo[i][j] = equalCharacters + lps(s, i + 1, j - 1);
    }
    // if characters are not equal, discard either s[i] or s[j]
    return memo[i][j] = max( lps(s, i + 1, j), lps(s, i, j - 1) );
}

// helper function
int longest_palindrome(const string& s)
{

    memset(memo, -1, sizeof memo);
    return lps(s, 0, s.length() - 1);
}

int main()
{

    cout << longest_palindrome("bbabcbcab") << '\n'; // 7: babcbab | bacbcab
    cout << longest_palindrome("abbaab") << '\n';    // 4: abba | baab
    cout << longest_palindrome("opengenus") << '\n'; // 3: ene | ege | ngn | nen

    return 0;
}
