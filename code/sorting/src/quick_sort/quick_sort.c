/*Part of Cosmos by OpenGenus Foundation*/
#include <stdio.h> //predefined Library

void swap(int *p, int *q) //Swap function to reduce code complexity afterwards
{
	int temp = *p;
	*p = *q;
	*q = temp;
}


//Last element is used a spivot
//Places elements smaller than pivot to its left side
//Places elements larger than pivot to its right side
int partition(int a[], int low, int high) //Partition Function
{
	int pivot = a[high];
	int i = (low - 1);  

	for (int j = low; j <= high- 1; j++) //Loop till High-1
	{
		if (a[j] <= pivot) //Condition check
		{
			i++;
			swap(&a[i], &a[j]); //Use of swap function declared above
		}
	}
	swap(&a[i + 1], &a[high]);
	return (i + 1);
}

void quickSort(int a[], int low, int high)  //Quicksort function 
{
	if (low < high)
	{
		int k = partition(a, low, high); //Use of above defined partition function
		//k is pivot index

		quickSort(a, low, k - 1);
		quickSort(a, k + 1, high);
	}
}
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
	printf("What is the size of the array?\n"); //Print Condition
	scanf("%d",&n); //Taking input from user
	int a[n];
	printf("Enter elements of the array one by one\n");

	for(i = 0; i < n; i++){
		scanf("\n%d",&a[i]);
	}    

	quickSort(a, 0, n - 1); // Use of above defined function to reduce space and time complexity
	printf("Sorted array: "); // Use of above defined function to reduce space and time complexity
	print(a, n);
	return 0;
}
