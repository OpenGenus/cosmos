/*
 * C Program to Implement Stooge Sort
 */
#include <stdio.h>
 
// Function Prototype
void stoogesort(int [], int, int);
 
void main()
{
    int b[7], i;
 
    printf("Enter the values you want to sort using STOOGE SORT!!!:\n");
    for (i = 0;i < 7;i++)
        scanf(" %d", &b[i]);
    stoogesort(b, 0, 6);
    printf("sorted by stooge sort \n");
    for (i = 0;i < 7;i++)
    {
        printf("%d ", b[i]);
    }
    printf("\n");
}
 
// Function to implement STOOGE SORT
void stoogesort(int a[], int i, int j)
{
    int temp, k;
 
    if (a[i] > a[j])
    {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;        
    }
    if ((i + 1) >= j)
        return;
    k = (int)((j - i + 1) / 3);
    stoogesort(a, i, j - k);
    stoogesort(a, i + k, j);
    stoogesort(a, i, j - k);
}
