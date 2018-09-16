/* Part of Cosmos by OpenGenus Foundation */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Bottom-up O(n^2) approach
int lis(int v[], int n)
{

    int dp[n], ans = 0;
    for (int i = 0; i < n; ++i)
    {
        dp[i] = 1;
        for (int j = 0; j < i; ++j)
            if (v[j] < v[i])
                dp[i] = max(dp[i], 1 + dp[j]);
        ans = max(ans, dp[i]);
    }
    return ans;
}

// Bottom-up O(n*log(n)) approach
int lis2(int v[], int n)
{
    // tail[i] stores the value of the lower possible value
    // of the last element in a increasing sequence of size i
    vector<int> tail;
    for (int i = 0; i < n; ++i)
    {
        vector<int>::iterator it = lower_bound(tail.begin(), tail.end(), v[i]);
        if (it == tail.end())
            tail.push_back(v[i]);
        else
            *it = v[i];
    }
    return tail.size();
}

int main()
{

    int v[9] = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    cout << lis(v, 9) << ", " << lis2(v, 9) << '\n';
    return 0;
}
