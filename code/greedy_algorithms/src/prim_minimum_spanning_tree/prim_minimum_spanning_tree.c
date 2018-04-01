#include <stdio.h>
#include <limits.h>

int 
find_min_edge(int *k, int *l, int n, int c[][1024], int *e)
{
	int min = INT_MAX;
	int i, j;
	for (i = 0; i < n; ++i)
		for (j = 0; j < n; ++j)
			if (c[i][j] < min) {
				min = c[i][j];
				*k = i;
				*l = j;
			}
	*e = *e - 1;
	return (min);
}

int 
find_new_index(int c[][1024], int near[], int n, int *e)
{
	int min=INT_MAX, index;
	int i;
	for (i = 0; i < n; ++i)
		if (near[i] != 0 && c[i][near[i]] < min) {
			min = c[i][near[i]];
			index = i;

		}
	*e = *e - 1;
	return (index);
}

int 
main()
{
	int n;
	printf("Enter number of nodes in graph: ");
	scanf("%d", &n);

	int e = n * (n - 1);
	int c[n][1024];
	printf("Enter cost matrix: \n");
	int i, j;
	for (i = 0; i < n; ++i)
		for (j = 0; j < n; ++j) {
			scanf("%d", &c[i][j]);
			if (c[i][j] == -1) {
				c[i][j] = INT_MAX;
				--e;
			}
		}
	e = e / 2;
			
	int t[n - 1][2];  //output edges
	int near[n];
	int k, l;
	int mincost = 0;
	
	mincost += find_min_edge(&k, &l, n, c, &e);
	t[0][0] = k;
	t[0][1] = l;

	for (i = 0; i < n; ++i) {
		if (c[i][l] < c[i][k])
			near[i] = l;
		else
			near[i] = k;
	}
	near[k] = near[l] = 0;

	for (i = 1; i < n - 1, e > 0; ++i) {
		int index = find_new_index(c, near, n, &e);
		t[i][0] = index;
		t[i][1] = near[index];
		mincost += c[index][near[index]];
		near[index] = 0;

		int k; 
		for (k = 0; k < n; ++k)
			if (near[k] != 0 && c[k][near[k]] > c[k][index])
				near[k] = index;
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
