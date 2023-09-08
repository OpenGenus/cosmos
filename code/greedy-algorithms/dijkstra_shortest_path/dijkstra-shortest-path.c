#include <stdio.h>
#include <limits.h>

/* Number of vertices in the graph */
#define V 9

/* A utility function to find the vertex with minimum distance
 value, from the set of vertices not yet included in shortest
 path tree
 */
int minDistance(int dist[], bool sptSet[])
{
	/* Initialize min value*/
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return (min_index);
}

/* Function to print shortest path from source to j
 using parent array*/
void printPath(int parent[], int j)
{
	
	if (parent[j]==-1)
		return;

	printPath(parent, parent[j]);

	printf("%d ", j);
}

/* A utility function to print the constructed distance
 array*/
int printSolution(int dist[], int n, int parent[])
{
	int src = 0;
	printf("Vertex\t Distance\tPath");
	for (int i = 1; i < V; i++)
	{
		printf("\n%d -> %d \t\t %d\t\t%d ", src, i, dist[i], src);
		printPath(parent, i);
	}
}

/* Funtion that implements Dijkstra's single source shortest path
 algorithm for a graph represented using adjacency matrix
 representation*/
void dijkstraAlgo(int graph[V][V], int src)
{
	int dist[V]; 


	bool sptSet[V];


	int parent[V];


	for (int i = 0; i < V; i++)
	{
		parent[0] = -1;
		dist[i] = INT_MAX;
		sptSet[i] = false;
	}

	dist[src] = 0;

	for (int count = 0; count < V-1; count++)
	{
		
		int u = minDistance(dist, sptSet);

	
		sptSet[u] = true;

	
		for (int v = 0; v < V; v++)

		
			if (!sptSet[v] && graph[u][v] &&
				dist[u] + graph[u][v] < dist[v])
			{
				parent[v] = u;
				dist[v] = dist[u] + graph[u][v];
			} 
	}

	printSolution(dist, V, parent);
}

/* driver program to test above function*/
int main()
{
	/* Let us create the example graph discussed above */
	int graph[V][V];
  for(int i=0;i<V;i++)
  {
    for(int j=0;j<V;j++)
    {
     scanf("%d",&graph[i][j]);
    }
  }  
	dijkstraAlgo(graph, 0);

	return (0);
}
