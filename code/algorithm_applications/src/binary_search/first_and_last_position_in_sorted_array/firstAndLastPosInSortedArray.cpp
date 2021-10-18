#include <bits/stdc++.h>
using namespace std;

int first(int arr[], int x, int n)
{
    int low = 0, high = n - 1, res = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] > x)
            high = mid - 1;
        else if (arr[mid] < x)
            low = mid + 1;
        else
        {
            res = mid;
            high = mid - 1;
        }
    }
    return res;
}

int last(int arr[], int x, int n)
{
    int low = 0, high = n - 1, res = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] > x)
            high = mid - 1;
        else if (arr[mid] < x)
            low = mid + 1;
        else
        {
            res = mid;
            low = mid + 1;
        }
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int q;
    cin >> q;
    while (q--)
    {
        int a;
        cin >> a;
        cout << first(arr, a, n) << " " << last(arr, a, n) << endl;
    }
}