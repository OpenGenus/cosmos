// https://www.hackerrank.com/challenges/bfsshortreach/problem
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> graph[100002];
ll n;
void bfs(ll source)
{ 
  ll dist[n+1], vis[n+1];
  for(ll i = 0;i<=n;i++)
    dist[i] = vis[i] = 0;
  queue<ll> q;
  q.push(source);
  while(!q.empty())
  { 
    ll u = q.front();
    q.pop(); 
    vis[u] = 1;
    for(auto k : graph[u])
    {
      if(vis[k]==0)
      {
        q.push(k);
        dist[k] = dist[u] + 6; 
        vis[k] = 1;
      }
    }
  }
  for(ll i=1;i<=n;i++)
    if(dist[i]&&i!=source) cout<<dist[i]<<" ";
    else if(i!=source) cout<<"-1 ";
}
int main() {
  ll t; cin>>t;
  while(t--)
  { 
    ll m; cin>>n>>m;
    for(ll i=0;i<=n;i++) graph[i].clear();
    while(m--)
    {
      ll u,v; cin>>u>>v;
      graph[u].push_back(v);
      graph[v].push_back(u);
    }
    ll source; cin>>source;
    bfs(source);
    cout<<endl;
  }
  return 0;
}
