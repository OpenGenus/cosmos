/*Part of Cosmos by OpenGenus Foundation*/

#include <stdio.h>  //pre-defined libraries
typedef int bool;
#define true 1 
#define false 0 

void swap(int *p, int *q) //Swap function
{
	int temp = *p;//Swapping position of two variable with respect to a third one
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
			if (a[j] > a[j + 1])//Condition check to see if greater than swap their position
			{
				swap(&a[j], &a[j + 1]);
				swapped = true; //using boolean operator
			}
		}


		if (swapped == false) //checking for alternative condition
			break;/*break if array is sorted
					i.e. no swapping possible*/
	}
}


{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", a[i]);
	printf("\n");
}



	int n, i;
	printf("What is the size of the array?\n");//taking size of array as input from user
	scanf("%d",&n);
	int a[n];
	printf("Enter elements of the array one by one\n");//storing elements in array
	for(i = 0; i < n; i++){
		scanf("\n%d",&a[i]);

	printf("Sorted array: ");
	print(a, n);  //using upper function
	return 0;
}
