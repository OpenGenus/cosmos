#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;
void introsort_r(int a[], int first, int last, int depth);
void _introsort(int a[], int n);
int _partition(int a[], int first, int last);
void _insertion(int a[], int n);
void _swap(int *a, int *b);
void _doheap(int a[], int begin, int end);
void _heapsort(int a[], int begin, int end);
bool _isSorted(int a[], int end);

void introsort_r(int a[], int first, int last, int depth)
{
    while (last - first > 0)
    {
        if (depth == 0)
            _heapsort(&a[first], first, last - first + 1 );
        else
        {
            int pivot;
            if (_isSorted(a, last))
                break;
            pivot = _partition(a, first, last);
            introsort_r(a, pivot + 1, last, depth - 1);
            last = pivot - 1;
        }
    }
}

void _introsort(int a[], int n)
{
    introsort_r ( a, 0, n - 1, (int(2 * log(double(n)))));
    _insertion(a, n);
}

int _partition ( int a[], int first, int last)
{
    int pivot, mid = (first + last) / 2;

    pivot = a[first] > a[mid]  ? first : mid;

    if (a[pivot] > a[last])
        pivot = last;

    _swap( &a[pivot], &a[first] );
    pivot = first;

    while (first < last)
    {
        if (a[first] <= a[last])
            _swap( &a[pivot++], &a[first] );
        ++first;
    }

    _swap (&a[pivot], &a[last]);
    return pivot;
}

void _insertion ( int a[], int n )
{
    int i;
    for (i = 1; i < n; i++)
    {
        int j, save = a[i];
        for (j = i; j >= 1 && a[j - 1] > save; j--)
            a[j] = a[j - 1];
        a[j] = save;
    }
}

void _swap(int *a, int *b)
{
    int save = *a;
    *a = *b;
    *b = save;
}
void _doheap(int a[], int begin, int end )
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

void _heapsort(int a[], int begin, int end )
{
    int i;
    for (int i = (end - 1) / 2; i >= begin; i--)
        _doheap( a, i, end - 1);
    for (i = end - 1; i > begin; i--)
    {
        _swap( &a[i], &a[begin]);
        _doheap(a, begin, i - 1);
    }
}
bool _isSorted(int a[], int end)
{
    for (int i = 0; i < end; i++)
    {
        if (a[i] > a[i + 1])
            return false;
        else
            return true;
    }
    return true;
}
int main()
{
    int arrayNum[50], t;
    cout << "Enter Number of Elements:";
    cin >> t;
    for (int y = 0; y < t; y++)
        cin >> arrayNum[y];
    _introsort(arrayNum, t);
    for (int x = 0; x < t; x++)
        std::cout << x << ":" << arrayNum[x] << std::endl;
    cin.get();
    return 0;
}
