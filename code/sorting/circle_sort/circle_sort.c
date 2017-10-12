/*Part of Cosmos by OpenGenus Foundation*/

#include <stdio.h>
#include <stdlib.h>
 
void swap(int *p, int *q)
{
    int tmp = *p;
    *p = *q;
    *q = tmp;
}

void print_vector(int *a, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int circle_sort(int *a, int n, int lower, int upper, int swaps)
{
    if (lower == upper)
        return swaps;

    int low = lower;
    int high = upper;
    int mid = (upper - lower) / 2;

    while (lower < upper) {
        if (a[lower] > a[upper]) {
            swap(&a[lower], &a[upper]);
            swaps++;
        }
        lower++;
        upper--;
    }

    if (lower == upper) {
        if(a[lower] > a[upper + 1]) {
            swap(&a[lower], &a[upper + 1]);
            swaps++;
        }
    }

    circle_sort(a, n, low, low + mid, swaps);
    circle_sort(a, n, low + mid + 1, high, swaps);

    return swaps;
}

int main()
{   
    int n;
    int *a;
    printf("Inform the size of the array:\n");
    scanf("%d", &n);

    a = (int *) malloc(n * sizeof(int));

    printf("Enter elements of the array one by one\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }    

    printf("Unsorted List: ");
    print_vector(a, n);
    circle_sort(a, n, 0, n - 1, 0);
    printf("Sorted List: ");
    print_vector(a, n);

    free(a);
    return 0;
}
