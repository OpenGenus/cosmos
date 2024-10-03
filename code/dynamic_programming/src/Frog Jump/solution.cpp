/*
Problem Statement
There is a frog on the 1st step of an N stairs long staircase. The frog wants to reach the Nth stair. HEIGHT[i] is the height of the (i+1)th stair.If Frog jumps from ith to jth stair, the energy lost in the jump is given by |HEIGHT[i-1] - HEIGHT[j-1] |.In the Frog is on ith staircase, he can jump either to (i+1)th stair or to (i+2)th stair. Your task is to find the minimum total energy used by the frog to reach from 1st stair to Nth stair.
*/
// Recursion solution : TLE

#include <bits/stdc++.h>
int func(int n, vector<int>& heights){
    if(n == 0){
        return 0;
    }
    int left = func(n-1, heights) + abs(heights[n] - heights[n-1]);
    int right = INT_MAX;
    if(n > 1){
        right =  func(n-2, heights) + abs(heights[n] - heights[n-2]);
    }
    return min(left , right);
}
int frogJump(int n, vector<int> &heights)
{
    return func(n - 1, heights); // n-1 as frog is already on 1st stair
}

// Memoisation

#include <bits/stdc++.h>
int func(int n, vector<int>& heights, vector<int>& dp){
    if(n == 0){
        return 0;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    int left = func(n-1, heights, dp) + abs(heights[n] - heights[n-1]);
    int right = INT_MAX;
    if(n > 1){
        right =  func(n-2, heights, dp) + abs(heights[n] - heights[n-2]);
    }
    return dp[n] = min(left , right);
}
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n , -1);
    return func(n - 1, heights, dp); // n-1 as frog is already on 1st stair
}

// Tabulation


int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n , -1);
    // covering base cases
    dp[0] = 0;
    
    // removing recursion
    for(int i = 1; i <= n-1; i++){
        int left = dp[i-1] + abs(heights[i] - heights[i-1]);
        int right = INT_MAX;
        if(i > 1){
            right = dp[i-2] + abs(heights[i] - heights[i-2]);
        }
        dp[i] = min(left, right);
    }
     return dp[n-1];
}

//Space Optimisation


int frogJump(int n, vector<int> &heights)
{
    int one = 0, two = 0;
    
    // removing recursion
  
    for(int i = 1; i <= n-1; i++){
        int left = two + abs(heights[i] - heights[i-1]);
        int right = INT_MAX;
        if(i > 1){
            right = one + abs(heights[i] - heights[i-2]);
        }
        
        int ans = min(left, right);
        if(i == 1){
            two = ans;
        }
        else{
            one = two;
            two = ans;
        }
        
    }
     return two;
}
