// This algorithm is similar to quicksort because it
// chooses an element as a pivot and partitions the
// data into two based on the pivot. However, unlike
// quicksort, quickselect only recurses into one side
// - the side with the element it is searching for.
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
// Part of Cosmos by OpenGenus Foundation
using namespace std;

// Swaps values in vector with given indices
void vSwap(vector<int> &v, int pos1, int pos2)
{
    int temp = v[pos1];
    v[pos1] = v[pos2];
    v[pos2] = temp;
}

int partition(vector<int> &v, int left, int right, int pivotIndex)
{
    int pivotValue = v[pivotIndex];
    vSwap(v, pivotIndex, right);
    int storeIndex = left;
    for (int i = left; i < right; i++)
        if (v[i] < pivotValue)
        {
            vSwap(v, storeIndex, i);
            storeIndex++;
        }
    vSwap(v, right, storeIndex);
    return storeIndex;
}

// Returns the k-th smallest element of list in left <= k <= right
int select(vector<int> &v, int left, int right, int k)
{
    if (left == right)
        return v[k];
    // Select a random pivot within left and right
    int pivotIndex = left + floor(rand() % (right - left + 1));
    pivotIndex = partition(v, left, right, pivotIndex);

    if (k == pivotIndex)
        return v[k];
    else if (k < pivotIndex)
        return select(v, left, pivotIndex - 1, k);
    else
        return select(v, pivotIndex + 1, right, k);
}

int main()
{
    vector<int> v = {70, 45, 98, 66, 34, 18, 23, 6, 8, 99, 69, 24, 10, 97, 88, 42, 74, 4, 5, 100};
    cout << select(v, 0, v.size() - 1, 0) << endl;
    return 0;
}
