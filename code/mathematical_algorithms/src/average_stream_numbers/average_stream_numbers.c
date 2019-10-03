#include <stdio.h>

float 
getAvg(float prev_avg, int x, int n)
{
	return (((prev_avg * n) + x) / (n + 1));
}

void
streamAvg(float arr[], int n)
{

	float avg = 0;
	for (int i = 0; i < n; i++) {
		avg = getAvg(avg, arr[i], i);
		printf("Average of %d numbers is %f \n", i + 1, avg);
	}
}

int
main()
{
	int n;
	printf("Enter Array Size \n");
	scanf("%d", &n);
	
	float arr[n];
	printf("Enter %d Integers \n", n);
	
	for (int i = 0; i < n; i++)
		scanf("%f", &arr[i]);
	
	streamAvg(arr, n);

	return (0);
}
