/*
 * Implement any scheme to find the optimal solution for the
 * Traveling Salesperson problem and then solve the same problem
 * instance using any approximation algorithm and determine
 * the error in the approximation.
 */


#include <stdio.h>

int a[10][10], visited[10], no, cost, sum, vs[10];
int 
least(int c)
{
	int i, nc = 999, min = 999, kmin;
	for(i = 1; i <= no; i++)
	{
		if((a[c][i] != 0) && (visited[i] == 0))
			if(a[c][i] < min)
			{
				min = a[i][1] + a[c][i];
				kmin = a[c][i];
				nc = i;
			}
	}
	if(min != 999)
		cost += kmin;
	return nc;
}

void 
tsp(int city)
{
	int ncity;
	visited[city] = 1;
	printf("%d ->",city);
	ncity = least(city);
	if(ncity == 999)
	{
		cost += a[city][1];
		printf("1\n");
		return;
	}
	tsp(ncity);
}

void 
nearest_n(int city)
{
	int min, j, i, u;
	vs[city] = 1;
	printf("%d -> ", city);
	u = city;
	for(j = 1; j <= no; j++)
	{
		min = 999;
		for (i = 0; i <= no; ++i)
			if((vs[i] == 0) && (a[city][i] != 0))
				if(a[city][i] < min)
				{
					min = a[city][i];
					u = i;
				}
		vs[u] = 1;
		if(min != 999)
		{
			sum += min;
			printf("%d -> ", u);
		}
		city = u;
	}
	printf("1\n");
	sum += a[u][1];
}

int 
main()
{
	int i, j;

	printf("Enter the No of Cities\n");
	scanf("%d", &no);

	printf("\nEnter the Adjacency Matrix\n");
	for(i = 1; i <= no; i++)
		for(j = 1; j <=no; j++)
			scanf("%d", &a[i][j]);

	printf("Using Dynamic Prog\n");
	tsp(1);
	printf("Cost is %d\n", cost);
	printf("Using approx method\n");
	nearest_n(1);
	printf("Cost is %d\n", sum);
	printf ("\nRatio is %f\n", (float)sum/cost);
	return 0;
}
