#include <iostream>
// Part of Cosmos by OpenGenus Foundation
using namespace std;

int updateGap(int gap)
{
    gap = (gap * 10) / 13;
    if (gap < 1)
        return 1;
    else
        return gap;
}

void combSort(int ar[], int n)
{
    int gap = n;
    int flag = 0;
    while (gap > 1 || flag == 1)
    {
        gap = updateGap(gap);
        flag = 0;
        for (int i = 0; i < (n - gap); i++)
        {
            int x;
            if (ar[i] > ar[i + 1])
            {
                x = ar[i];
                ar[i] = ar[i + 1];
                ar[i + 1] = x;
                flag = 1;
            }
        }
    }
}

int main()
{
    int n;
    cout << "Input number of elements in the array - ";
    cin >> n;
    int ar[n];
    for (int i = 0; i < n; i++)
        cin >> ar[i];
    combSort(ar, n);
    cout << "Array after sorting - ";
    for (int i = 0; i < n; i++)
        cout << ar[i] << endl;
}
