/*
Problem Statement : 
Find the length of LCS present in given two sequences.
LCS -> Longest Common Subsequence
*/

#include <stdio.h> 
#include <string.h>
#define MAX 1000

int max(int a, int b) 
{
    return (a > b) ? a : b; 
}

int lcs(char *x, char *y, int x_len, int y_len) 
{
    int dp[x_len + 1][y_len + 1]; 

    for (int i = 0; i <= x_len; ++i) 
    { 
        for (int j = 0; j <= y_len; ++j) 
        { 
            if (i == 0 || j == 0) 
                dp[i][j] = 0; 
            else if (x[i - 1] == y[j - 1]) 
                dp[i][j] = dp[i - 1][j - 1] + 1;     
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        } 
    } 

    return dp[x_len][y_len]; 
}

int main() 
{
    char a[MAX], b[MAX];
    printf("Enter two strings : ", a, b);
    scanf("%s %s", a, b);

    int a_len = strlen(a);
    int b_len = strlen(b);
    printf("\nLength of LCS : %d", lcs(a, b, a_len, b_len)); 

    return 0; 
}

/*
Enter two strings : AGGTAB GXTXAYB

Length of LCS : 4
*/
