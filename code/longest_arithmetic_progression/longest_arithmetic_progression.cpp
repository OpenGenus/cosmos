#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int longest_arithmetic_progression(const vector<int> &A)
{
    int n = A.size();
    if (n <= 2)
        return n;
    unordered_map<int, int> mp;
    vector<vector<int>> dp(1001, vector<int>(1001));
    int res = 2;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            dp[i][j] = 2;
            int need = 2 * A[i] - A[j];
            if (mp.find(need) != mp.end())
            {
                dp[i][j] = max(dp[i][j], 1 + dp[mp[need]][i]);
                res = max(res, dp[i][j]);
            }
        }
        mp[A[i]] = i;
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << longest_arithmetic_progression(a) << "\n";
    return 0;
}
