/* Part of Cosmos by OpenGenus Foundation */

#include <stdio.h>

void insertion(int*, int);

int main()
{
	// n total no 
	int n;
	
	printf("how many no.\n");
	scanf("%d", &n);
	printf("enter the no. want to sort\n");
	// array name a[]
	int arr[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d", &arr[i]);
	}
	// recursion call here 
	insertion(arr, n);
	return 0;
}

void insertion(int arr[], int n)
{
	int key;
	int j;
	for(int i=1;i<n;i++)
	{
		key = arr[i];
		j = i-1;
		
		while(j>=0 && arr[j]>key)
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
	
	for(int i=0;i<n;i++)
	{
		printf("%d\t", arr[i]);
	}
	printf("\n");

}
