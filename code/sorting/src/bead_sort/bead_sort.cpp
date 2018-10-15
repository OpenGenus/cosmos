#include <vector>
#include <iostream>
using namespace std;

#define BEAD(i, j) beads[i * max + j]

// Part of Cosmos by OpenGenus Foundation
// function to perform the above algorithm
void beadSort(vector<int>& a)
{
    // Find the maximum element
    int max = a[0];
    for (size_t i = 1; i < a.size(); ++i)
        if (a[i] > max)
            max = a[i];

    // allocating memory
    vector<unsigned char> beads(max * a.size(), 0);

    // mark the beads
    for (size_t i = 0; i < a.size(); ++i)
        for (int j = 0; j < a[i]; ++j)
            BEAD(i, j) = 1;

    for (int j = 0; j < max; ++j)
    {
        // count how many beads are on each post
        int sum = 0;
        for (size_t i = 0; i < a.size(); ++i)
        {
            sum += BEAD(i, j);
            BEAD(i, j) = 0;
        }

        // Move beads down
        for (size_t i = a.size() - sum; i < a.size(); ++i)
            BEAD(i, j) = 1;
    }

    // Put sorted values in array using beads
    for (size_t i = 0; i < a.size(); ++i)
    {
        int j;
        for (j = 0; j < max && BEAD(i, j); ++j)
            ;

        a[i] = j;
    }
}

// driver function to test the algorithm
int main()
{
    vector<int> a{5, 3, 1, 7, 4, 1, 1, 20};

    beadSort(a);

    cout << "After Sorting.. " << endl;
    for (size_t i = 0; i < a.size(); ++i)
        cout << a[i] << " ";

    return 0;
}
