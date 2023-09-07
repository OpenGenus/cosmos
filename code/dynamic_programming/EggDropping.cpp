/*
There are n number of eggs and building which has k floors. 
Write an algorithm to find the minimum number of drops is required to know the floor from which if egg is dropped, it will break.
*/

#include<bits/stdc++.h>
using namespace std;
int eggdroping(int eggs,int floors){
    int dp[eggs+1][floors+1];
    for(int i=0;i<=floors;i++)
        dp[0][i]=0,dp[1][i]=i;
    for(int i=0;i<=eggs;i++)
        dp[i][0]=0;
    for(int i=2;i<eggs+1;i++){
        for(int j=1;j<floors+1;j++){
            dp[i][j]=INT_MAX;
            for(int k=1;k<=j;k++){
                int c=1+max(dp[i-1][k-1],dp[i][j-k]);
                dp[i][j]=min(dp[i][j],c);
            }
        }
    }

//the dp table
    /*for(int i=0;i<=eggs;i++){
        for(int j=0;j<=floors;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }*/
    return dp[eggs][floors];
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int eggs,floors;
        cin>>eggs>>floors;
        cout<<eggdroping(eggs,floors)<<endl;
    }
}
