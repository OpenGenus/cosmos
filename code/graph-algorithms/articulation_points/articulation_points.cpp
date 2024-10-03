

#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define f first
#define s second
#define pii pair<int,int>
#define vii vector<pair<int,int> >
#define si stack<int>
#define ll long long int
#define MOD 10000007

vector<int> g[200];
int vis[200],disc[200],low[200],parent[200];
int art[200];
int n,e;

set<pair<int,int> > bridges;

void checkArticulation(int ind){
    static int time = 0;

    int children = 0;

    vis[ind] = 1;
    disc[ind] = low[ind] = time++;

    for(int i=0;i<g[ind].size();i++){
        int v = g[ind][i];

        if(vis[v] == 0){
            children++;
            parent[v] = ind;
            checkArticulation(v);

            low[ind] = min(low[ind],low[v]);

            if(parent[ind]==-1 && children>1)
                art[ind]=1;

            if(parent[ind]!=-1 && low[v]>=disc[ind])
                art[ind] = 1;
        }
        else if(v!=parent[ind])
            low[ind] = min(low[ind],disc[v]);
    }
}

void articulation()
{
    for(int i=0;i<n;i++){
        parent[i] = -1;
        vis[i] = 0;
        art[i] = 0;
        low[i] = 0;
        disc[i] = 0;
    }

    for(int i=0;i<n;i++){
        if(vis[i]==0)
            checkArticulation(i);
    }

    for(int i=0;i<n;i++)
        if(art[i]==1)
            cout<<i<<" ";
}

int main()
{
    ios_base::sync_with_stdio(false);

    #ifndef ONLINE_JUDGE
   	freopen("in.txt", "r", stdin);
    #endif
    int t;
    cin>>t;

    while(t--){
        cin>>n>>e;

        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++){
            g[i].clear();
        }
        for(int i=0;i<e;i++){
            int x,y;
            cin>>x>>y;
            x--;
            y--;
            g[x].pb(y);
            g[y].pb(x);
        }
        articulation();
    }
    return 0;
}


