/* Part of Cosmos by OpenGenus Foundation */
#include <stdio.h>

/* Selection Sort Implementation in C */
int main()
{
    int n, i, j, min, temp;

    printf("\n Enter the number of Elements: ");
    scanf("%d",&n);
    int a[n];
    printf("\n Enter the %d Elements: ",n);
    for (i = 0; i < n; i++)
        scanf("%d",&a[i]);

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++)
    {
        // Find the minimum element in unsorted array
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[min] > a[j])
                min = j;
        }
        if (min != i)
        {

            // Swap the found minimum element with the first element
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }

    // Print the sorted array
    printf("\n The Sorted array is : ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    return (0);
}
