#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void
swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void
shuffle_array(int arr[], int n)
{
	srand(time(NULL));

	int i;
	for (i = n - 1; i > 0; i--) {
		int j = rand() % (i + 1);
		swap(&arr[i], &arr[j]);
	}

	for (i = 0; i < n; i++)
		printf("%d ",arr[i]);
	printf("\n");
}

int
main()
{
	int arr[] = {1 ,2, 3, 4, 5, 6, 7, 8};
	int n = sizeof(arr) / sizeof(arr[0]);
	shuffle_array(arr, n);

	return (0);
}
