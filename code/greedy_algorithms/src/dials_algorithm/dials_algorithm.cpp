// C++ Program for Dijkstra's dial implementation
#include<bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f

// This class represents a directed graph using
// adjacency list representation
class Graph
{
	int V; // No. of vertices

	// In a weighted graph, we need to store vertex
	// and weight pair for every edge
	list< pair<int, int> > *adj;

public:
	Graph(int V); // Constructor

	// function to add an edge to graph
	void addEdge(int u, int v, int w);

	// prints shortest path from s
	void shortestPath(int s, int W);
};

// Allocates memory for adjacency list
Graph::Graph(int V)
{
	this->V = V;
	adj = new list< pair<int, int> >[V];
}

// adds edge between u and v of weight w
void Graph::addEdge(int u, int v, int w)
{
	adj[u].push_back(make_pair(v, w));
	adj[v].push_back(make_pair(u, w));
}

// Prints shortest paths from src to all other vertices.
// W is the maximum weight of an edge
void Graph::shortestPath(int src, int W)
{
	/* With each distance, iterator to that vertex in
	its bucket is stored so that vertex can be deleted
	in O(1) at time of updation. So
	dist[i].first = distance of ith vertex from src vertex
	dits[i].second = iterator to vertex i in bucket number */
	vector<pair<int, list<int>::iterator> > dist(V);

	// Initialize all distances as infinite (INF)
	for (int i = 0; i < V; i++)
		dist[i].first = INF;

	// Create buckets B[].
	// B[i] keep vertex of distance label i
	list<int> B[W * V + 1];

	B[0].push_back(src);
	dist[src].first = 0;

	//
	int idx = 0;
	while (1)
	{
		// Go sequentially through buckets till one non-empty
		// bucket is found
		while (B[idx].size() == 0 && idx < W*V)
			idx++;

		// If all buckets are empty, we are done.
		if (idx == W * V)
			break;

		// Take top vertex from bucket and pop it
		int u = B[idx].front();
		B[idx].pop_front();

		// Process all adjacents of extracted vertex 'u' and
		// update their distanced if required.
		for (auto i = adj[u].begin(); i != adj[u].end(); ++i)
		{
			int v = (*i).first;
			int weight = (*i).second;

			int du = dist[u].first;
			int dv = dist[v].first;

			// If there is shorted path to v through u.
			if (dv > du + weight)
			{
				// If dv is not INF then it must be in B[dv]
				// bucket, so erase its entry using iterator
				// in O(1)
				if (dv != INF)
					B[dv].erase(dist[v].second);

				// updating the distance
				dist[v].first = du + weight;
				dv = dist[v].first;

				// pushing vertex v into updated distance's bucket
				B[dv].push_front(v);

				// storing updated iterator in dist[v].second
				dist[v].second = B[dv].begin();
			}
		}
	}

	// Print shortest distances stored in dist[]
	printf("Vertex Distance from Source\n");
	for (int i = 0; i < V; ++i)
		printf("%d	 %d\n", i, dist[i].first);
}

// Driver program to test methods of graph class
int main()
{
	// create the graph given in above fugure
	int V = 9;
	Graph g(V);

	// making above shown graph
	g.addEdge(0, 1, 4);
	g.addEdge(0, 7, 8);
	g.addEdge(1, 2, 8);
	g.addEdge(1, 7, 11);
	g.addEdge(2, 3, 7);
	g.addEdge(2, 8, 2);
	g.addEdge(2, 5, 4);
	g.addEdge(3, 4, 9);
	g.addEdge(3, 5, 14);
	g.addEdge(4, 5, 10);
	g.addEdge(5, 6, 2);
	g.addEdge(6, 7, 1);
	g.addEdge(6, 8, 6);
	g.addEdge(7, 8, 7);

	// maximum weighted edge - 14
	g.shortestPath(0, 14);

	return 0;
}

