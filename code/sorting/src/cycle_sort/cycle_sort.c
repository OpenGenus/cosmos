#include <stdio.h>

void swap(int *a, int *b)
{
    int t = *b;
    *b = *a;
    *a = t;
}
 
void cycleSort(long long int arr[],long long int n)
{
    int cycle_start;
    for (cycle_start = 0; cycle_start <= n - 2; ++cycle_start) {
        int item = arr[cycle_start]; 
        int pos = cycle_start;

        int i;
        for (i = cycle_start + 1; i < n; ++i)
            if (arr[i] < item)
                ++pos;

        if (pos == cycle_start)
            continue;
 
        while (item == arr[pos])
            ++pos;
 
        if (pos != cycle_start)
            swap(&item, &arr[pos]);
 
        while (pos != cycle_start) {
            pos = cycle_start;
 
            for (i = cycle_start + 1; i < n; i++)
                if (arr[i] < item)
                    ++pos;
 
            while (item == arr[pos])
                ++pos;
 
            if (item != arr[pos])
                swap(&item, &arr[pos]);
        }
    }
}
int main()
{
    long long int n;
    printf("Enter size of the Array: ");
    scanf("%lld", &n);

    long long int arr[n];
    printf("Enter %lld Integers:- \n", n);
    int i;
    for (i = 0; i < n; ++i)
    {
        scanf("%lld ", &arr[i]);
    }
    cycleSort(arr, n);
    
    printf("Array after Sorting:- \n");
    for (i = 0; i < n; ++i)
    {
        printf("%lld ", arr[i]);
    }
    printf("\n");
    
    return (0);
}
