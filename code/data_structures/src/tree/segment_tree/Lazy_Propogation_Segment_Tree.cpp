#include<bits/stdc++.h>
using namespace std;

vector<int>tree(400,0),lazy(400,0);
int a[100] = {1, 3, 5, 7, 9, 11};

int buildtree(int node,int start,int end)
{
	if(start==end)
	{
		tree[node]=a[start];
		return 0;
	}
	int mid=(start+end)/2;
	buildtree(2*node+1,start,mid);
	buildtree(2*node+2,mid+1,end);
	tree[node]=tree[2*node+1]+tree[2*node+2];
}
int getsum(int node,int start,int end,int l,int r)
{
	if(lazy[node]!=0)
	{
		tree[node]+=(end-start+1)*lazy[node];
		if(start!=end)
		{
			lazy[2*node+1]=lazy[node];
			lazy[2*node+2]=lazy[node];
		}
		lazy[node]=0;
	}
	if(start>r || end<l)
		return 0;
	if(start>=l && end<=r)
		return tree[node];
	int mid=(start+end)/2;
	return getsum(2*node+1,start,mid,l,r)+getsum(2*node+2,mid+1,end,l,r);
}
int updaterange(int node,int start,int end,int l,int r,int diff)
{
	if(lazy[node]!=0)
	{
		tree[node]+=(end-start+1)*diff;
		if(start!=end)
		{
			lazy[2*node+1]+=lazy[node];
			lazy[2*node+2]+=lazy[node];
		}
		lazy[node]=0;
	}
	if(start>r || end<l)
		return 0;

	if(start>=l && end<=r)
	{
		tree[node]+=(end-start+1)*diff;
		if(start!=end)
		{
			lazy[2*node+1]+=diff;
			lazy[2*node+2]+=diff;	
		}
		return 0;
	}
	int mid=(start+end)/2;
	updaterange(2*node+1,start,mid,l,r,diff);
	updaterange(2*node+2,mid+1,end,l,r,diff);
	tree[node]=tree[2*node+1]+tree[2*node+2];	
}
int main()
{

	buildtree(1,1,5);
	cout<<getsum(1,1,5,1,3)<<endl;
	updaterange(1,1,5,1,5,10);
	cout<<getsum(1,1,5,1,3)<<endl;
}