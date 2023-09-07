#include<iostream>
#include<string.h>
using namespace std;



int  unboundedKnapsack(int w,int n,int val[],int wt[])
{
	int i,j;

	int dp[w+1];

	memset(dp,0,sizeof(dp));

	for(i=0;i<=w;i++)
	{
		for(j=0;j<n;j++)
		{
			
			if(i>=wt[j])
			dp[i]=max(dp[i],dp[i-wt[j]]+val[j]);

		}
	}

	return dp[w];
}

int main()
{
    int W = 100;
    int val[] = {10, 30,20 };
    int wt[] = {5,10,15};
    int n = 3;
 
    cout<<unboundedKnapsack(W, n, val, wt)<<endl;
 	
    return 0;
}