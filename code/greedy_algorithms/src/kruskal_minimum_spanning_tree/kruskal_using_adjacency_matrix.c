#include <stdio.h>
#include <limits.h>

int 
delete_min_edge(int *u, int *v, int c[][1024], int n, int *e)
{
	int min = INT_MAX;
	int i, j;

	for (i = 0; i < n; ++i)
		for (j = 0; j < n; ++j)
			if (c[i][j] < min && c[i][j] != -1) {
				min = c[i][j];
				*u = i;
				*v = j;
			}

	c[*u][*v] = -1;
	*e = *e - 1;
	return (min);
}

int 
find(int n, int parent[], int i)
{
	while (parent[i] >= 0)
		i = parent[i];

	return (i);
}

void 
Union(int n, int parent[], int p, int q)
{
	int temp = parent[p] + parent[q];
	if (parent[p] > parent[q]) {
		parent[p] = q;
		parent[q] = temp;
	}
	else {
		parent[q] = p;
		parent[p] = temp;	
	}
}

int 
main()
{
	int n;
	int e = 0;
	printf("Enter number of nodes in graph: ");
	scanf("%d", &n);   

	int c[n][1024];
	printf("Enter cost matrix: \n");
	int i, j;
	for (i = 0; i < n; ++i)
		for (j = 0; j < n; ++j) {
			scanf("%d", &c[i][j]);
			if (c[i][j] != -1)
				++e;
		}

	e = e / 2;
	int t[n - 1][2];
	int parent[n];
	for (i = 0; i < n; i++)
		parent[i] = -1;
	
	int mincost = 0;
	int u, v, p, q;
	i = 0;
	while (i < n - 1 && e > 0) {
		int min = delete_min_edge(&u, &v, c, n, &e);
		p = find(n, parent, u);
		q = find(n, parent, v);
		if (p != q) {
			
			t[i][0] = u;
			t[i][1] = v;
			++i;
			mincost += min;
			Union(n, parent, p, q);
		}
	}
	
	if(i != n - 1)
		printf("There is no spanning tree\n");
	else {
		printf("Minimum Spanning Tree:- \n");

		for (i = 0; i < n - 1; ++i)
			printf("%d----%d \n", t[i][0], t[i][1]);

		printf("Mincost: %d \n", mincost);
	}
}
