/*
 * Part of Cosmos by OpenGenus foundation
 * 
 * Redundant Connection
 * 
 * Description
 * 
 * Return an edge that can be removed from an undirected graph so that the resulting graph is a tree of N nodes
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> parent; //disjoint set;

int findParent(int a)
{
    if (parent[a] != a)
        return parent[a] = findParent(parent[a]);
    else
        return a;   
}

vector<int> findRedundantConnection(vector<vector<int>>& edges) 
{
    int n = edges.size();
    parent.resize(n+1,0);
    for(int i=0;i<=n;i++)
    {
        parent[i] = i;
    }
    vector<int> ans(2,0);    //storing the answer
    for(int i=0;i<n;i++)
    {
        int x = findParent(edges[i][0]);    //Union Set
        int y = findParent(edges[i][1]);
        if(x != y)
            parent[y] = x;
        else
        {
            ans[0] = edges[i][0];
            ans[1] = edges[i][1];
        }
    }
    return ans;
}

int main ()
{
    vector<vector<int>> edges;
    int n , e;
    cin >> n >> e;
    cout << "Input number of vertices" << endl;
    cout << "Input number of edges" << endl;
    for(int i=0;i<e;i++)
    {
        int u , v;    //temporary variables
        vector<int> edge(2);    //single edge
        cin >> u >> v;
        edge[0] = u;
        edge[1] = v;
        edges[i].push_back(edge);
    }
    cout << findRedundantConnection(edges);
    return 0;
}