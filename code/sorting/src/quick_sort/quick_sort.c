/*Part of Cosmos by OpenGenus Foundation*/

/* Implementation of QuickSort in C */
#include <stdio.h>

// A utility function to swap two elements
void swap(int *p, int *q)
{
	int temp = *p;
	*p = *q;
	*q = temp;
}


// In this function,
// Last element is used a pivot and the pivot element is placed at its correct position in sorted array,
// Elements smaller than pivot are placed to the left side of pivot
// Elements larger than pivot are placed to the right side of pivot
int partition(int a[], int low, int high)
{
	int pivot = a[high]; // pivot
	int i = (low - 1);  // Index of smaller element

	for (int j = low; j <= high- 1; j++)
	{
		// If current element is smaller than or equal to the pivot
		if (a[j] <= pivot)
		{
			i++; // increment index of smaller element
			swap(&a[i], &a[j]);
		}
	}
	swap(&a[i + 1], &a[high]);
	return (i + 1);
}

/* This function implements QuickSort
  a[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(int a[], int low, int high)
{
	if (low < high)
	{
		//k is pivot index
		int k = partition(a, low, high);

		// Separately sort elements before
    // partition and after partition
		quickSort(a, low, k - 1);
		quickSort(a, k + 1, high);
	}
}

/* Function to print an array */
void print(int a[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", a[i]);
	printf("\n");
}

// Main program to test above functions
int main()
{
	int n, i;
	printf("What is the size of the array?\n");
	scanf("%d",&n); // Input no. of elements in array
	int a[n];
	printf("Enter elements of the array one by one\n");

	// Input elements in the array
	for(i = 0; i < n; i++){
		scanf("\n%d",&a[i]);
	}

	// Calling quickSort function
	quickSort(a, 0, n - 1);
	printf("Sorted array: ");
	// Callling print function
	print(a, n);
	return 0;
}
