/*Part of Cosmos by OpenGenus Foundation*/
#include <stdio.h>

void swap(int *p, int *q)
{
	int temp = *p;
	*p = *q;
	*q = temp;
}


//Last element is used a spivot
//Places elements smaller than pivot to its left side
//Places elements larger than pivot to its right side
int partition(int a[], int low, int high)
{
	int pivot = a[high];
	int i = (low - 1);  

	for (int j = low; j <= high- 1; j++)
	{
		if (a[j] <= pivot)
		{
			i++;
			swap(&a[i], &a[j]);
		}
	}
	swap(&a[i + 1], &a[high]);
	return (i + 1);
}

void quickSort(int a[], int low, int high)
{
	if (low < high)
	{
		int k = partition(a, low, high);
		//k is pivot index

		quickSort(a, low, k - 1);
		quickSort(a, k + 1, high);
	}
}
void print(int a[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", a[i]);
	printf("\n");
}

int main()
{   
	int n, i;
	printf("What is the size of the array?\n");
	scanf("%d",&n);
	int a[n];
	printf("Enter elements of the array one by one\n");

	for(i = 0; i < n; i++){
		scanf("\n%d",&a[i]);
	}    

	quickSort(a, 0, n - 1);
	printf("Sorted array: ");
	print(a, n);
	return 0;
}
