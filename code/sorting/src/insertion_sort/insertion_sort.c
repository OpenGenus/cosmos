#include <stdio.h>

// Part of Cosmos by OpenGenus Foundation
void insertionsort(int*, int);

int main()
{
	int n;
	scanf("%d", &n);
	int arr[n];
                  // input the array
	for(int i=0;i<n;i++)
	{
		scanf("%d", &arr[i]);
	}
	insertionsort(arr, n);
	return 0;
}
void insertionsort(int arr[], int n)
{
	int key;
	int j;
	for(int i=1;i<n;i++)
	{
		key = arr[i];
		j = i-1;
		/* Shift elements of arr[0..i-1], that are  
                   greater than key, to one position ahead  
                   of their current position */
		while(j>=0 && arr[j]>key)
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
                  // print the array
	for(int i=0;i<n;i++)
	{
		printf("%d\t", arr[i]);
	}
	printf("\n");

}
