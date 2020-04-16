/*Part of Cosmos by OpenGenus Foundation*/

/* Implementation of bubbleSort in C */
#include <stdio.h>
typedef int bool;
#define true 1
#define false 0

// Function to swap two values
void swap(int *p, int *q)
{
	int temp = *p;
	*p = *q;
	*q = temp;
}

/*Sorting an array a[] consisting of n
  elements with bubble sort method*/
void bubbleSort(int a[], int n)
{
	int i, j;
	bool swapped;
	for (i = 0; i < n - 1; i++)
	{
		swapped = false;
		 // Last i elements are already in place
		for (j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1]) // Comparing adjacent elements
			{
				swap(&a[j], &a[j + 1]);
				swapped = true;
			}
		}


		if (swapped == false)
			break;/*break if array is sorted
					i.e. no swapping possible*/
	}
}

// Function to print an array
void print(int a[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", a[i]);
	printf("\n");
}


// Main function
int main()
{
	int n, i;
	printf("What is the size of the array?\n");
	scanf("%d",&n); // Input the no. of elements in the array
	int a[n];
	printf("Enter elements of the array one by one\n"); // Input the elements of the array
	for(i = 0; i < n; i++){
		scanf("\n%d",&a[i]);
	}
	bubbleSort(a, n); // Calling bubbleSort function
	printf("Sorted array: ");
	print(a, n); // Calling the print function
	return 0;
}
