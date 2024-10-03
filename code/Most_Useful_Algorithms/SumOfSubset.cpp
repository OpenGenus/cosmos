#include <iostream>
#include <vector>

using namespace std;


bool isSubsetSum(const vector<int>& nums, int targetSum) {
    int n = nums.size();


    vector<vector<bool>> dp(n + 1, vector<bool>(targetSum + 1, false));

    
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= targetSum; j++) {
            if (j < nums[i - 1]) {
                
                dp[i][j] = dp[i - 1][j];
            } else {
                
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
            }
        }
    }

    
    return dp[n][targetSum];
}

int main() {
    vector<int> nums = {3, 34, 4, 12, 5, 2};
    int targetSum = 9;

    if (isSubsetSum(nums, targetSum)) {
        cout << "There is a subset with the sum " << targetSum << endl;
    } else {
        cout << "No subset with the sum " << targetSum << " exists." << endl;
    }

    return 0;
}
