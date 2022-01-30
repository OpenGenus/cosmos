#include <stdio.h>

void
swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int
partition(int arr[], int low, int high)
{
    int pivot = arr[high];   
    int i = (low - 1);  
 
    for (int j = low; j <= high- 1; j++) {
        if (arr[j] <= pivot) {
            i++;   
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void
quickSort(int arr[], int low, int high)
{
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

float
median(int n, int arr[n])
{
	if (n % 2 != 0)
		return (float)arr[n / 2];

	return ((float)(arr[(n - 1) / 2] + arr[n / 2]) / 2.0);
}

int
main()
{
	int n;
	printf("Enter size of the Array\n");
	scanf("%d",&n);
	int arr[n];
	printf("Enter %d integers\n",n);
	for (int i = 0; i < n; i++)
		scanf("%d",&arr[i]);
	quickSort(arr,0,n - 1);
	printf("Median = %f\n",median(n,arr));

	return (0);
}