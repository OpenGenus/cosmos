#include <iostream>
#include <vector>
#include <algorithm>

/* Part of Cosmos by OpenGenus Foundation */

bool dfs(int v, std::vector<std::vector<int>> &g, std::vector<int> &dp)
{
    for (int u : g[v])
    {
        if (!dp[u])
        {
            dp[u] = 3 - dp[v]; // 3 - 1 = 2; 3 - 2 = 1
            dfs(u, g, dp);
        }
        if (dp[u] != 3 - dp[v])
            return false;
    }

    return true;
}

// Time complexity: O(|V| + |E|)
bool check_bipartite(std::vector<std::vector<int>> &g)
{
    int n = (int) g.size();
    std::vector<int> dp(n);

    for (int i = 0; i < n; i++)
        if (!dp[i])
        {
            dp[i] = 1;
            if (!dfs(i, g, dp))
                return false;
        }

    return true;
}

int main()
{
    std::cout << "Enter the number of vertexes:" << std::endl;
    int n;
    std::cin >> n;

    std::cout << "Enter the number of edges:" << std::endl;
    int m;
    std::cin >> m;

    std::cout << "Enter the edges in the following format: u v. 0 <= u, v < n" << std::endl;
    std::vector<std::vector<int>> g(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        std::cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    if (check_bipartite(g))
        std::cout << "This graph is bipartite.\n";
    else
        std::cout << "This graph is not bipartite.\n";
    return 0;
}
