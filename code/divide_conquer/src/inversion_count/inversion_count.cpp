//  divide conquer | inversion count | C++
//  Part of Cosmos by OpenGenus Foundation

#include <iostream>
using namespace std;

int mergesort(int arr[], int l, int r);
int merge(int arr[], int l, int m, int r);



int main()
{
    int n, a[100], i;
    cout << "Enter nuber of elements : ";
    cin >> n;
    cout << "Enter the elements : ";
    for (i = 0; i < n; i++)
        cin >> a[i];
    cout << "Number of inversion = " << mergesort(a, 0, n - 1);
    return 0;
}

//merge
int merge(int arr[], int l, int m, int r)
{
    int i, j, k, c[100], count = 0;
    i = 0;
    j = l;
    k = m;
    while (j <= m - 1 && k <= r)
    {
        if (arr[j] <= arr[k])
            c[i++] = arr[j++];

        else
        {
            c[i++] = arr[k++];
            count += m - j;

        }

    }

    while (j <= m - 1)
        c[i++] = arr[j++];

    while (k <= r)
        c[i++] = arr[k++];
    i = 0;
    while (l <= r)
        arr[l++] = c[i++];

    return count;
}


//mergesort
int mergesort(int arr[], int l, int r)
{
    int x = 0, y = 0, z = 0;
    int m = (l + r) / 2;
    if (l < r)
    {
        x += mergesort(arr, l, m);
        y += mergesort(arr, m + 1, r);
        z += merge(arr, l, m + 1, r);

    }

    return x + y + z;
}
