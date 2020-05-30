/*Part of Cosmos by OpenGenus Foundation*/

#include <stdio.h>  //pre-defined libraries
typedef int bool;
#define true 1 
#define false 0 

void swap(int *p, int *q) //Using Swap function with parameters
void swap(int *p, int *q) //Using Swap function with parameters
void swap(int *p, int *q)  //Using Swap function with parameters
{
	int temp = *p;//Swapping position of two variable with respect to a third one
	*p = *q;
	*q = temp; //Placing variables at different position using pointer
}

/*Sorting an array a[] consisting of n
  elements with bubble sort method*/
void bubbleSort(int a[], int n)
{
	int i, j;
	bool swapped;
	for (i = 0; i < n - 1; i++) //for loop till n-1 terms
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


void print(int a[], int size) //Function to print
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", a[i]);
	printf("\n");
}



int main()  //Main function
{   
	int n, i;
	printf("What is the size of the array?\n");
	scanf("%d",&n);
	int a[n];
	printf("Enter elements of the array one by one\n");
	for(i = 0; i < n; i++){
		scanf("\n%d",&a[i]);
	}    
	bubbleSort(a, n); //using upper function
	printf("Sorted array: ");
	print(a, n);  //using upper function
	return 0;
}
