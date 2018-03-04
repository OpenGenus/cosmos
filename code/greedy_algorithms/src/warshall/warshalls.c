/*
 * Compute the transitive closure of a given directed graph
 * using Warshall's algorithm.
 */

#include <stdio.h>
#include <math.h>

#define max(a, b) (a > b ? a : b)

void 
warshal(int p[10][10], int n)
{
	int i, j, k; 
	for(k = 1; k <= n; k++)
		for(i = 1; i <= n; i++)
			for(j = 1; j <= n; j++)
				p[i][j] = max(p[i][j], p[i][k] && p[k][j]); 
}

int 
main()
{
	int p[10][10] = {0}, n, i, j; 
	printf("Enter the size of matrix\n");
	scanf("%d", &n);

	printf ("Enter the Adjacency matrix\n");
	for(i = 1; i <= n; i++)
		for(j = 1; j <= n; j++)
			scanf("%d", p[i][j]);

	warshal(p, n); 
	printf("\n Transitive closure: \n"); 
	for(i = 1; i <= n; i++) {
		for(j = 1; j <= n; j++)
			printf("%d\t", p[i][j]); 
		printf("\n"); 
	}
	return (0);
}
