#include <iostream>
#include <vector>
using namespace std;
// Part of Cosmos by OpenGenus Foundation
int lBitconSeq(vector<int> v, int n)
{
    vector<int> lis, lds;     // lis stands for longest increasing subsequence and lds stands for longest decreasing subsequence
    if (n == 0)
        return 0; // in case tha array is empty longest length will also be empty
    // finding lis
    for (int i = 0; i < n; i++)
        lis.push_back(1);
    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            if (v[i] > v[j] && lis[j] + 1 > lis[i])
                lis[i] = lis[j] + 1;

    //findin lds
    for (int i = 0; i < n; i++)
        lds.push_back(1);
    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            if (v[i] < v[j] && lds[j] + 1 > lds[i])
                lds[i] = lds[j] + 1;

    // result wil be max(lis[i] + lds[i] -1)
    int res = lis[0] + lds[0] - 1;
    for (int i = 1; i < n; i++)
        if ((lis[i] + lds[i] - 1) > res)
            res = lis[i] + lds[i] - 1;
    return res;
}

int main()
{
    vector<int> v;
    int n;
    cout << "enter no. of elements in array\n";
    cin >> n;
    cout << "enter elements of the array\n";
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);         // filling the array with numbers

    }
    cout << "max length of the lingest bitconic sequence is " << lBitconSeq(v, n);
}
