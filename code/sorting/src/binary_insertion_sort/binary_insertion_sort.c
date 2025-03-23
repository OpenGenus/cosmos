#include <stdio.h> 
/* Binary Insertion sort is used to find index to place element in array. */
/* It has less complexity as compared to Insertion sort */
int BinarySearch(int l[], int value, int start, int end) 
{ 
	/* l is the array that is to be sorted */
	/* Value variable contains elements from array that is to be inserted */
	/* start variable contains the index of first element from unsorted array */
	/* end variable stores index of last element from unsorted array */
	if (end <= start) 
		return ((value > l[start]) ? (start + 1) : start); 
	/* m contains the middle element index of an array */
	int m = (start + end)/2; 
	/* To check if selected element is equal to middle element in array */
	if(value == l[m])
		return (m + 1); 
	/* To check if selected element is greater than the middle element in array */
	if(value > l[m])
		return (BinarySearch(l, value, m + 1, end));
	return (BinarySearch(l, value, start, m - 1));
} 

/* InsetionSort Funciton is used to sort an array l of size n */
void InsertionSort(int l[], int n) 
{ 	
	/* l argument contains unsorted array */
	/* n is the length of array */
	int i, loc, j, k, value; 
	/* for loop traverses the unsorted array */
	for (i = 1; i < n; ++i) 
	{ 
		j = i - 1; 
		value = l[i]; 

		/* BinarySearch Function is called to find the index in an array */
		loc = BinarySearch(l, value, 0, j); 

		/* Elements are shifted to their indexes */
		while (j >= loc) 
		{ 
			l[j + 1] = l[j]; 
			j--; 
		} 
		l[j + 1] = value; 
	} 
} 

/* Main Program to create a list of elements to be sorted */
int main() 
{ 
	int l[] = {37, 23, 0, 17, 12, 72, 31, 46, 100, 88, 54}; 
	/* n is the length of the unsorted array */
	int n = sizeof(l)/sizeof(l[0]); 

	InsertionSort(l, n); 
	/* for loop displays the sorted array elements */
	printf("Sorted array: "); 
	for (int i = 0; i < n; ++i) 
		printf("%d ",l[i]); 

	return (0); 
} 
/* Sorted array: 0 12 17 23 31 37 46 54 72 88 100 */
