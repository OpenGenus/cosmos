/* Part of Cosmos by OpenGenus Foundation */
#include <stdio.h>

typedef int bool;

/* Function to swap 2 array elements */
void 
swap(int *p, int *q) 
{
    int temp = *p;
    *p = *q;
    *q = temp;
}

/* Function to sort an array using Selection sort */
void 
selectionSort(int arr[], int n, bool order)
{
    int idx;

    /* Order 1 for AScending sort */
    if (order == 1) {
        for (int i = 0; i < n - 1; i++) {

            /* Find smallest element in the unsorted subarray */
            idx = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[idx] > arr[j]) {
                    idx = j;
                }
            }
            /* Move minimum element from unsorted subarray to sorted subarray */
            if (idx != i) {
                swap(&arr[i], &arr[idx]);
           }
        }
    }
    /* Order 0 for Descending sort */
    else if (order == 0) {
        for (int i = 0; i < n - 1; i++) {

            /* Find largest element in the unsorted subarray */
            idx = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[idx] < arr[j]) {
                    idx = j;
                }
            }
            /* Move maximum element from unsorted subarray to sorted subarray */
            if (idx != i) {
                swap(&arr[i], &arr[idx]);
           }
        }
    }
    /* If order not 0 or 1, sorting order undefined */
    else {
        printf("Undefined sorting order");
    }

}

/* Function to print array */
void
printArray(int arr[], int n) 
{
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int
main()
{
    int n;
    /* Input number of elements */ 
    printf("Enter the number of Elements: \n");
    scanf("%d",&n);

    int arr[n];
    /* Input array elements */
    printf("Enter the array elements: \n");

    for (int i = 0; i < n; i++) {
        scanf("%d",&arr[i]);
    }
     
    bool order;
    /* Input sorting order */
    printf("Enter sorting order: (1: Ascending; 0: Descending): \n");
    scanf("%d", &order);

    /* If user inputs anything except 0 or 1 for order */
    if (order != 1 && order != 0) {
        printf("Undefined sorting order.\n");
        return 1;
    }
    
    /* Sort array */
    selectionSort(arr, n, order);
    /*Print sorted array */
    printf("Sorted array:\n");
    printArray(arr, n);

    return (0);
}
