/* Part of Cosmos by OpenGenus Foundation */

#include <stdio.h>
typedef int bool;

/* Swap two elements */
void 
swap(int *p, int *q)
{
	int temp = *p;
	*p = *q;
	*q = temp;
}

/* Sort array using bubble sort */
void 
bubbleSort(int arr[], int n, bool order)
{
    /* Order 1 corresponds to ascending sort */
    if (order == 1) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(&arr[j], &arr[j + 1]);
                }
            }
        }
    }
    /* Order 0 corresponds to ascending sort */
    else if (order == 0) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] < arr[j + 1]) {
                    swap(&arr[j], &arr[j + 1]);
                }
            }
        }
    }
    /* If any other value of order is passed */
    else {
        printf("Undefined Sorting Order");
    }
}

/* Print sorted array */
void 
print(int a[], int n)
{
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
    } 
	printf("\n");
}

int 
main()
{
	int n;
    /* Input array size */
	printf("What is the size of the array?\n");
	scanf("%d",&n);

	int arr[n];
    /* Input elements of array */
	printf("Enter elements of the array one by one\n");

	for(int i = 0; i < n; i++) {
		scanf("\n%d",&arr[i]);
	}

    bool order;
    /* Input order of sorting. 1 for Ascending, 0 for Descending */
    printf("Enter order of sorting (1: Ascending; 0: Descending)\n");
    scanf("%d", &order);
    
    /* If user inputs order besides 1 or 0 */
    if (order != 0 && order != 1) {
        printf("Undefined sorting order.\n");
        return 1;
    }

	bubbleSort(arr, n, order);
	printf("Sorted array: ");
	print(arr, n);
	return (0);
}
