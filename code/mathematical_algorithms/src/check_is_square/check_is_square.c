#include <stdio.h>
#include <math.h>

int
main()
{
	int n, sqrt_n;
	scanf("%d", &n);
	sqrt_n = sqrt(n);
	
	if (sqrt_n * sqrt_n == n) 
		printf("Natural Square number \n");
	else
		printf("Not a Natural Square \n");

	return (0);
}