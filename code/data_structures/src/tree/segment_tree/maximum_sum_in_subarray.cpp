// program for calculating maximum sum in a subarray

#include<bits/stdc++.h>
#define ll long long int
using namespace std;

struct p {
    ll sum,maxSubSum,maxSumFromRight,maxSumFromLeft;
};

void build(ll* a,p* tree,ll i, ll j, ll k) {
  if(i == j) {
    tree[k].sum = a[i];
    tree[k].maxSubSum = a[i];
    tree[k].maxSumFromRight = a[i];
    tree[k].maxSumFromLeft = a[i];
    return ;
  }

  ll mid = (i+j)/2;
  build(a,tree,i,mid,k*2);
  build(a,tree,mid+1,j,k*2+1);

  tree[k].sum = tree[k*2].sum + tree[k*2+1].sum;
  tree[k].maxSumFromRight = max( tree[k*2+1].maxSumFromRight, tree[k*2+1].sum + tree[k*2].maxSumFromRight );
  tree[k].maxSumFromLeft = max( tree[k*2].maxSumFromLeft, tree[k*2].sum + tree[k*2+1].maxSumFromLeft );
  tree[k].maxSubSum = max( tree[k*2].maxSubSum, tree[k*2+1].maxSubSum );
  tree[k].maxSubSum = max( tree[k].maxSubSum, tree[k*2].maxSumFromRight + tree[k*2+1].maxSumFromLeft );
}

p query(p* tree,ll s,ll e,ll i, ll j, ll k) {
  if(j < s || i > e || i > j){
    p t;
    t.maxSubSum = INT_MIN;
    t.maxSumFromLeft = INT_MIN;
    t.maxSumFromRight = INT_MIN;
    t.sum = 0;
    return t;
  }

  if(s >= i && e <= j) {
    return tree[k];
  }

  ll mid = (s+e)/2;
  p l1,l2,l;
  l1 = query(tree,s,mid,i,j,k*2);
  l2 = query(tree,mid+1,e,i,j,k*2+1);

  l.sum = l1.sum + l2.sum;
  l.maxSumFromRight = max( l2.maxSumFromRight, l2.sum + l1.maxSumFromRight );
  l.maxSumFromLeft = max( l1.maxSumFromLeft, l1.sum + l2.maxSumFromLeft );
  l.maxSubSum = max( l1.maxSubSum, l2.maxSubSum );
  l.maxSubSum = max( l.maxSubSum, l1.maxSumFromRight + l2.maxSumFromLeft );
  return l;
}

int main() {
  ll n,q,x,y;
  char k;
  
  // enter size of array
  cin>>n;
  ll* a = new ll[n];
  
  // enter elements of array
  for(ll i=0;i<n;i++)
    cin>>a[i];

  p* tree = new p[4*n + 1];
  build(a,tree,0,n-1,1);

  // number of queries
  cin>>q;
  while(q--){
    // enter left and right for each query
    cin>>x>>y;
    cout<<query(tree,0,n-1,x-1,y-1,1).maxSubSum<<"\n";
  }
  return 0;
}
