#include<iostream>
using namespace std;

/*
 * Part of Cosmos by OpenGenus Foundation
*/

///Coin Change Problem 
///Top Down DP
int dp[100] = {0};
int coinWaysTD(int amt,int coins[],int n){
    if(amt==0){
        dp[0] = 1;
        return 1;
    }
    ///Recursive Case
    int ans = 0;
    
    if(dp[amt]!=0){
        return dp[amt];
    }
    for(int i=0;i<n;i++){
        if(amt-coins[i]>=0){
            ans += coinWaysTD(amt-coins[i],coins,n);
        }
    }
    ///Store and return for the first time
    dp[amt] = ans;
    return ans;
}

///Bottom Up DP
int coinWaysBU(int amt,int coins[],int n){
    int dp[100] = {0};
    dp[0] = 1;

    for(int i=1;i<=amt;i++){
        for(int j=0;j<n;j++){
           if(i-coins[j]>=0){
                dp[i] += dp[i-coins[j]];
           }
        }
    }
    return dp[amt];
}


int main(){

    int coins[] = {1,2,3,8};
    int amount = 3;
    cout<<coinWaysTD(amount,coins,4)<<endl;
    cout<<coinWaysBU(amount,coins,4)<<endl;
return 0;
}
