/*#define CATCH_CONFIG_MAIN
#include "catch.hpp"

// this function should be stored in code folder
bool isEqual(int a, int b) {
   return a == b;
}

TEST_CASE("just sample", "[sample]") {
    REQUIRE(isEqual(1, 0) == false);
}*/
class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        const int n = scores.size();
        vector<int> dp(n, 0);
        // first: age
        // second: scores
        vector<pair<int, int>> arr(n, {0, 0}); 
        for(int i = 0; i < n; ++i){
            arr[i].first = ages[i];
            arr[i].second = scores[i];
        }
        sort(arr.begin(), arr.end());
        int team_score = 0;
        for(int i = 0; i < n; ++i){
            dp[i] = arr[i].second;
            for(int j = i - 1; j >= 0; --j){
                // arr sorted by age, latter element has to have high score to maintain increasing susequence
                if(arr[i].second >= arr[j].second){
                    // update each status
                    dp[i] = max(dp[i], dp[j] + arr[i].second); 
                }
            }
            // maximum value could in any place
            team_score = max(team_score, dp[i]); 
        }
        return team_score;
    }
};
