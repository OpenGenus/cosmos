#include <iostream>
#include <vector>

using namespace std;

class Graph 
{
private:
	int ver;
	vector<int>* adj;
	vector<int>* centroidTree;
	int* sizes;
	bool* deleted;
public:
	Graph(int num) : ver(num) {
		adj = new vector<int>(ver + 1);
		centroidTree = new vector<int>(ver + 1);
		sizes = new int[ver + 1];
		deleted = new bool[ver + 1];	
	}
	
	~Graph();
	
	void addEdge(int x, int y, vector<int> arr[]);

	void calcSizes(int cur, int par);

	int findCentroid(int cur, int par, int vertices);

	void decomposeTree(int cur, int total);
};

Graph::~Graph()
{
	delete []adj;
	delete []sizes;
	delete []deleted;
}

void Graph::addEdge(int x, int y, vector<int> arr[])
{
	arr[x].push_back(y);
}

void Graph::calcSizes(int cur, int par)
{
	sizes[cur] = 1;
	for (int i = 0; i < adj[cur].size(); ++ i)
	{
		int to = adj[cur][i];
		if (!(to == par || deleted[to] == true))
		{
			calcSizes (to, cur);
			sizes[cur] += sizes[to];
		}
	}
}

int Graph::findCentroid(int cur, int par, int vertices){
	for (int i = 0; i < adj[cur].size(); ++ i)
	{
		int to = adj[cur].size();
		if (!(to == par || deleted[to] == true))
		{
			if (sizes[to] > vertices / 2)
			{
				return findCentroid(to, cur, vertices);
			}
		}
		return cur;
	}
}

void Graph::decomposeTree(int cur, int total)
{
	calcSizes (cur, -1);
	int centroid = findCentroid (cur, -1, sizes[cur]);
	calcSizes (centroid, -1);
	deleted[centroid] = true;
	for (int i = 0; i < adj[centroid].size(); ++ i)
	{
		int to = adj[centroid][i];
		if (deleted[to] == true) continue;
		decomposeTree(to, sizes[to]);
		addEdge(cur, to, centroidTree);
	}
}

int main()
{
	return 0;	
}
