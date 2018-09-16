#include <iostream>
#include <vector>
#include <climits>

/*
 * Part of Cosmos by OpenGenus Foundation
 */

using namespace std;
void countingSort(vector<int> arr, vector<int>& sortedA)
{
    int m = INT_MIN;
    for (size_t i = 0; i < arr.size(); i++)
        if (arr[i] > m)
            m = arr[i];

    int freq[m + 1];   //m is the maximum number in the array
    for (int i = 0; i <= m; i++)
        freq[i] = 0;
    for (size_t i = 0; i < arr.size(); i++)
        freq[arr[i]]++;
    int j = 0;
    for (int i = 0; i <= m; i++)
    {
        int tmp = freq[i];
        while (tmp--)
        {
            sortedA[j] = i;
            j++;
        }
    }
}
int main()
{
    vector<int> arr{1, 4, 12, 34, 16, 11, 9, 1, 3, 33, 5};
    vector<int> sortedA(arr.size() + 1);   // stores sorted array
    countingSort(arr, sortedA);
    cout << "Sorted Array:  ";
    for (size_t i = 0; i < arr.size(); i++)
        cout << sortedA[i] << " ";
    return 0;
}
