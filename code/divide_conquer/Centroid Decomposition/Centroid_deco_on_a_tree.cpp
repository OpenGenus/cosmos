// spj_29's Template.
/***********************************************
    Code for centroid decomposition of a tree.
    overall complexity is nlogn.
************************************************/
#include <bits/stdc++.h>
 
using namespace std;
 
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define fileio freopen("in.in", "r", stdin),freopen("out.out", "w", stdout);
#define ll long long int
#define FF first
#define SS second
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<long long int,long long int>
#define sd(x) scanf("%d",&x)
#define slld(x) scanf("%lld",&x)
#define pd(x) printf("%d\n",x)
#define plld(x) printf("%lld\n",x)
#define pss printf
#define MOD 1000000007
#define INF 1e17
#define eps 0.00001
#define endl '\n'
#define debug(n1) cout<<n1<<endl
ll n;
vector<ll>adj[100005];
ll cenpar[100005];
ll sub[100005],submax[100005];
bool visited[100005];
ll cen[100005],temppar[100005];


void subdfs(ll i,ll p)
{
    //submax[i]=size of maximum subtree of node i.
    //sub[i]=size of subtree of node i.
    //temppar[i]= parent of node i in current component(not necessarily parent in original/final tree).
    submax[i]=0;
    temppar[i]=p;
    sub[i]=1;
    ll m=0;
    for(auto j:adj[i])
        if(j!=p&&!visited[j])
        {
            //recuricively get centroid of subtrees.
            subdfs(j,i),sub[i]+=sub[j];
            if(sub[j]>sub[m])m=j,submax[i]=sub[j];
        }
    // assume current centroid to be centroid of heaviest subtree. and move upwards till we get the true centroid.
    //can be easily proved that it takes linear time.
    m=cen[m];
    if(m==0)m=i;
    while(2*sub[m]<sub[i]||2*submax[m]>sub[i])
        m=temppar[m];
    cen[i]=m;
}
ll getcen(ll i)
{
    //preform dfs on the component rooted at i with al the processed vertices marked visited.
    //subdfs() gets the centroid of the connected component with node i.
    //It is stored in cen[i].
    subdfs(i,i);
    ll j=cen[i];
    //mark node as visited so that it is not processed in components it does not belong to.
    visited[j]=1;
    for(auto i:adj[j])
        if(!visited[i])
            //get centroid of subtree and put its parent to be the current centroid (j).
            cenpar[getcen(i)]=j;
    return j;
}

int main() {
//Take input. n = the number of nodes in the original tree.
slld(n);
for(int i=1;i<n;i++)
{
    ll x,y;
    // There is an edge between node x and node y
    slld(x);slld(y);
    //Add x and y to each other's adjecency lists
    adj[x].pb(y);
    adj[y].pb(x);
}
//getcen() is the main function which constructs the entire centroid tree and returns its root.
ll root=getcen(1);
//Set the parent of root to be root(optional)
cenpar[root]=root;
//The information of the entire centroid tree is now stored in the cenpar[] array cenpar[i]=parent of ith node in the centroid tree.
    return 0;
           }
