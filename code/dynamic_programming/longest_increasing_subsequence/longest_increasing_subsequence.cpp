/* Part of Cosmos by OpenGenus Foundation */

#include <iostream>

using namespace std;

// Bottom-up O(n^2) approach
int lis(int v[], int n) {

    int dp[n], ans = 0;
    for(int i = 0; i < n; ++i) {
        dp[i] = 1;
        for(int j = 0; j < i; ++j)
            if(v[j] < v[i])
                dp[i] = max(dp[i], 1 + dp[j]);
        ans = max(ans, dp[i]);
    }
    return ans;
}

int main() {

    int v[9] = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    cout << lis(v, 9) << '\n';
    return 0;
}
