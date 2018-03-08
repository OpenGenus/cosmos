#include <iostream>
#include <vector>

class Graph 
{
    int ver_;
    std::vector<std::vector<int>> adj_;
    std::vector<std::vector<int>> centroidTree_;
    std::vector<int> sizes_;
    std::vector<bool> marked_;
    public:
        Graph(int num) :
            ver_(num),
            adj_(num + 1),
            centroidTree_(num + 1),
            sizes_(num + 1),
            marked_(num + 1)	
            {}

        void addEdge(int x, int y, std::vector<std::vector<int>> &graph);
        void calcSizes(int cur, int par, std::vector<std::vector<int>> graph);
        int findCentroid(int cur, int par, int vertices, std::vector<std::vector<int>> graph);
        void decomposeTree(int cur, int par, int total, std::vector<std::vector<int>> graph);
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
}

void Graph::calcSizes(int cur, int par, std::vector<std::vector<int>> graph)
{
    sizes_[cur] = 1;
    for (const auto& to : graph[cur])
    {
        if (!(to == par || marked_[to] == true))
        {
            calcSizes (to, cur, graph);
            sizes_[cur] += sizes_[to];
        }
    }
}

int Graph::findCentroid(int cur, int par, int vertices, std::vector<std::vector<int>> graph){
    for (const auto& to : graph[cur])
    {
        if (!(to == par || marked_[to] == true))
        {
            if (sizes_[to] > vertices / 2)
            {
                return findCentroid(to, cur, vertices, graph);
            }
        }
        return cur;
    }
}

void Graph::decomposeTree(int cur, int par, int total, std::vector<std::vector<int>> graph)
{
    calcSizes(cur, -1, graph);
    int centroid = findCentroid(cur, -1, sizes_[cur], graph);
    calcSizes(centroid, -1, graph);
    marked_[centroid] = true;
    for (const auto& to : adj_[cur])
    {
        if(!(to == par || marked_[to] == true))
        {
            decomposeTree(to, cur, sizes_[to], graph);
            addEdge(cur, to, centroidTree_);
        }
    }
}
