#include<iostream>
#include<vector>
using namespace std;

/*
 * Part of Cosmos by OpenGenus Foundation
*/
const int MAX=100;

int coinWays(int amt,vector<int>& coins){

    // init the dp table
    vector<int> dp(MAX, 0);
    int n = coins.size();
    dp[0] = 1; // base case
    
    for(int j=0;j<n;j++){
        for(int i=1;i<=amt;i++){
            if(i-coins[j]>=0){
                // if coins[j] < i then add no. of ways - 
                // - to form the amount by using coins[j]
                dp[i] += dp[i-coins[j]]; 
           }
        }
    }

    //final result at dp[amt]
    return dp[amt];
}


int main(){

    vector<int> coins = {1,2,3}; // coin denominations 
    int amount = 4;  // amount
    cout<<coinWays(amount,coins)<<endl;
    return 0;
}
