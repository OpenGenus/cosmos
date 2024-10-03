// C++ program to impleament cycle sort
#include <iostream>
using namespace std;
// Part of Cosmos by OpenGenus Foundation
// Function sort the array using Cycle sort
void cycleSort (int arr[], int n)
{
    // traverse array elements and put it to on
    // the right place
    for (int cycle_start=0; cycle_start<=n-2; cycle_start++)
    {
        // initialize item as starting point
        int item = arr[cycle_start];

        // Find position where we put the item. We basically
        // count all smaller elements on right side of item.
        int pos = cycle_start;
        for (int i = cycle_start+1; i<n; i++)
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
        {
            swap(item, arr[pos]);
        }

        // Rotate rest of the cycle
        while (pos != cycle_start)
        {
            pos = cycle_start;

            // Find position where we put the element
            for (int i = cycle_start+1; i<n; i++)
                if (arr[i] < item)
                    pos += 1;

            // ignore all duplicate  elements
            while (item == arr[pos])
                pos += 1;

            // put the item to it's right position
            if (item != arr[pos])
            {
                swap(item, arr[pos]);
            }
        }
    }
}

// Main Function
int main()
{
    int sz;
    cout<<"Enter the size of array : ";
    cin>>sz;//size of array
    int arr[sz];
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Enter Elements : ";
    for(int m=0; m<sz; m++)
        cin>>arr[m];
    cycleSort(arr,  n) ;

    cout << "\nAfter sort : " <<endl;
    for(int i =0; i<n; i++)
        cout << arr[i] << " ";
    return 0;
}
