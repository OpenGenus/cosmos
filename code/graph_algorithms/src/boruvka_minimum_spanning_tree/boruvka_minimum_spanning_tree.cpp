#include <iostream>
#include <vector>

const int MAXN = 10000;
const int inf = 0x3fffffff;

int nodeCount, edgesCount;
std::vector<std::pair<int, int>> graf[MAXN];

void readGraph()
{
    std::cin >> nodeCount >> edgesCount;
    for (int i = 0; i < edgesCount; i++)
    {
        int x, y, w;
        std::cin >> x >> y >> w;
        graf[x].push_back({y, w});
        graf[y].push_back({x, w});
    }
}

int parent[MAXN], rank[MAXN];
// Initialize the forest of trees
void initDisjoint()
{
    for (int i = 0; i < nodeCount; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}

// Get set representative
int getSR(int x)
{
    if (x == parent[x])
        return x;
    return parent[x] = getSR(parent[x]);
}

int areUnited(int x, int y)
{
    return getSR(x) == getSR(y);
}

void unite(int x, int y)
{
    x = getSR(x);
    y = getSR(y);
    if (rank[x] > rank[y])
        parent[y] = x;
    else
    {
        parent[x] = y;
        if (rank[x] == rank[y])
            rank[y]++;
    }
}

std::pair<int, int> cheapEdge[MAXN];
int solve()
{
    int numberOfTrees = nodeCount;
    int weightSum = 0;
    initDisjoint();

    while (numberOfTrees > 1)
    {
        // initializing cheapest edge to "none"
        for (int i = 0; i < nodeCount; i++)
            cheapEdge[i].first = -1;
        for (int i = 0; i < nodeCount; i++)
            for (size_t j = 0; j < graf[i].size(); j++)
            {
                std::pair<int, int> edge = graf[i][j];
                int xsr = getSR(i);
                int ysr = getSR(edge.first);
                int w = edge.second;
                if (xsr == ysr)
                    continue;
                if (cheapEdge[xsr].first == -1 ||
                    w < graf[cheapEdge[xsr].first][cheapEdge[xsr].second].second)
                    cheapEdge[xsr] = {i, j};
                if (cheapEdge[ysr].first == -1 ||
                    w < graf[cheapEdge[ysr].first][cheapEdge[ysr].second].second)
                    cheapEdge[ysr] = {i, j};
            }
        for (int i = 0; i < nodeCount; i++)
        {
            int xsr = getSR(i);
            if (cheapEdge[xsr].first == -1)
                continue;
            std::pair<int, int> edge = graf[cheapEdge[xsr].first][cheapEdge[xsr].second];
            int ysr = getSR(edge.first);
            if (xsr == ysr)
                continue;
            weightSum += edge.second;
            unite(xsr, ysr);
            numberOfTrees--;
        }
    }

    return weightSum;
}

int main()
{
    readGraph();
    int weight = solve();
    std::cout << "The weight of the minimum spanning tree is " << weight;
    return 0;
}
