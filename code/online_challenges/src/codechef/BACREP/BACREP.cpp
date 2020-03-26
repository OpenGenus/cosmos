#include <iostream>

using namespace std;

#define ll long long
#define dd double
#define endl "\n"
#define pb push_back
#define all(v) v.begin(),v.end()
#define mp make_pair
#define fi first
#define se second
#define fo(i,n) for(int i=0;i<n;i++)
#define fo1(i,n) for(int i=1;i<=n;i++)
ll mod=1000000007;
const ll  N=500050;
bool vis[N];
vector <int> adj[N];
ll depth[N]={0};
vector <int> atd[N];
ll maxdepth=1;
ll par[N]={0};

ll po(ll k ,ll n,ll ans,ll temp,ll ans1)
{
    if(n==0)return ans;
    
    while(temp<=n)
    {
        ans*=ans1;ans%=mod;ans1=ans1*ans1;ans1%=mod;n=n-temp;temp*=2;
    }
    return po(k,n,ans,1,k)%mod;
    //eg. po(2,78,1,1,2);
}
void bfs(int root)
{
    vis[root]=1;
    depth[root]=1;
    atd[1].pb(root);
    queue <int> q;
    q.push(root);
    while(!q.empty())
    {
        ll a=q.front();
        // vis[a]=1;
        q.pop();
        for(int i:adj[a])
        {
            if(vis[i])
                continue;
            vis[i]=1;    
            depth[i]=depth[a]+1;
            atd[depth[i]].pb(i);
            par[i]=a;
            maxdepth=depth[i];
            q.push(i);
        }
    }
}
ll min(ll a,ll b)
{
    if(a>b)return b;else return a;
}
ll max(ll a,ll b)
{
    if(a>b)return a;else return b;
}
int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll t;
    //cin>>t;
    t=1;
    while(t--)
    {
        ll n,q;
        
    cin>>n>>q;
    fo(i,n-1)
    {
        ll a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    bfs(1);
    ll store[n+1]={0};
    for(int i=1;i<=n;i++)
    {
        ll c;
        cin>>c;
        store[i]=c;
    }
    while(q--)
    {
        for(int i=maxdepth;i>=2;i--)
        {
            for(int j:atd[i])
            {
                if(adj[j].size()!=1)
                    store[j]=0;
                store[j]+=store[par[j]];    
            }
        }
        store[1]=0;
        char ch;
        cin>>ch;
        if(ch=='?')
        {
            ll a;
            cin>>a;
            cout<<store[a]<<'\n';
        }
        else
        {
            ll a,b;
            cin>>a>>b;
            store[a]+=b;
        }
    }
   }

    return 0;
}
