/*Part of Cosmos by OpenGenus Foundation*/

#include <stdio.h> //Pre-defined libraries
typedef int bool;
#define true 1
#define false 0

void swap(int *p, int *q)//Swap function with parameter used to reduce usage of same code again
{
	int temp = *p;
	*p = *q;
	*q = temp;
}

/*Sorting an array a[] consisting of n
  elements with bubble sort method*/
void bubbleSort(int a[], int n) //Bubble sort function with parameters containing no of elements and array
{
	int i, j;
	bool swapped;
	for (i = 0; i < n - 1; i++)
	{
		swapped = false;
		for (j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1]) //Condition check to see if next elements is greater than the initial one
			{
				swap(&a[j], &a[j + 1]);
				swapped = true;
			}
		}


		if (swapped == false) //Boolean used for alternative situation
			break;/*break if array is sorted
					i.e. no swapping possible*/
	}
}

//printing sorted array
void print(int a[], int size) //Print function
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", a[i]);
	printf("\n");
}



int main() //Main function
{
	int n, i;
	printf("What is the size of the array?\n");//taking size of array as input from user
	scanf("%d",&n);
	int a[n];
	printf("Enter elements of the array one by one\n");//storing elements in array
	for(i = 0; i < n; i++){
		scanf("\n%d",&a[i]);
	}
	bubbleSort(a, n); //Using Functions defined above to reduce code complexity
	printf("Sorted array: ");
	print(a, n); //Using Functions defined above to reduce code complexity
	return 0;
}
