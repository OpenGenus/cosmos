/* Part of Cosmos by OpenGenus Foundation */

#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

/* Utility functions */

void fill(vector<int> &v)
{
    for (auto& elem : v)
        elem = rand() % 100;
}

void printarr(vector<int> &v)
{
    for (const auto& elem : v)
        cout << elem << " ";
    cout << "\n";
}

/* Binary search with fewer comparisons */
int binary_search(vector<int> &v, int key)
{
    int m;

    int l = 0, r = v.size();

    while (r - l > 1)
    {
        m = l + (r - l) / 2;

        if (v[m] > key)
            r = m;
        else
            l = m;
    }

    if (v[l] == key)
        return l;
    else
        return -1;
}

/* Driver program */
int main()
{
    int size;
    cout << "Enter the array size:";
    cin >> size;

    vector<int> v(size);
    fill(v);

    cout << "Array (sorted) : ";
    sort(v.begin(), v.end());
    printarr(v);

    cout << "Search for (input search key) : ";
    int key;
    cin >> key;

    cout << "Found " << key << " at index " << binary_search(v, key) << endl;
}
