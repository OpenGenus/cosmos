#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using Iter = std::vector<int>::iterator;

Iter partition(vector<int> &v, Iter low, Iter high)
{
  int pivot = *high;
  Iter iter = low - 1;

  for (Iter l = low; l <= (high - 1); l++) {
    if (*l <= pivot) {
      iter_swap(++iter, l);
    }
  }

  iter_swap(iter + 1, high);

  return iter + 1;
}

void quick_sort(vector<int> &v, Iter low, Iter high)
{
  if (low >= high)
    return;

  auto pivot = partition(v, low, high);
  
  quick_sort(v, low, pivot - 1);
  quick_sort(v, pivot + 1, high);
}

// Testing the quick sort implementation
int main()
{
    vector<int> v = {2, 3, 6, 7, 4, 1};
    quick_sort(v, v.begin(), v.end() - 1);
    for (auto &i : v) {
        cout << i << " ";
    }	
    return 0;
}
