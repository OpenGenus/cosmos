/* Part of Cosmos by OpenGenus Foundation */

#include<stdio.h>
#include<iostream>

void swap(int *a, int *b);

using namespace std;

// Dutch National Flag Sort
void flagSort(int a[], int arr_size)
{
    int lo = 0;
    int hi = arr_size - 1;
    int mid = 0;
 
    while (mid <= hi)
    {
        switch (a[mid])
        {
        case 0:
            swap(&a[lo++], &a[mid++]);
            break;
        case 1:
            mid++;
            break;
        case 2:
            swap(&a[mid], &a[hi--]);
            break;
        }
    }
}
 
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


void flagFill(int a[] , int size) 
{
    for (int i = 0; i < size; ++i) {
        a[i] = rand() % 2 + 1;
    }
}

// Driver program
int main()
{
    int size=10;
    int maxRand=10;
    printf("Input test array size: ");
    cin >> size;
    int a[size];
    
    flagFill(a,size);
    printf("Unsorted: ");
    printarr(a, size);
    flagSort(a,size);
    printf("Sorted:   ");
    printarr(a, size);
 
    getchar();
    return 0;
}
