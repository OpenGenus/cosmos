// A C++ Program to implement Gnome Sort
#include <iostream>
using namespace std;

// A function to sort the algorithm using gnome sort
void gnomeSort(int arr[], int n)
{
    int index = 0;

    while (index < n)
    {
        if (index == 0)
            index++;
        if (arr[index] >= arr[index - 1])
            index++;
        else
        {
            swap(arr[index], arr[index - 1]);
            index--;
        }
    }
    return;
}

// A utility function ot print an array of size n
void printArray(int arr[], int n)
{
    cout << "Sorted sequence after Gnome sort: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

// Driver program to test above functions.
int main()
{
    int arr[] = {34, 2, 10, -9};
    int n = sizeof(arr) / sizeof(arr[0]);

    gnomeSort(arr, n);
    printArray(arr, n);

    return 0;
}
