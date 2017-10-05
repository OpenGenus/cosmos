#include <stdio.h>
void swap(int* m, int* n)
{
    int x =*m;
    *m =*n;
    *n =x;
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];   
    int i =low-1; 
 
    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;  
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quick_Sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quick_Sort(arr, low, pi - 1);
        quick_Sort(arr, pi + 1, high);
    }
}
void printarr(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("n");
}
 
int main()
{
    int arr[] = {10,9,8,7,6,5,4,3,2,1};
    int n = 10;
    quick_Sort(arr, 0, n-1);
    printf("Sorted array: n");
    printarr(arr, n);
    return 0;
}
