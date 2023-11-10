#include <stdio.h>
#include <stdlib.h>

// Function to read elements of an array
void readArray(int *arr, int size) {
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

// Function to merge two arrays
void mergeArrays(int *arr1, int m, int *arr2, int n, int *result) {
    int i = 0, j = 0, k = 0;
    
    while (i < m && j < n) {
        if (arr1[i] < arr2[j]) {
            result[k++] = arr1[i++];
        } else {
            result[k++] = arr2[j++];
        }
    }
    
    while (i < m) {
        result[k++] = arr1[i++];
    }
    
    while (j < n) {
        result[k++] = arr2[j++];
    }
}

int main() {
    int m, n;
    
    printf("Enter the number of elements in the first array: ");
    scanf("%d", &m);
    
    printf("Enter the number of elements in the second array: ");
    scanf("%d", &n);
    
    int *arr1 = malloc(m * sizeof(int));
    int *arr2 = malloc(n * sizeof(int));
    
    if (arr1 == NULL || arr2 == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    
    readArray(arr1, m);
    readArray(arr2, n);
    
    int mergedSize = m + n;
    int *mergedArray = malloc(mergedSize * sizeof(int));
    
    if (mergedArray == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    
    mergeArrays(arr1, m, arr2, n, mergedArray);
    
    printf("\nMerged array is:\n");
    for (int i = 0; i < mergedSize; i++) {
        printf("%d ", mergedArray[i]);
    }
    
    free(arr1);
    free(arr2);
    free(mergedArray);
    
    return 0;
}