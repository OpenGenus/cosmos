#include <bits/stdc++.h>
using namespace std;
int knapsack(int wt[],int W,int n){
    bool t[n+1][W+1];
    for (int j=1;j<=W;j++)
        t[0][j]=false;
    for (int i=0;i<=n;i++)
        t[i][0]=true;
    for (int i=1;i<n+1;i++){
        for (int j=1;j<W+1;j++){
            if (wt[i-1]<=j)
                t[i][j]=t[i-1][j-wt[i-1]] || t[i-1][j];
            else 
                t[i][j]=t[i-1][j];
        }
    }
    int ls,rs;
    for (int i=W/2;i>=0;i--){
        if (t[n][i]){
            ls=i;break;
        }
    }
    for (int i=W/2+1;i<=W+1;i++){
        if (t[n][i]){
            rs=i;break;
        }
    }
    return rs-ls;
}

int main(){
    int arr[]={1,2,3,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    int W=0;
    for (int i=0;i<n;i++)
        W+=arr[i];
    cout<<knapsack(arr,W,4)<<endl;
}