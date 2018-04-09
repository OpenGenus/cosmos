// C++ program to sort an array using bucket sort
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Part of Cosmos by OpenGenus Foundation
// Function to sort arr[] of size n using bucket sort
void bucketSort(vector<float>& arr)
{
    // 1) Create n empty buckets
    vector<float> b[arr.size()];

    // 2) Put array elements in different buckets
    for (size_t i = 0; i < arr.size(); i++)
    {
        int bi = arr.size() * arr[i];   // Index in bucket
        b[bi].push_back(arr[i]);
    }

    // 3) Sort individual buckets
    for (size_t i = 0; i < arr.size(); i++)
        sort(b[i].begin(), b[i].end());

    // 4) Concatenate all buckets into arr[]
    int index = 0;
    for (size_t i = 0; i < arr.size(); i++)
        for (size_t j = 0; j < b[i].size(); j++)
            arr[index++] = b[i][j];
}

/* Driver program to test above funtion */
int main()
{
    vector<float> arr{0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    bucketSort(arr);

    cout << "Sorted array is \n";
    for (size_t i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    return 0;
}
