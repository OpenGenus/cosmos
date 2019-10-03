/* Part of Cosmos by OpenGenus Foundation */

#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>

/* Utility functions */

void fill(std::vector<int> &v)
{
    for (auto& elem : v)
        elem = rand() % 100;
}

void printArr(std::vector<int> &v)
{
    for (const auto& elem : v)
        std::cout << elem << " ";
    std::cout << "\n";
}

/* Binary search with fewer comparisons */
int binarySearch(std::vector<int> &v, int key)
{
    int l = 0, r = v.size();

    while (r - l > 1)
    {
        int m = l + (r - l) / 2;

        if (v[m] > key)
            r = m;
        else
            l = m;
    }

    return (v[l] == key) ? l : -1;
}

/* Driver program */
int main()
{
    int size;
    std::cout << "Enter the array size:";
    std::cin >> size;

    std::vector<int> v(size);
    fill(v);

    std::cout << "Array (sorted) : ";
    sort(v.begin(), v.end());
    printArr(v);

    int key;
    std::cout << "Search for (input search key) : ";
    std::cin >> key;

    std::cout << "Found " << key << " at index " << binarySearch(v, key) << "\n";
}
