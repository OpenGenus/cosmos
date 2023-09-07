/*
Problem Statement: Given a head node which needs to be considered 
                   as the starting point of the graph. We need to find
                   the nodes that are unreachable from the head node.
                   Here n is the number of nodes and m is the number of edges.
Solution: I've solved this using Depth-First-Search approach.
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define FIO ios::sync_with_stdio(0);
vector<ll> vis(100001,0);
vector<ll> a[100001];
void dfs(ll s)
{
	ll j;
	vis[s]=1;
	for(j=0;j<a[s].size();j++)
	{
		if(!vis[a[s][j]])
			dfs(a[s][j]);
	}
}
int main() 
{
	FIO;
	ll i,c=0,n,m,x,y,z;
	cin>>n>>m;
	vector<pair<ll,ll>> v;
	map<ll,ll> mp1,mp2;
	set<ll> sp;
	stack<ll> st;
	queue<ll> q;
	for(i=0;i<m;i++)
	{
		cin>>x>>y;
		a[x].pb(y);
		a[y].pb(x);
	}
	cin>>z;
	dfs(z);
	for(i=1;i<=n;i++)
	{
		if(!vis[i])
			c++;
	}
	cout<<c;
	return 0;
}
