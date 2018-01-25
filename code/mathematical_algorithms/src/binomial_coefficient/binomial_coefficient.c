#include <stdio.h>

long long int a[101][101];

void
pascal()
{
	int i, j;
	
	for (i = 0; i < 101; i++) {
		for (j = 0; j <= i; j++) {
			if (j == 0 || j == i)
				a[i][j] = 1;
			
			else
				a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
		}
	}
}

int
main()
{
	int n, r;
	
	printf("Enter n: ");
	scanf("%d", &n);
	
	printf("Enter r: ");
	scanf("%d", &r);
	
	pascal();
	printf("%dC%d = %lli\n", n, r, a[n][r]);
		
	return (0);
}
