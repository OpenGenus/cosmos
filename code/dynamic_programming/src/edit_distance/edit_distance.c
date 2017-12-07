/*
 * dynamic programming | edit distance | C
 * Part of Cosmos by OpenGenus Foundation
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX = 1010;

int memo[MAX][MAX]; /* used for memoization */

int
mn(int x, int y)
{
    return x < y ? x : y;
}

/* Utility function to find minimum of three numbers */
int
min(int x, int y, int z)
{
    return mn(x, mn(y, z));
}

int
editDist(char str1[], char str2[], int m, int n)
{
    /*
     * If first string is empty, the only option is to
     * insert all characters of second string into first
     */
    if (m == 0) return n;

    /*
     * If second string is empty, the only option is to
     * remove all characters of first string
     */
    if (n == 0) return m;

    /* If this state has already been computed, get its value */
    if (memo[m][n] > -1) return memo[m][n];

    /*
     * If last characters of two strings are same, nothing
     * much to do. Ignore last characters and get count for
     * remaining strings.
     */
    if (str1[m-1] == str2[n-1])
        return memo[m][n] = editDist(str1, str2, m-1, n-1);

    /*
     * If last characters are not same, consider all three
     * operations on last character of first string, recursively
     * compute minimum cost for all three operations and take
     * minimum of three values.
     */
    return memo[m][n] = 1 + min ( editDist(str1, str2, m, n-1),  /* Insert  */
                                  editDist(str1, str2, m-1, n),  /* Remove  */
                                  editDist(str1, str2, m-1, n-1) /* Replace */
    );
}

/* Driver program */
int
main()
{
    char str1[] = "sunday";
    char str2[] = "saturday";

    int str1Length = sizeof(str1) / sizeof(str1[0]);
    int str2Length = sizeof(str2) / sizeof(str2[0]);
    memset(memo, -1 ,sizeof memo);
    int minimum = editDist(str1, str2, str1Length, str2Length);
    printf("%d\n", minimum);

    return 0;
}
