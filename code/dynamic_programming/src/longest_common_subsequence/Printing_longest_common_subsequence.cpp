//Printing longest common sub-sequence
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

//Helper function to print LCA
string LCA(string s1,string s2){
    int m=s1.length();
    int n=s2.length();
    int dp[m+1][n+1];
    
    //initialising first row
    for(int i=0; i<=m; i++){
        dp[0][i]=0;
    }
    
    //initialising first column
    for(int j=0; j<=n; j++){
        dp[j][0]=0;
    }
    
    //creating DP table
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(s1[i-1]==s2[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            else 
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    
    int i=m,j=n;
    string result;
    
    while(i>0&&j>0){
        if(s1[i-1]==s2[j-1]){
            result.push_back(s1[i-1]);
            i--; j--;
        }
        else{
            if(dp[i][j-1]>dp[i-1][j])
                j--;
            else
                i--;
        }
    }
    
    reverse(result.begin(),result.end());
    return result;
}


int main()
{
    string s1="abcdaf";
    string s2="acbcf";
    
    string answer=LCA(s1,s2);
    cout<<"The LCA is: "<<answer;
    return 0;
}