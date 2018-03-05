#include <iostream>
#include <vector>

class Graph 
{
	int ver_;
	std::vector<std::vector<int>> adj_;
	std::vector<std::vector<int>> centroidTree_;
	std::vector<int> sizes_;
	std::vector<bool> marked_;
    
	Graph(int num) : 
        ver_(num),
		adj_(num + 1, std::vector<int>),
		centroidTree_(num + 1, std::vector<int>),
		sizes_(num + 1),
		marked_(num + 1),	
    {}

	void addEdge(int x, int y, std::vector<std::vector<int>> &graph);
	void calcSizes(int cur, int par, std::vector<std::vector<int>> graph);
	int findCentroid(int cur, int par, int vertices);
	void decomposeTree(int cur, int total);
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
	arr[x].push_back(y);
}

void Graph::calcSizes(int cur, int par, std::vector<std::vector<int>> graph)
{
	sizes_[cur] = 1;
	for (const auto& to : graph[cur])
	{
		if (!(to == par || marked_[to] == true))
		{
			calcSizes (to, cur);
			sizes_[cur] += sizes_[to];
		}
	}
}

int Graph::findCentroid(int cur, int par, int vertices, std::vector<std::vector<int>> graph){
	for (const auto& to : graph[cur])
	{
		if (!(to == par || marked_[to] == true))
		{
			if (sizes[to] > vertices / 2)
			{
				return findCentroid(to, cur, vertices);
			}
		}
		return cur;
	}
}

void Graph::decomposeTree(int cur, int par, int total)
{
	calcSizes(cur, -1);
	int centroid = findCentroid(cur, -1, sizes[cur]);
	calcSizes(centroid, -1);
	marked_[centroid] = true;
	for (const auto& to : adj_[cur])
	{
		if(!(to == par || marked_[to] == true))
        	{
		    decomposeTree(to, cur, sizes[to]);
		    addEdge(cur, to, centroidTree);
        	}
	}
}
