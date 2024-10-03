#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &v, int lo, int hi)
{
    int pivot = v[hi];
    int i = lo - 1;
    for(int j = lo; j <= hi - 1; ++j)
    {
        if (v[j] <= pivot)
        {
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i + 1], v[hi]);
    return (i + 1);
}

void quick_sort(vector<int> &v, int lo, int hi)
{
    if (lo < hi)
    {
        int pi = partition(v, lo, hi);
        // Separately sort elements
        quick_sort(v, lo, pi - 1);
        quick_sort(v, pi + 1, hi);
    } 
}

// Testing the quick sort implementation
int main()
{
    vector<int> v = {2, 3, 6, 7, 4, 1};
    quick_sort(v, 0, v.size());
    for(int i = 0; i < v.size(); ++i)
    {
        cout << v[i] << " ";
    }	
    return 0;
}
