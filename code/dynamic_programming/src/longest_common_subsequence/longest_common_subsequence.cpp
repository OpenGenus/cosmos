/* Part of Cosmos by OpenGenus Foundation */

#include <bits/stdc++.h>
using namespace std;

/*  Compute the longest common subsequence
 *  of strings a[0...n] and b[0...m]
 *  Time complexity: O(n*m)
 *  @author md-shamim-ahmad
 */
int longestCommonSubsequence(string text1, string text2) {
    vector<vector<int> > dp(text1.size() + 1, vector<int>(text2.size() + 1));
    for (int i = 0; i < text1.size(); i++) {
        for (int j = 0; j < text2.size(); j++) {
            if (text1[i] == text2[j]) {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            } else {
                dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }
    return dp[dp.size() - 1][dp[0].size() - 1];
}

int main() {
    
    cout << longestCommonSubsequence("cosmos", "opengenus") << '\n';
    cout << longestCommonSubsequence("ABCDGH", "AEDFHR") << '\n';

    return 0;
}
