#include <iostream>
#include <vector>

class Graph
{
public:
    int ver_;
    std::vector<std::vector<int>> adj_;
    std::vector<std::vector<int>> centroidTree_;
    std::vector<int> sizes_;
    std::vector<bool> marked_;
    Graph(int num) :
        ver_(num),
        adj_(num + 1),
        centroidTree_(num + 1),
        sizes_(num + 1),
        marked_(num + 1)
    {
    }

    void addEdge(int x, int y, std::vector<std::vector<int>> &graph);
    void calcSizes(int cur, int par, std::vector<std::vector<int>> graph);
    int findCentroid(int cur, int par, int vertices, std::vector<std::vector<int>> graph);
    void decomposeTree(int cur, int par, int total, int level,
                       std::vector<std::vector<int>> &Level);
};

void Graph::addEdge(int x, int y, std::vector<std::vector<int>> &graph)
{
    if (x < 0 || x > ver_)
    {
        throw std::out_of_range{"x is out of boundaries"};
    }
    if (y < 0 || y > ver_)
    {
        throw std::out_of_range{"y is out of boundaries"};
    }
    graph[x].push_back(y);
    graph[y].push_back(x);
}

void Graph::calcSizes(int cur, int par, std::vector<std::vector<int>> graph)
{
    sizes_[cur] = 1;
    for (const auto& to : graph[cur])
        if (!(to == par || marked_[to]))
        {
            calcSizes (to, cur, graph);
            sizes_[cur] += sizes_[to];
        }
}

int Graph::findCentroid(int cur, int par, int vertices, std::vector<std::vector<int>> graph)
{
    for (const auto& to : graph[cur])
        if (!(to == par || marked_[to]))
            if (sizes_[to] > vertices / 2)
                return findCentroid(to, cur, vertices, graph);

    return cur;
}

void Graph::decomposeTree(int cur, int par, int total, int level,
                          std::vector<std::vector<int>> &Level)
{
    calcSizes(cur, -1, adj_);
    int centroid = findCentroid(cur, -1, sizes_[cur], adj_);
    Level[level].push_back(centroid);
    calcSizes(centroid, -1, adj_);
    marked_[centroid] = true;
    for (const auto& to : adj_[centroid])
        if (!(to == par || marked_[to]))
        {
            decomposeTree(to, cur, sizes_[to], level + 1, Level);
            addEdge(cur, to, centroidTree_);
        }
}

void showOutput(std::vector<std::vector<int>> Level)
{
    for (int i = 1; Level[i].empty() == false; ++i)
    {
        std::cout << "Centroids of level " << i << ": ";
        bool more_than_1 = false;
        for (const auto& j : Level[i])
        {
            if (more_than_1 == true)
                std::cout << ", ";
            std::cout << j;
            more_than_1 = true;
        }
        std::cout << '\n';
    }
}

int main()
{
    std::vector<std::vector<int>> Level(8);
    Graph tree(7);
    tree.addEdge(1, 2, tree.adj_);
    tree.addEdge(1, 3, tree.adj_);
    tree.addEdge(2, 4, tree.adj_);
    tree.addEdge(4, 5, tree.adj_);
    tree.addEdge(4, 6, tree.adj_);
    tree.addEdge(2, 7, tree.adj_);
    tree.decomposeTree(1, -1, tree.ver_, 1, Level);
    showOutput(Level);
    return 0;
}
