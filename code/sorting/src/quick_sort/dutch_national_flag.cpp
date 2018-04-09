/* Part of Cosmos by OpenGenus Foundation */

#include <vector>
#include <stdlib.h>
#include <iostream>

using namespace std;

// Dutch National Flag Sort for array items 0,1,2
void flagSort(vector<int> &v)
{
    int lo = 0;
    int hi = v.size() - 1;
    int mid = 0;

    while (mid <= hi)
        switch (v[mid])
        {
        case 0:
            swap(v[lo++], v[mid++]);
            break;
        case 1:
            mid++;
            break;
        case 2:
            swap(v[mid], v[hi--]);
            break;
        }
}

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


void flagFill(vector<int> &v)
{
    for (size_t i = 0; i < v.size(); ++i)
        v[i] = rand() % 3;
}

// Driver program
int main()
{
    int size = 10;
    cout << "Input test array size: ";
    cin >> size;
    vector<int> v(size);

    flagFill(v);
    cout << "Unsorted: ";
    printarr(v);
    flagSort(v);
    cout << "Sorted:   ";
    printarr(v);

    return 0;
}
