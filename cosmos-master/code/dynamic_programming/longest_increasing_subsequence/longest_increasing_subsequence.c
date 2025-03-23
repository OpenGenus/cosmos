/* Part of Cosmos by OpenGenus Foundation */
// LIS  implementation in C
#include<stdio.h>

// Max function 
int max(int a,int b)
{
    if( a > b)
        return a;
    return b;
}

// O(n^2) approach
int lis(int arr[], int n)
{
    int dp[n], ans = 0 , i = 0, j = 0;
    for(i = 0; i < n; ++i)
    {
        dp[i] = 1;
        for(j = 0; j < i; j++)
            if(arr[j] < arr[i])
                dp[i] = max(dp[i], 1 + dp[j]);
        ans = max(ans, dp[i]);
    }
    return ans;
}

int main() {

    int arr[8] = {10, 22, 9, 33, 21, 50, 41, 60};
    printf("LIS is : %d\n",lis(arr, 8));
    return 0;
}