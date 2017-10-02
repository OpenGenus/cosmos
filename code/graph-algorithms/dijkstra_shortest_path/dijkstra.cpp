// https://www.hackerearth.com/practice/algorithms/graphs/shortest-path-algorithms/practice-problems/algorithm/shortest-path-problem/
#include<bits/stdc++.h>
using namespace std;
const int N = 1E5 + 1;
vector<pair<int,int> > graph[N];
set<pair<int,int> > pq;
int dist[N],vis[N];
int main()
{
  int n,m; cin>>n>>m;
  while(m--)
  {
    int u,v,w; cin>>u>>v>>w;
    graph[u].push_back({v,w});
  }
  for(int i = 0;i<=n;i++) dist[i] = 1E9, vis[i] = 0;
  dist[1] = 0; 
  pq.insert({0,1});
  while(!pq.empty())
  {
    pair<int,int> p = *pq.begin();
    pq.erase(pq.begin());
    int u = p.second;
    if(vis[u]) continue;
    vis[u] = 1;
    for(auto k : graph[u])
    {
      if(dist[k.first]>(dist[u]+k.second))
      {
        dist[k.first] = dist[u] + k.second;
        pq.insert({dist[k.first],k.first});
      }
    }
  }
  for(int i = 2;i<=n;i++) cout<<dist[i]<<" ";
}
