#include <bits/stdc++.h>
using namespace std;

int mcm_memo(vector<int> &arr, int si, int ei, vector<vector<int>> &dp)
{
    if (ei - si == 1)
    {
        return dp[si][ei] = 0;
    }

    if (dp[si][ei] != 0)
    {
        return dp[si][ei];
    }

    int minRes = (int)1e9;
    for (int i = si + 1; i < ei; i++)
    {
        int leftRes = mcm_memo(arr, si, i, dp);
        int rightRes = mcm_memo(arr, i, ei, dp);

        minRes = min(minRes, leftRes + arr[si] * arr[i] * arr[ei] + rightRes);
    }
    dp[si][ei] = minRes;
    return minRes;
}

int matrixMultiplication(vector<int> &arr, int n)
{
    vector<vector<int>> dp(n, vector<int>(n , 0));
    return mcm_memo(arr, 0, n-1, dp);
}
