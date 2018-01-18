#include <stdio.h>

int 
kadanesAlgorithm(int a[], int n)
{
	int max_so_far = 0, max_ending_here = 0;
	int i;
	for (i = 0; i < n; ++i) {
	    max_ending_here = max_ending_here + a[i];

	    if (max_so_far < max_ending_here)
	        max_so_far = max_ending_here;
	
	    if (max_ending_here < 0)
	        max_ending_here = 0;
	}
	return (max_so_far);
}

int 
main()
{
	int n;
	printf("Enter size of Array: ");
	scanf("%d", &n);

	int a[n];
	printf("Enter %d Integers \n", n);
	int i;
	for (i = 0; i < n; ++i)
		scanf("%d", &a[i]);

	printf("Largest Contiguous Subarray Sum: %d \n", kadanesAlgorithm(a, n));

	return (0);
}
