// Cpp code to find number of connected components in graph
// Author: KunalKartik02

#include <bits/stdc++.h>
#define ll long long
using namespace std;

void dfs(int node, vector<int> adj[], vector<bool> &vis)
{
    vis[node] = true;

    for (auto child : adj[node])
    {
        if (!vis[child])
            dfs(child, adj, vis);
    }
}

int main()
{
    ll n, m; // n denotes number of nodes, m denotes number of edges
    cin >> n >> m;

    vector<int> adj[n + 1]; // adjacency list representation of graph.
    for (int i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    bool f = false;
    vector<bool> vis(n + 1, false);
    int cc = 0; // cc denotes number of connected components.
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i, adj, vis);
            ++cc;
        }
    }
    cout << cc << endl;

    return 0;
}