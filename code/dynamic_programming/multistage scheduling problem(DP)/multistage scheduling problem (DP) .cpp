/*
MULTISTAGE SCHEDULING PROBLEM:-
program to find out the length of a shortest path between source and destination where a graph G is given as input in the format described below.

First line indicates integer ‘n, m’ seperated by space where n is no of vertices(including source and destination) and m stands for the number of edges. After that each line indicates integers: a b w where there is an edge of weight w from vertex a to vertex b and an edge of weight w from vertex b to a.
*/

#include "bits/stdc++.h"
using namespace std;

int main() {

ios_base::sync_with_stdio(false);
cin.tie(0);

int t,n,n1,a,b,w,i,j,m;
int g[1005][1005];
cin>>t;
while(t--){    

for(i=1;i<=1000;i++)
{
for(j=1;j<=1000;j++)
g[i][j]=-1;
}
cin>>n>>m;



for(i=0;i<m;i++)
{
	cin>>a>>b>>w;
	g[a][b]=w;
	g[b][a]=w;

}


int dp[1005],ans=INT_MAX,temp;

for(i=1;i<=1000;i++)
dp[i]=INT_MAX;
dp[1]=0;



for(i=2;i<=n;i++)
{
	for(j=1;j<=i-1;j++)
	{
		if(g[i][j]!=-1){
			dp[i]=min(dp[i],dp[j]+g[i][j]);
		}
	}
}

cout<<dp[n]<<"\n";

}    
return 0;
}
