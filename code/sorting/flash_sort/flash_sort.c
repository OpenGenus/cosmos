// The flash sort algorithm
// The idea is simple
// If we know min max of arr is 0 and 100
// We know that 50 must be somewhere near the mid
#include <stdio.h>
#include <stdlib.h>

void myswap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void flashSort(int *arr, int size)
{
    // Phase 1
    int min = arr[0];
    int max = arr[0];
    for (int i = 1; i < size; ++i)
    {
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
    }

    if (min == max)
        return;

    int m = 0.43 * size; // Divide to m class
    float c = (float)(m - 1) / (max - min);

    int *L = (int *)calloc(m + 1, sizeof(int));
    for (int i = 0; i < size; ++i)
    {
        int k = c * (arr[i] - min) + 1;
        ++L[k]; // L[k]: the number of class K
    }
    for (int k = 2; k <= m; ++k)
    {
        L[k] += L[k - 1]; // L[k]: upper bound of class K
    }

    // Phase 2
    int move = 0; // number of move
    int j = 0;
    int k = m;
    while (move < size - 1) // Only move size - 1 step
    {
        while (j >= L[k]) // arr[j] is in right class
        {
            ++j;
            k = c * (arr[j] - min) + 1;
        }
        int flash = arr[j]; // temp to hold the value
        while (j < L[k])    // stop when arr[j] is changed
        {
            k = c * (flash - min) + 1;
            myswap(&flash, &arr[--L[k]]);
            ++move;
        }
    }

    // Phase 3
    // Use Insertion sort for every class
    // Don't sort the m class,
    // Becuase the m class is all max
    for (int k = 1; k < m; ++k)
    {
        for (int i = L[k] + 1; i < L[k + 1]; ++i)
        {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key)
            {
                arr[j + 1] = arr[j];
                --j;
            }
            arr[j + 1] = key;
        }
    }
    free(L);
}

int main()
{
    int arr[] = {9, 1, 1, 8, 2, 2, 3, 6, 7, 12};
    int size = sizeof(arr) / sizeof(arr[0]);
    flashSort(arr, size);
    for (int i = 0; i < size; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
