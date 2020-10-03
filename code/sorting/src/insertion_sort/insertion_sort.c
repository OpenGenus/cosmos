/* Part of Cosmos by OpenGenus Foundation */
#include <stdio.h>

typedef int bool;

void insertionSort(int*, int, bool);
void printArray(int*, int);

int 
main()
{
	int n;
    /* Taking number of array elements as input from user */
    printf("Enter size of array:\n");
	scanf("%d", &n);

	int arr[n];
    /* Taking array elements as input from user */
    printf("Enter array elements:\n");

	for(int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
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

    /* Sort array */
	insertionSort(arr, n, order);
    /* Print sorted array */
    printArray(arr, n);

	return (0);
}

/* Insertion sort function */
void 
insertionSort(int arr[], int n, bool order)
{
	int key;
	int j;

    /* Order 1 corresponds to Ascending order */
    if (order == 1) {
        for(int i = 1; i < n; i++) {
            key = arr[i];
            j = i - 1;
            /* 
             * Shift elements of arr[0..i-1], that are  
                   * greater than key, to one position ahead  
                   * of their current position 
             */
            while(j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        } 
    }

    /* Order 0 corresponds to Descending order */
    else if (order == 0) {
        for(int i = 1; i < n; i++) {
            key = arr[i];
            j = i - 1;
            /* 
             * Shift elements of arr[0..i-1], that are  
                   * lesser than key, to one position ahead  
                   * of their current position 
             */
            while(j >= 0 && arr[j] < key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        } 
    }

    /* If order not 0 or 1, undefined */
    else {
        printf("Undefind sorting order.\n");
    }

}

/* To print array */
void 
printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
