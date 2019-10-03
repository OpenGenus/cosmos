/*
 * BY:-  https://github.com/alphaWizard
 *
 * algorithm:- finds maximum bipartite matching for a given bipartite graph
 *          by taking input number of nodes(n) and number of edges(m)
 *
 * Part of Cosmos by OpenGenus Foundation
 */
#include <iostream>
#include <vector>

std::vector<int> adj[10000];
bool mark[10000];
int match[10000];
void init()
{
    for (int i = 0; i < 10000; ++i)
    {
        match[i] = -1; adj[i].clear();
    }
}
bool dfs(int u)
{
    for (int i = adj[u].size() - 1; i >= 0; --i)
    {
        int v = adj[u][i];
        if (!mark[v])
        {
            mark[v] = true;
            if (match[v] == -1 || dfs(match[v]))
            {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    using namespace std;
    init();
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
    }

    int ct = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < 10000; ++j)
            mark[j] = false;
        if (dfs(i))
            ++ct;
    }

    cout << ct << endl;

    return 0;
}
