#include <math.h>
#include <stdio.h>
#include <stdbool.h>

void introsort_r(int a[], int first, int last, int depth);
void introsort(int a[], int n);
int partition(int a[], int first, int last);
void insertion(int a[], int n);
void swap(int *a, int *b);
void doheap(int a[], int begin, int end);
void heapsort(int a[], int begin, int end);
bool isSorted(int a[], int end);

void introsort_r(int a[], int first, int last, int depth)
{
    while (last - first > 0)
    {
        if (depth == 0)
            heapsort(&a[first], first, last - first + 1);
        else
        {
            int pivot;
            if (isSorted(a, last))
                break;
            pivot = partition(a, first, last);
            introsort_r(a, pivot + 1, last, depth - 1);
            last = pivot - 1;
        }
    }
}

void introsort(int a[], int n)
{
    introsort_r(a, 0, n - 1, (int)(2 * (log(n))));
    insertion(a, n);
}

int partition(int a[], int first, int last)
{
    int pivot, mid = (first + last) / 2;

    pivot = a[first] > a[mid] ? first : mid;

    if (a[pivot] > a[last])
        pivot = last;

    swap(&a[pivot], &a[first]);
    pivot = first;

    while (first < last)
    {
        if (a[first] <= a[last])
            swap(&a[pivot++], &a[first]);
        ++first;
    }
    swap(&a[pivot], &a[last]);
    return pivot;
}

void insertion(int a[], int n)
{
    int i;
    for (i = 1; i < n; ++i)
    {
        int j, save = a[i];
        for (j = i; j >= 1 && a[j - 1] > save; --j)
            a[j] = a[j - 1];
        a[j] = save;
    }
}

void swap(int *a, int *b)
{
    int save = *a;
    *a = *b;
    *b = save;
}

void doheap(int a[], int begin, int end)
{
    int save = a[begin];
    while (begin <= end / 2)
    {
        int k = 2 * begin;
        while (k < end && a[k] < a[k + 1])
            ++k;
        if (save >= a[k])
            break;
        a[begin] = a[k];
        begin = k;
    }
    a[begin] = save;
}

void heapsort(int a[], int begin, int end)
{
    for (int i = (end - 1) / 2; i >= begin; --i)
        doheap(a, i, end - 1);
    for (int i = end - 1; i > begin; --i)
    {
        swap(&a[i], &a[begin]);
        doheap(a, begin, i - 1);
    }
}

bool isSorted(int a[], int end)
{
    for (int i = 0; i < end; ++i)
    {
        if (a[i] > a[i + 1])
            return 0;
        else
            return 1;
    }
    return 1;
}

void main()
{
    int arrayNum[10] = {5, 2, 4, 9, 8, 2, 7, 4, 1, 5};
    int n = sizeof(arrayNum) / sizeof(arrayNum[0]);
    printf("unSorted Array Elements: ");
    for (int x = 0; x < n; x++)
        printf("%d ", arrayNum[x]);

    introsort(arrayNum, n);
    printf("\nSorted Array Elements: ");
    for (int x = 0; x < n; x++)
        printf("%d ", arrayNum[x]);

    return;
}

/*
Sample Output:

unSorted Array Elements: 5 2 4 9 8 2 7 4 1 5 
Sorted Array Elements: 1 2 2 4 4 5 5 7 8 9
*/