#include <stdio.h>

int 
DelannoyGenerator(int m, int n)
{
	int d = 1;
	if ((m == 0) || (n == 0))
		d = 1;
	else
		d = DelannoyGenerator(m - 1, n) + DelannoyGenerator(m, n - 1) + DelannoyGenerator(m - 1, n - 1);
	
	return (d);
}

int 
main()
{
	int m, n, result = 0;
	
	printf("Enter m value: ");
	scanf("%d", &m);

	printf("Enter n value: ");
	scanf("%d", &n);
		
	result = DelannoyGenerator(m, n);
	printf("Delannoy Number of (%d,%d) is %d \n", m, n, result);
	
	return (0);
}
