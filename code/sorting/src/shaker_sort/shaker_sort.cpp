/* Part of Cosmos by OpenGenus Foundation */
/*
 * This is coctail shaker sort (bidirectional bubble sort)
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void shaker_sort(vector<int> &v)
{
    bool swap = false;
    for (unsigned i = 0; i < v.size() / 2; ++i)
    {
        /*
         * Indices of the inner loops result from an
         * invariant of the algorithm. In 'i'th execution
         * of the outer loop, it is guaranteed that the
         * leftmost and rightmost i elements will be sorted.
         * Hence, inner loops only check the others for
         * inversions.
         */

        // Traverse from left to right
        for (unsigned j = i; j < v.size() - i - 1; ++j)
            if (v[j] > v[j + 1])
            {
                // Inversion found - swap elements
                int tmp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = tmp;
                swap = true;
            }

        // Traverse from right to left - hence, bidirectional
        for (unsigned j = v.size() - 2 - i; j > i; j--)
            if (v[j] < v[j - 1])
            {
                // Inversion found - swap elements
                int tmp = v[j];
                v[j] = v[j - 1];
                v[j - 1] = tmp;
                swap = true;
            }
        if (!swap)
            break;                // The array is sorted when
        // there are no elements have been swapped.
    }
}

int main()
{
    int size = 0;
    cout << "Enter size of array: ";
    cin >> size;
    vector<int> source_array;

    for (int i = 0; i < size; ++i)
        source_array.push_back(rand() % 100 + 1);

    cout << "Source array is: ";
    for (int j : source_array)
        cout << j << " ";
    cout << endl;

    shaker_sort(source_array);

    cout << "Sorted array is: ";
    for (int j : source_array)
        cout << j << " ";
    cout << endl;

    return 0;
}
