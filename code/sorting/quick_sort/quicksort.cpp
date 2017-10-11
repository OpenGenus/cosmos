/* Part of Cosmos by OpenGenus Foundation */

#include <vector>
#include <iostream>
#include <algorithm> /* for random_shuffle */
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

void quicksort(vector<int> &v, int lo, int hi)
{
    if (lo < hi)
    {
        int pi = partition(v, lo, hi);
        // Separately sort elements
        quicksort(v, lo, pi - 1);
        quicksort(v, pi + 1, hi);
    } 
}

void print(vector<int> &v)
{
    for(int i = 0; i < v.size(); ++i)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

// Testing the quick sort implementation
int main()
{
    vector<int> v;
    for (int i = 1; i <= 10; i++)
      v.push_back(i);
    random_shuffle(v.begin(), v.end());

    print(v);
    quicksort(v, 0, v.size() - 1);
    print(v);
    return 0;
}
