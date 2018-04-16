#include <iostream>

using namespace std;

// Part of Cosmos by OpenGenus Foundation
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(int a[], int low, int high)
{
    int pivot, index, i;
    index = low;
    pivot = high;

    for (i = low; i < high; i++)
        if (a[i] < a[pivot])
        {
            swap(&a[i], &a[index]);
            index++;
        }
    swap(&a[pivot], &a[index]);

    return index;
}


int QuickSort(int a[], int low, int high)
{
    int pindex;
    if (low < high)
    {
        pindex = Partition(a, low, high);
        QuickSort(a, low, pindex - 1);
        QuickSort(a, pindex + 1, high);
    }
    return 0;
}

int main()
{
    int n, m, bi, ai, i, k;
    double median;
    cout << "Enter the number of element in the first data set: ";
    cin >> n;

    int a[n];

    for (i = 0; i < n; i++)
    {
        cout << "Enter " << i + 1 << "th element: ";
        cin >> a[i];
    }

    cout << "\nEnter the number of element in the second data set: ";
    cin >> m;

    int b[m];

    for (i = 0; i < m; i++)
    {
        cout << "Enter " << i + 1 << "th element: ";
        cin >> b[i];
    }


    QuickSort(a, 0, n - 1);
    QuickSort(b, 0, m - 1);

    cout << "\tThe Median from these data set is: ";
    ai = 0;
    bi = 0;
    if ((m + n) % 2 == 1)
    {
        k = (n + m) / 2 + 1;
        while (k > 0)
        {
            if (a[ai] <= b[bi] && ai < n)
            {
                k--;
                if (k == 0)
                    cout << a[ai];
                ai++;
            }
            else if (a[ai] > b[bi] && bi < m)
            {
                k--;

                if (k == 0)
                    cout << b[bi];
                bi++;
            }
        }
    }
    else
    {
        k = (n + m) / 2 + 1;
        while (k > 0)
        {

            if (a[ai] <= b[bi] && ai < n)
            {
                k--;
                if (k <= 1)
                    median += a[ai];
                ai++;
            }
            else if (a[ai] > b[bi] && bi < m)
            {
                k--;

                if (k <= 1)
                    median += b[bi];
                bi++;
            }
        }

        cout << median / 2;
    }
}
