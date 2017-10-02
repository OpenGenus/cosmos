// In the given tree find the distance of all nodes from the source.
#include<bits/stdc++.h>
using namespace std;
const int N = 1E5 + 1;
vector<int> graph[N];
int dist[N];
void dfs(int source,int parent)
{
  for(auto adj : graph[source])
  {
    if(adj == parent) continue;
    dist[adj] = dist[source] + 1;
    dfs(adj,source);
  }
}
int main()
{
  int n; cin>>n;
  for(int i = 0;i<(n-1);i++)
  {
    int u,v; cin>>u>>v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  int source; cin>>source;
  dist[source] = 0;
  dfs(source,-1);
  for(int i = 1;i<=n;i++) cout<<dist[i]<<" ";
  return 0;
}
