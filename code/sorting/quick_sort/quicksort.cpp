#include <iostream>
#include <vector>

int partition(std::vector<int> &vec, int low, int high)
{
  int pivot = vec[high];
  int index = low - 1;

  for (int l = low; l <= (high - 1); l++) {
    if (vec[l] <= pivot) {
      index++;
      std::swap(vec[index], vec[l]);
    }
  }

  std::swap(vec[index + 1], vec[high]);

  return index + 1;
}

void quick_sort(std::vector<int> &vec, int low, int high)
{
  if (low >= high)
    return;

  int index = partition(vec, low, high);

  quick_sort(vec, low, index - 1);
  quick_sort(vec, index + 1, high);
}

int main()
{
  std::vector<int> v { 7, 5, 3, 4, 10, 8, 9, 1, 2, 6 };

  quick_sort(v, 0, v.size() - 1);

  for (auto& i : v)
    std::cout << i << ' ';
  
  std::cout << std::endl;
}
