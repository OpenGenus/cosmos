/* Part of Cosmos by OpenGenus Foundation */
#include <vector>
#include <iostream>
using namespace std;

void heapify (vector<int> &v, int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && v[l] > v[largest])
        largest = l;
    if (r < n && v[r] > v[largest])
        largest = r;
    if (largest != i)
    {
        swap(v[i], v[largest]);
        heapify(v, n, largest);
    }
}

// The heap sort function that should be called
void heap_sort(vector<int> &v)
{
    int n = v.size();

    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; --i)
        heapify(v, n, i);
    // Extract element from heap 1 by 1
    for (int i = n - 1; i >= 0; --i)
    {
        swap(v[0], v[i]);
        heapify(v, i, 0);
    }
}


// Testing the heap sort implementation
int main()
{
    vector<int> v = {2, 3, 6, 7, 4, 1};
    heap_sort(v);
    for (size_t i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    return 0;
}
