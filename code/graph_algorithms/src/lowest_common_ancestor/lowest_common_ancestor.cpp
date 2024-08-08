#include <iostream>
#include <vector>
#include <array>
using namespace std;

// Part of Cosmos by OpenGenus Foundation

// Problem Statement
/*
 * Given a tree with n nodes
 * Your task is to process q queries of the following form:
 * who is the lowest common ancestor of nodes a and b in the tree?
 *
 * The lowest common ancestor of two nodes of a rooted tree is the lowest node
 * whose subtree contains both the nodes.
 */

void dfs(int k, int p, vector<int> &depth, vector<vector<int>> &adj, vector<array<int, 20>> &ancestor)
{
    ancestor[k][0] = p;
    depth[k] = depth[p] + 1;
    for (int i = 1; i < 20; i++)
        ancestor[k][i] = ancestor[ancestor[k][i - 1]][i - 1];

    for (int i : adj[k])
        if (i != p)
            dfs(i, k, depth, adj, ancestor);
}

int kthAncestor(int k, int x, vector<array<int, 20>> &ancestor)
{
    for (int i = 0; i < 20; i++)
        if (x & (1 << i))
            k = ancestor[k][i];

    return k;
}

int lca(int a, int b, vector<array<int, 20>> &ancestor, vector<int> &depth)
{
    if (depth[a] < depth[b])
        swap(a, b);

    a = kthAncestor(a, depth[a] - depth[b], ancestor);

    if (a == b)
        return b;

    for (int i = 19; i >= 0; i--)
        if (ancestor[a][i] != ancestor[b][i])
            a = ancestor[a][i], b = ancestor[b][i];

    return ancestor[a][0];
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> depth(n + 1);
    vector<array<int, 20>> ancestor(n + 1);

    dfs(1, 0, depth, adj, ancestor);

    int q;
    cin >> q;
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b, ancestor, depth) << '\n';
    }
}
