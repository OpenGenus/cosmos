/*
 * C Program to Implement BogoSort in an Integer Array
 */
#include <stdio.h>
#include <stdlib.h>
 
#define size 7
/* Function Prototypes */
 
int is_sorted(int *, int);
void shuffle(int *, int); 
void bogosort(int *, int);
 
int main()
{
    int numbers[size];
    int i;
 
    printf("Enter the elements of array:");
    for (i = 0; i < size;i++)
    {
        scanf("%d", &numbers[i]);
    }
    bogosort(numbers, size);
    printf("The array after sorting is:");
    for (i = 0;i < size;i++)
    {
        printf("%d\n", numbers[i]);
    }
    printf("\n");
}
 
/* Code to check if the array is sorted or not */
int is_sorted(int *a, int n)
{
    while (--n >= 1)
    {
        if (a[n] < a[n - 1])
        {
            return 0;
          }
    }
      return 1;
}
 
/* Code to shuffle the array elements */
void shuffle(int *a, int n)
{
    int i, t, temp;
    for (i = 0;i < n;i++)
    {
        t = a[i];
        temp = rand() % n;    /* Shuffles the given array using Random function */
        a[i] = a[temp];
        a[temp] = t;
    }
}
 
/* Code to check if the array is sorted or not and if not sorted calls the shuffle function to shuffle the array elements */
void bogosort(int *a, int n)
{
    while (!is_sorted(a, n))
    {
        shuffle(a, n);
    }
}
