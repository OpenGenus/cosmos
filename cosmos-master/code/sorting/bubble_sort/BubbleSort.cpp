/* Part of Cosmos by OpenGenus Foundation */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void bubble_sort(vector<int> &v)
{
    while(1)
    {
        bool swapped = false;
        for(int i = 0; i < v.size() - 1; ++i)
        {
            if (v[i] > v[i + 1])
            {
                swap(v[i], v[i + 1]);
                swapped = true;
            }
        }
        if (!swapped) { break; }
    }
}

// Testing the implemented bubble sort
int main()
{
    vector<int> v = {2, 3, 1, 7, 6};
    bubble_sort(v);
    for(int i = 0; i < v.size(); ++i)
    {
        cout << v[i] << " ";   
    }
    return 0;
}
