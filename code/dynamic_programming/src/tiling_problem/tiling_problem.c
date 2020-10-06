#include <stdio.h>

long long int 
tiling(int n)
{
	long long int tile[n + 1];
	int i;
	
	tile[0] = 1;
	tile[1] = 1;
	tile[2] = 2;

	for (i = 3; i <= n; i++)
		tile[i] = tile[i - 1] + tile[i - 2];

	return (tile[n]);
}

int 
main()
{   
	int n;
	printf("Enter Number of tiles: ");
	scanf("%d", &n);
	printf("Number of ways to arrange tiles is %lli \n", tiling(n));

	return (0);
}
