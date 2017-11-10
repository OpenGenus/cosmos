/*
 * From a given vertex in a weighted connected graph, find shortest 
 * paths to other vertices using Dijkstra's algorithm
 */

#include "stdio.h"

#define infinity 999
 
void dij(int n, int src, int cost[10][10], int dist[])
{
	int i, u, count, flag[10], min;
	for(i = 1; i <= n; i++)
		flag[i] = 0, dist[i] = cost[src][i];
	count = 2;
	while(count <= n)
	{
		min = 99;
		for(i = 1; i <= n; i++)
			if(dist[i] < min && !flag[i])
				min = dist[i], u = i;
		flag[u] = 1;
		count++;
		for(i = 1; i <= n; i++)
			if((dist[u] + cost[u][i] < dist[i]) && !flag[i])
				dist[i] = dist[u] + cost[u][i];
	}
}
 
void main()
{
	int n, src, i, j, cost[10][10], dist[10];
	printf("Enter the number of nodes:\n");
	scanf("%d",&n);
	printf("Enter the cost matrix:\n");
	for(i = 1; i <= n; i++)
		for(j = 1; j <= n; j++)
		{
			scanf("%d", &cost[i][j]);
			if(cost[i][j] == 0)
				cost[i][j] = infinity;
		}
	printf("Enter the source matrix:\n");
	scanf("%d", &src);
	dij(n, src, cost, dist);
	printf("Shortest path:\n");
	for(i = 1; i <= n; i++)
		if(i != src)
			printf("%d->%d,cost=%d\n", src, i, dist[i]);
}
