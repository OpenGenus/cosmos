#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <algorithm>
// Part of Cosmos by OpenGenus Foundation
using namespace std;

#define WHITE 0

#define MAXV 15

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef map<int, int> mii;

vii adjList[MAXV];

vector<string> v_names;

mii dfs_num;
mii dfs_low;
mii dfs_parent;

int dfsNumberCounter;
int dfsRoot;
int rootChildren;

bool articulation_vertex[MAXV];

void articulation(int u)
{
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++;

    for (vii::iterator it = adjList[u].begin(); it != adjList[u].end(); it++)
    {
        if (dfs_num[it->first] == WHITE)
        {
            dfs_parent[it->first] = u;

            if (u == dfsRoot)
                rootChildren++;

            articulation(it->first);

            if (dfs_low[it->first] >= dfs_num[u]) // Articulation check
                articulation_vertex[u] = true;

            if (dfs_low[it->first] > dfs_num[u]) // Bridge check
                cout << "Bridge: (" << u << "," << it->first << ") " << endl;

            dfs_low[u] = min(dfs_low[u], dfs_low[it->first]);

        }
        else if (it->first != dfs_parent[u])
            dfs_low[u] = min(dfs_low[u], dfs_num[it->first]);

    }
}

int main()
{
    int V, E, X, Y;

    cin >> V >> E;

    for (int i = 0; i < E; i++)
    {
        cin >> X >> Y;

        adjList[X].push_back(make_pair(Y, 0));
        adjList[Y].push_back(make_pair(X, 0));
    }

    for (int i = 0; i < V; i++)
        if (dfs_num[i] == WHITE)
        {
            dfsRoot = i;
            rootChildren = 0;
            articulation(i);

            // Special case where the initial vertex is articulation
            articulation_vertex[dfsRoot] = (rootChildren > 1);
        }

    cout << "Articulation Points: " << endl;
    for (int i = 0; i < V - 1; i++)
        if (articulation_vertex[i])
            cout << "Vertex: " << i << endl;

    return 0;
}
