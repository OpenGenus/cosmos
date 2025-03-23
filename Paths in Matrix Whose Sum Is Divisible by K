class Solution {
public:
    
    int m = 1e9+7;
    int helper(vector<vector<int>>&grid, int i, int j, int k, int sum, vector<vector<vector<int>>> &dp){
        if(i >= grid.size() || j >=grid[0].size()) return 0;
        if(i==grid.size()-1&&j==grid[0].size()-1){
           if((sum+ grid[i][j])%k!=0) return 0;
            else return 1;
        }
        sum = sum%k;
        if(dp[i][j][sum]!=-1) return dp[i][j][sum];
        int &final = dp[i][j][sum];
        sum = (sum%k + grid[i][j]%k)%k;
       return final = (helper(grid,i+1,j,k,sum,dp)%m + helper(grid,i,j+1,k,sum,dp)%m)%m;
    }
    
    
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        // memset(dp,-1,sizeof(dp));
        for(int i = 0; i < grid.size();i++){
            for(int j = 0;j < grid[0].size();j++){
                grid[i][j] = grid[i][j]%k;
            }
        }
        // rest work
  vector<vector<vector<int>>> dp(grid.size()+1 , vector<vector<int>>(grid[0].size()+1 , vector<int> (k , - 1)));
        return helper(grid,0,0,k,0,dp);
    }
};
