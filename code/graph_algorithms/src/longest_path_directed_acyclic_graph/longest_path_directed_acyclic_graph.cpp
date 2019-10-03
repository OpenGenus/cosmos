#include <iostream>
#include <vector>
#include <algorithm>

/* Part of Cosmos by OpenGenus Foundation */

void dfs(int v, std::vector<std::vector<int>> &g, std::vector<int> &dp)
{
    if (dp[v])
        return;

    dp[v] = 1;
    for (int u : g[v])
    {
        dfs(u, g, dp);
        dp[v] = std::max(dp[v], dp[u] + 1);
    }
}

// Time complexity: O(|V| + |E|)
std::vector<int> longest_path_directed_acyclic_graph(std::vector<std::vector<int>> &g)
{
    int n = (int) g.size();
    std::vector<int> dp(n);

    for (int i = 0; i < n; i++)
        if (!dp[i])
            dfs(i, g, dp);

    int start = (int) (max_element(dp.begin(), dp.end()) - dp.begin());
    int dist = dp[start] - 1;
    std::vector<int> res;
    res.push_back(start);
    while (dist > 0)
    {
        for (int nxt : g[start])
            if (dp[nxt] == dist)
            {
                start = nxt;
                dist--;
                res.push_back(start);
                break;
            }
    }

    return res;
}

int main()
{
    std::cout << "Enter the number of vertexes:" << std::endl;
    int n;
    std::cin >> n;

    std::cout << "Enter the number of edges:" << std::endl;
    int m;
    std::cin >> m;

    std::cout <<
        "Enter the edges in the following format: u v -- an edge from u to v. 0 <= u, v < n" <<
        std::endl;
    std::vector<std::vector<int>> g(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        std::cin >> u >> v;
        g[u].push_back(v);
    }

    std::cout << "Longest path:\n";
    for (int v : longest_path_directed_acyclic_graph(g))
        std::cout << v << " ";
    std::cout << "\n";
    return 0;
}
