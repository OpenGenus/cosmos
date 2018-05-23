#include <iostream>
#include <vector>
#include <climits>

using namespace std;
typedef long long ll;
// Part of Cosmos by OpenGenus Foundation
const int MAXN = 1e4 + 5;
vector<int> adj[MAXN];
bool vis[MAXN], AP[MAXN];
int n, m, currTime, disc[MAXN];
int low[MAXN];  // low[i] is the minimum of visited currTime of all vertices which are reachable from i.

void init()
{
    currTime = 0;
    for (int i = 1; i <= n; i++)
    {
        adj[i].clear(); vis[i] = false; AP[i] = false; disc[i] = 0; low[i] = INT_MAX;
    }
}

void dfs(int u, int parent)
{
    vis[u] = true;
    disc[u] = low[u] = currTime + 1;
    int child = 0;
    for (auto v : adj[u])
    {
        if (v == parent)
            continue;
        if (!vis[v])
        {
            child = child + 1;
            currTime++;
            dfs(v, u);
            //check if subtree rooted at v has a connection to one of the ancestors of u.
            low[u] = min(low[u], low[v]);

            if (parent == -1 && child > 1)
                AP[u] = true;

            if (parent != -1 && low[v] >= disc[u])
                AP[u] = true;
        }
        else
            // back edge.
            low[u] = min(low[u], disc[v]);
    }
}

int main()
{
    cin >> n >> m;  // n = number of vertices, m = number of edges
    init();
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, -1); //start from any random vertex, make its parent -1.
    return 0;
}
