/*
 * Part of Cosmos by OpenGenus Foundation
 * @Author: Ayush Garg 
 * @Date: 2017-10-13 23:11:52 
 * @Last Modified by: Ayush Garg
 * @Last Modified time: 2017-10-13 23:23:10
 */

#include <stdio.h>
#include <string.h>

#define MAX 1010

int dp[MAX][MAX]; // used to memoize

// utility function to get max
int max(int a, int b){
    return (a>b)?a:b;
}
/**
 *  Return the longest palindromic subsequence
 *  in s[i...j] in a top-down approach.
 *  Time complexity: O(n^2), n = length of s
 */
int lps(const char s[], int i, int j) {

    // if out of range
    if(i > j) return 0;

    // if already computed
    if(dp[i][j] > -1) return dp[i][j];

    // if first and last characters are equal
    if(s[i] == s[j]) {
        // number of equal characters is 2 if i != j, otherwise 1
        int equalCharacters = 2 - (i == j);
        return dp[i][j] = equalCharacters + lps(s, i+1, j-1);
    }
    // if characters are not equal, discard either s[i] or s[j]
    return dp[i][j] = max( lps(s, i+1, j), lps(s, i, j-1) );
}

// helper function
int longest_palindrome(const char s[]) {

    memset(dp, -1, sizeof dp);
    return lps(s, 0, strlen(s)-1);
}

int main() {
    
    printf("%d\n",longest_palindrome("bbabcbcab")); // 7: babcbab | bacbcab
    printf("%d\n",longest_palindrome("abbaab"));    // 4: abba | baab
    printf("%d\n",longest_palindrome("opengenus")); // 3: ene | ege | ngn | nen
    return 0;
}
