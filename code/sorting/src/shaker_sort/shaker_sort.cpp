/* Part of Cosmos by OpenGenus Foundation */
/*
 * This is coctail shaker sort (bidirectional buble sort)
 */

#include <iostream>
#include <vector>
#include <algorithm>

void shaker_sort(std::vector<int> &v)
{
    bool swap = false;
    for (unsigned i = 0; i < v.size() / 2; ++i)
    {
        for (unsigned j = i; j < v.size() - i - 1; ++j)
            if (v[j] > v[j + 1])
            {
                int tmp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = tmp;
                swap = true;
            }
        for (unsigned j = v.size() - 2 - i; j > i; --j)
            if (v[j] < v[j - 1])
            {
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
    std::cout << "Enter size of array: ";
    std::cin >> size;
    std::vector<int> source_array;

    for (int i = 0; i < size; ++i)
        source_array.push_back(rand() % 100 + 1);

    std::cout << "Source array is: ";

    for (int j : source_array)
        std::cout << j << " ";
    std::cout << "\n";

    shaker_sort(source_array);

    std::cout << "Sorted array is: ";

    for (int j : source_array)
        std::cout << j << " ";
    std::cout << "\n";

    return 0;
}