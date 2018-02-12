#include <stdio.h>

// Part of Cosmos by OpenGenus Foundation
void insertion(int*, int);

int main()
{
	int n; // Number of elements
	printf("Enter number of elements to be sorted\n");
	scanf("%d", &n);
	int arr[n]; // Input array of size n
	printf("Enter the elements:\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d", &arr[i]); // Scanning each element of the array
	}
	insertion(arr, n); // calling insertion sort. The array is sorted in-place
	return 0;
}

void insertion(int arr[], int n)
{
	int key,j,i;
	for(i=1;i<n;i++) // We start from first element. Because one element is always sorted. 
	{
		key = arr[i];
		j = i-1;
		while(j>=0 && arr[j]>key) //Until we find the position of key
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
	
	for(i=0;i<n;i++) //printing the array
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

}
