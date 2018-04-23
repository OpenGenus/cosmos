/* Part of Cosmos by OpenGenus Foundation */

#include <iostream>
#include <string>

using namespace std;

int longestPalSubstr(string str)
{
    int n = str.size();

    bool ispal[n][n];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            ispal[i][j] = false;

    // All substrings of length 1 are palindromes
    int maxLength = 1;
    for (int i = 0; i < n; ++i)
        ispal[i][i] = true;

    // check for sub-string of length 2.
    for (int i = 0; i < n - 1; ++i)
        if (str[i] == str[i + 1])
        {
            ispal[i][i + 1] = true;
            maxLength = 2;
        }

    // Check for lengths greater than 2. k is length
    // of substring
    for (int k = 3; k <= n; ++k)
        for (int i = 0; i < n - k + 1; ++i)
        {
            // Get the ending index of substring from
            // starting index i and length k
            int j = i + k - 1;
            if (ispal[i + 1][j - 1] && str[i] == str[j])
            {
                ispal[i][j] = true;

                if (k > maxLength)
                    maxLength = k;
            }
        }
    return maxLength;
}

int main()
{
    string str = "hacktoberfestsefrisawesome";
    cout << "Length of longest palindromic substring is " << longestPalSubstr(str);
    return 0;
}
