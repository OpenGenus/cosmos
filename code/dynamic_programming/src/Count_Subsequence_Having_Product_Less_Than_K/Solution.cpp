#include<iostream>
#include<cstring>
using namespace std;
int dp[10005][10005];

int helper(int a[], int n, int k , int product)
{
    // base case
    if(n==0)
    {
        return 0;
    }
    if(product > k)
    {
        return 0;
    }
    if(dp[n][product] !=-1)
    {
        return dp[n][product];
    }

    int include = product * a[n-1];

    int exclude =product;
    int count =0;

    if( include < k)
    {
        count++;
    }

    count += helper(a,n-1,k,include) + helper(a,n-1,k,exclude);

    dp[n][product] =count;

    return  dp[n][product];
}

int solve(int a[], int n, int k)
{
    dp[k+1][n+1];
    memset(dp,-1,sizeof(dp));
    int product =1;
    return helper(a,n,k,product);
    
}
int main()
{
    int n;
    cin>>n;
    
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    int k;
    cout<<"Enter the value of k"<<endl;
    cin>>k;

    cout<<solve(a,n,k)<<endl;

    return 0;

}

