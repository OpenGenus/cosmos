#include <vector>
#include <iostream>

using namespace std;

/* Sorts the array using pigeonhole algorithm */
// Part of Cosmos by OpenGenus Foundation
void pigeonholeSort(vector<int>& arr)
{
    // Find minimum and maximum values in arr[]
    int min = arr[0], max = arr[0];
    for (size_t i = 1; i < arr.size(); i++)
    {
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
    }
    int range = max - min + 1; // Find range

    // Create an array of vectors. Size of array
    // range. Each vector represents a hole that
    // is going to contain matching elements.
    vector<int> holes[range];

    // Traverse through input array and put every
    // element in its respective hole
    for (size_t i = 0; i < arr.size(); i++)
        holes[arr[i] - min].push_back(arr[i]);

    // Traverse through all holes one by one. For
    // every hole, take its elements and put in
    // array.
    int index = 0;  // index in sorted array
    for (int i = 0; i < range; i++)
    {
        vector<int>::iterator it;
        for (it = holes[i].begin(); it != holes[i].end(); ++it)
            arr[index++] = *it;
    }
}

// Driver program to test the above function
int main()
{
    vector<int> arr{25, 0, 2, 9, 1, 4, 8};

    pigeonholeSort(arr);

    cout << "Sorted order is : ";
    for (size_t i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << "\n";
    return 0;
}
