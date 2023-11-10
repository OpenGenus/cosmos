// recursion 
// TC - O(2^n) , SC - O(1)

class Solution {
public:
    int func(int n){
        if(n <= 1){
            return n;
        }
        return func(n-1) + func(n-2);
    }
    
    int climbStairs(int n) {
        return func(n+1);
    }
};

// memoisation
// TC - O(n), SC - O(n) + O(n)

class Solution {
public:
    int func(int n, vector<int> &dp){
        if(n <= 1){
            return n;
        }
         if(dp[n] !=-1){
             return dp[n];
         }
        return dp[n] = func(n-1, dp) + func(n-2, dp);
    }
    
    int climbStairs(int n) {
        vector<int>dp(n+2, -1);
        return func(n+1, dp);
    }
};

// tabulation
// TC - O(n), SC - O(n)

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+2, -1);
        dp[0] = 0, dp[1] = 1;
        for(int i = 2; i <=  n+1 ;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n+1];
    }
};


// space optimised 
// TC - O(n) , SC - O(1)

class Solution {
public:
    int climbStairs(int n) {
        int prev1 = 1, prev2 = 0;
        for(int i = 1;i<=n;i++){
            int ans = prev1 + prev2;
            prev2 = prev1;
            prev1 = ans;
        }
        return prev1;
    }
};
