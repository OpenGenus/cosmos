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

// eulerian for undirected graph

map<int,vector<int> > g;
int vis[200];
int in[200],out[200],already[200];
vector<int> vertices;
int maxi = 0;
int n,e;

int dfs(int ind){
    vis[ind]=1;

    for(int i=0;i<g[ind].size();i++){
        if(vis[g[ind][i]]==0)
            dfs(g[ind][i]);
    }
}

int isConnected(int i){
    memset(vis,0,sizeof(vis));

    dfs(i);

    for(auto p:vertices)
        if(vis[p]==0 && g[p].size()>0)
            return 0;

    return 1;
}

int eulerian(){
    vector<int> temp;
    int cou=0,eq=0;
    maxi = vertices.size();
    for(auto p:vertices){
    cout<<"00 "<<char(p)<<" "<<in[p]<<" "<<out[p]<<endl;
        if(in[p]!=out[p]){
            eq++;
            temp.pb(p);
        }
    }

    cout<<"equ "<<eq<<endl;
    if(eq==0){
        if(isConnected(vertices[0]))
            return 1;
        return 0;
    }
    else if(eq>2){
        return 0;
    }

    int x1=temp[0],x2=temp[1];

    if(in[x1]==out[x1]+1 && in[x2]+1==out[x2]){
        if(isConnected(x2))
            return 2;
        return 0;
    }

    if(in[x2]==out[x2]+1 && in[x1]+1==out[x1]){
        if(isConnected(x1))
            return 2;
        return 0;
    }
    return 0;
}

int check(){
    int res = eulerian();
    if(res==0)
        cout<<"Not eulerian\n";
    else if(res==1)
        cout<<"Euler cycle\n";
    else if(res==2)
        cout<<"Euler path\n";
}

void printGraph(){
    for(auto p:g){
        cout<<"here : "<<in[p.f]<<" "<<out[p.f]<<" "<<char(p.f)<<endl;
        for(int i=0;i<p.s.size();i++)
            cout<<char(p.s[i])<<" ";
        cout<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;

    while(t--){
        cin>>e;

        g.clear();
        memset(in,0,sizeof(in));
        memset(out,0,sizeof(out));
        vertices.clear();
        memset(already,0,sizeof(already));
        for(int i=0;i<e;i++){
            int x,y;
            if(already[x]==0){
                already[x]=1;
                vertices.pb(x);
            }
            if(already[y]==0){
                already[y]=1;
                vertices.pb(y);
            }
            out[x]++;
            in[y]++;
            g[x].pb(y);
        }
        printGraph();
        check();
    }
    return 0;
}

