/* Part of Cosmos by OpenGenus Foundation */

#include <vector>
#include <stdlib.h>
#include <iostream>

using namespace std;

/* UTILITY FUNCTIONS */
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void printarr(vector<int> &v)
{
    for (size_t i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << endl;
}

void fill(vector<int> &v, int max)
{
    for (size_t i = 0; i < v.size(); ++i)
        v[i] = rand() % max + 1;
}

// three-way-partioning
void partition(vector<int> &v, int low, int high, int &i, int &j)
{
    if (high - low <= 1)
    {
        if (v[high] < v[low])
            swap(v[high], v[low]);
        i = low;
        j = high;
        return;
    }

    int mid = low;
    int pivot = v[high];
    while (mid <= high)
    {
        if (v[mid] < pivot)
            swap(v[low++], v[mid++]);
        else if (v[mid] == pivot)
            mid++;
        else if (v[mid] > pivot)
            swap(v[mid], v[high--]);
    }

    i = low - 1;
    j = mid;
}


void quicksort(vector<int> &v, int low, int high)
{
    if (low >= high)
        return;

    int i, j;

    partition(v, low, high, i, j);

    // Recursively sort two halves
    quicksort(v, low, i);
    quicksort(v, j, high);
}

// Driver program
int main()
{
    int size = 10;
    int maxRand = 10;
    cout << "Input test array size: ";
    cin >> size;
    vector<int> v(size);
    cout << "Maximum random number: ";
    cin >> maxRand;

    fill(v, maxRand);
    cout << "Unsorted: ";
    printarr(v);
    quicksort(v, 0, size - 1);
    cout << "Sorted:   ";
    printarr(v);
    return 0;
}
