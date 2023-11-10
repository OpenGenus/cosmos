#include <bits/stdc++.h>
using namespace std;

double findMedian(int arr1[], int n1, int arr2[], int n2)
{
    int lo = 0, hi = n1;
    while (lo <= hi)
    {
        int cut1 = lo + (hi - lo) / 2;
        int cut2 = (n1 + n2) / 2;

        double l1 = cut1 == 0 ? INT_MIN : arr1[cut1 - 1];
        double l2 = cut2 == 0 ? INT_MIN : arr2[cut2 - 1];
        double r1 = cut1 == 0 ? INT_MAX : arr1[cut1];
        double r2 = cut2 == 0 ? INT_MAX : arr2[cut2];

        if (l1 > r2)
        {
            hi = cut1 - 1;
        }
        else if (l2 > r1)
        {
            lo = cut1 + 1;
        }
        else
        {
            if ((n1 + n2) % 2 == 0)
            {
                return ((max(l1, l2)) + (min(r1, r2))) / 2;
            }
            else
            {
                return min(r1, r2);
            }
        }

        return -1;
    }
}

int main()
{
    int n1, n2;
    cin >> n1 >> n2;
    int arr1[n1], arr2[n2];
    for (int i = 0; i < n1; i++)
    {
        cin >> arr1[i];
    }
    for (int i = 0; i < n2; i++)
    {
        cin >> arr2[i];
    }
    if (n2 > n1)
        cout << findMedian(arr1, n1, arr2, n2);
    else
        cout << findMedian(arr2, n2, arr1, n1);
}