/* Part of Cosmos by OpenGenus Foundation */

#include <bits/stdc++.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

/* UTILITY FUNCTIONS */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
 
void printarr(int a[], int n)
{
    for (int i = 0; i < n; ++i)
        printf("%d ", a[i]);
    printf("\n");
}

void fill(int a[], int size, int max)
{
    for (int i = 0; i < size; ++i)
        a[i] = rand() % max +1;
}


void partition(int a[], int low, int high, int &i, int &j)
{
    if (high - low <= 1)
    {
        if (a[high] < a[low])
            swap(&a[high], &a[low]);
        i = low;
        j = high;
        return;
    }
 
    int mid = low;
    int pivot = a[high];
    while (mid <= high)
    {
        if (a[mid]<pivot)
            swap(&a[low++], &a[mid++]);
        else if (a[mid]==pivot)
            mid++;
        else if (a[mid]>pivot)
            swap(&a[mid], &a[high--]);
    }
 
    i = low-1;
    j = mid; 
}
 
// 3-way partition based quick sort
void quicksort(int a[], int low, int high)
{
    if (low>=high) 
        return;
 
    int i, j; //references
 
    partition(a, low, high, i, j);
 
    // Recur two halves
    quicksort(a, low, i);
    quicksort(a, j, high);
}
 
// Driver program
int main()
{
    int size=10;
    int maxRand=10;
    printf("Input test array size: ");
    cin >> size;
    int a[size];
    printf("Maximum random number: ");
    cin >> maxRand;
    
    fill(a,size,maxRand);
    printf("Unsorted: ");
    printarr(a, size);
    quicksort(a, 0, size - 1);
    printf("Sorted:   ");
    printarr(a, size);
    return 0;
}
