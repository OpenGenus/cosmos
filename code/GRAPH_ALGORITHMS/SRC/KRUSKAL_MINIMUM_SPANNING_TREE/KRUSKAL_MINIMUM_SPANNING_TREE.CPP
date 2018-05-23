#include <iostream>
#include <vector>
#include <algorithm>
// Part of Cosmos by OpenGenus Foundation

int n, dj[100], rank[100]; //disjoint set
int findset(int a)
{
    if (dj[a] != a)
        return dj[a] = findset(dj[a]);
    else
        return a;
}
bool sameset(int a, int b)
{
    return findset(a) == findset(b);
}
void unionset(int a, int b)
{
    int x = findset(a), y = findset(b);
    if (rank[x] > rank[y])
        dj[y] = x;
    else
    {
        dj[x] = y;
        if (rank[x] == rank[y])
            rank[y]++;
    }
}

int main()
{
    using namespace std;
    int e, u, v, w;
    vector< pair<int, pair<int, int>>> edge;      //(weight, two vertices that the edge connects)
    for (int i = 0; i < n; i++)
    {
        dj[i] = i;
        ::rank[i] = 0;
    }
    cout << "Input Number of Edges" << endl;
    cin >> e;
    cout << "Input Edges (weight and then two vertices that the edge connects)" << endl;
    for (int i = 0; i < e; i++)
    {
        cin >> u >> v >> w;   //u,v,w are just temporary variables
        edge.push_back({u, {v, w}});
    }
    sort(edge.begin(), edge.end());    //sort by edge weight
    int mst = 0;
    for (int i = 0; i < e; i++)
    {
        int x = edge[i].second.first, y = edge[i].second.second;
        if (!sameset(x, y))
        {
            mst += edge[i].first;
            unionset(x, y);
        }
    }
    cout << mst << endl;
}
