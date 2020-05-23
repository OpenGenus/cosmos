/* Part of Cosmos by OpenGenus Foundation */
#include <stdio.h>

int
main()
{
    int n, i, j, min, temp;
    
    printf("\n Enter the number of Elements: "); // Entering the number of elements
    scanf("%d",&n);
    int a[n];
    printf("\n Enter the %d Elements: ",n); // Entering the elements in the array
    for (i = 0; i < n; i++)
        scanf("%d",&a[i]);
     
    for (i = 0; i < n - 1; i++) 
    {
        min = i; // Assume min = i
        for (j = i + 1; j < n; j++)
        {
            if (a[min] > a[j]) // If element at min position is greater than element at jth position then min = j
                min = j;
        }
        if (min != i) // If min and i are not same then swap the elements at position i and min
        {
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }
     
    printf("\n The Sorted array is : "); // Printing the sorted array
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    return (0);
}