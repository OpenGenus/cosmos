/*Part of Cosmos by OpenGenus Foundation*/

#include <stdio.h>
typedef int bool;
#define true 1
#define false 0

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
		for (j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
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

//printing sorted array
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
	printf("What is the size of the array?\n");//taking size of array as input from user
	scanf("%d",&n);
	int a[n];
	printf("Enter elements of the array one by one\n");//storing elements in array
	for(i = 0; i < n; i++){
		scanf("\n%d",&a[i]);
	}
	bubbleSort(a, n);
	printf("Sorted array: ");
	print(a, n);
	return 0;
}
