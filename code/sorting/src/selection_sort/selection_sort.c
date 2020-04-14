/* Part of Cosmos by OpenGenus Foundation */
#include <stdio.h>

int
main()
{
    int n, i, j, min, temp;

    printf("\n Enter the number of Elements: ");
    scanf("%d",&n);
    int a[n];
    printf("\n Enter the %d Elements: ",n);
    for (i = 0; i < n; i++)
        scanf("%d",&a[i]);

    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[min] > a[j])
                min = j;
        }
        if (min != i)
        {
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }

    printf("\n The Sorted array is : ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    return (0);
}
