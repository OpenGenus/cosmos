#include<iostream>
using namespace std;

/*
 * Part of Cosmos by OpenGenus Foundation
*/
#define MAX 100

int coinWays(int amt,int coins[],int n){

    // init the dp table
    int dp[MAX] = {0};
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

    int coins[] = {1,2,3,8}; // coin denominations 
    int amount = 3;  // amount
    cout<<coinWays(amount,coins,4)<<endl;
    return 0;
}
