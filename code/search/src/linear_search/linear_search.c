#include <stdio.h>
/*
 * Part of Cosmos by OpenGenus Foundation
*/

/*
 * Input: an integer array with size in index 0, the element to be searched
 * Output: if found, returns the index of the element else -1
*/
int search(int arr[], int size, int x)
{
	int i=0;
	for (i=0; i<size; i++)
	{
		if (arr[i] == x) // Comparing each element with the element to be found
		    return i;	// If element found returns it's index
	}
	return -1; // else returns -1
}


int main()
{
		int n; // No. of elements in the array
		scanf("%d",&n); // Input the no. of elements in the array
		int arr[n]; // Declaring an array with n elements 
		for(int i=0;i<n;i++)
		{
			scanf("%d ",&arr[i]); // Input array elements
		}
    int find; // Element to be found
		scanf("%d",&find);
		int  index = search(arr,n,find); // Calling the search function
		if(index == -1) // If element not found
		{
				printf("Element not found\n");
		}
		else // If element found then print it's index in the array
		{
				printf("Position of %d is %d\n", find, index);
		}
		return 0;
}
