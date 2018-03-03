#include <iostream>
#include <list>

using namespace std;

struct Graph 
{
	int V;
	list<int> *adj;
	int *size;
	bool *deleted;

	Graph (int num) : V(num) {
		adj = new list<int>[V];
		size = new int[V];
		deleted = new bool[V];	
	}

	void addEdge (int x, int y);

	void calcSizes (int cur, int par);

	int findCentroid (int cur, int par, int vertices);

	void decomposeTree (int cur, int total);
};

void Graph::addEdge (int x, int y)
{
	adj[x].push_back(y);
}

void Graph::calcSizes (int cur, int par)
{
	size[cur] = 1;
	list<int>::iterator i;
	for (i = adj[cur].begin(); i != adj[cur].end(); ++ i)
	{
		if (*i == par || deleted[*i] == true) continue;
		calcSizes (*i, cur);
		size[cur] += size[*i];
	}
}

int Graph::findCentroid (int cur, int par, int vertices){
	list<int>::iterator i;
	for (i = adj[cur].begin(); i != adj[cur].end(); ++ i)
	{
		if (*i == par || deleted[*i] == true) continue;
		if (size[*i] > vertices / 2)
		{
			return findCentroid (*i, cur, vertices);
		}
	}
	return cur;
}

void Graph::decomposeTree (int cur, int total)
{
	calcSizes (cur, -1);
	int centroid = findCentroid (cur, -1, size[cur]);
	calcSizes (centroid, -1);
	deleted[centroid] = true;
	list<int>::iterator i;
	for(i = adj[centroid].begin(); i != adj[centroid].end(); ++ i)
	{
		if (deleted[*i] == true) continue;
		decomposeTree(*i, size[*i]);
	}
}
