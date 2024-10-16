// Part of Cosmos by OpenGenus Foundation

#include<bits/stdc++.h>
using namespace std;


    //Tabulation method
    // Time complexity: O(m*n)
    int uniquePaths(int m, int n) {
        int dp[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==0)
                    dp[i][j]=1;
                else
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }


    //nCr method
    // Time complexity: O(m+n)
    int uniquePaths1(int m, int n) {
        int N=m+n-2;
        int r=m-1;
        double res=1;
        for(int i=1;i<=r;i++){
            res=res*(N-r+i)/i;
        }
        return (int)res;
    }
    
    
    // Brute force recursive method
    // Time complexity: O(2^(m+n))
    int uniquePaths2(int m, int n) {
        if(m==1 || n==1)
            return 1;
        return uniquePaths2(m-1,n)+uniquePaths2(m,n-1);
    }

    //Time complexity: O(m*n)
    int solve(int i, int j, vector<vector<int>> &dp, int &m, int &n){
        if (i == m - 1 || j == n - 1) return 1;
        if (dp[i][j] != 0) return dp[i][j];
        dp[i][j] = solve(i + 1, j, dp, m, n) + solve(i, j + 1, dp, m, n);
        return dp[i][j];
    }
    int uniquePaths3(int m, int n){
        vector<vector<int>> dp(m, vector<int>(n, 0));
        return solve(0, 0, dp, m, n);
    }

    int main(){
        int m,n;
        cin>>m>>n;
        cout<<uniquePaths(m,n)<< endl;
        cout<<uniquePaths1(m,n) << endl;
        cout<<uniquePaths2(m,n) << endl;
        cout<<uniquePaths3(m,n) << endl;
        return 0;
    }
    