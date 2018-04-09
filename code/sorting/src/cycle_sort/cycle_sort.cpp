// C++ program to impleament cycle sort
#include <iostream>
#include <vector>
using namespace std;
// Part of Cosmos by OpenGenus Foundation
// Function sort the array using Cycle sort
void cycleSort (vector<int>& arr)
{
    // traverse array elements and put it to on
    // the right place
    for (size_t cycle_start = 0; cycle_start <= arr.size() - 2; cycle_start++)
    {
        // initialize item as starting point
        int item = arr[cycle_start];

        // Find position where we put the item. We basically
        // count all smaller elements on right side of item.
        size_t pos = cycle_start;
        for (size_t i = cycle_start + 1; i < arr.size(); i++)
            if (arr[i] < item)
                pos++;

        // If item is already in correct position
        if (pos == cycle_start)
            continue;

        // ignore all duplicate  elements
        while (item == arr[pos])
            pos += 1;

        // put the item to it's right position
        if (pos != cycle_start)
            swap(item, arr[pos]);

        // Rotate rest of the cycle
        while (pos != cycle_start)
        {
            pos = cycle_start;

            // Find position where we put the element
            for (size_t i = cycle_start + 1; i < arr.size(); i++)
                if (arr[i] < item)
                    pos += 1;

            // ignore all duplicate  elements
            while (item == arr[pos])
                pos += 1;

            // put the item to it's right position
            if (item != arr[pos])
                swap(item, arr[pos]);
        }
    }
}

// Main Function
int main()
{
    vector<int> arr;
    cout << "Enter the elements of the array: ";
    int n;
    while (cin >> n)
        arr.push_back(n);
    cycleSort(arr);

    cout << "\nAfter sort : " << endl;
    for (size_t i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    return 0;
}
