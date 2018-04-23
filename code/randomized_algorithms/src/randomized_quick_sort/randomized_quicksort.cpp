// implementation of quicksort using randomization
// by shobhit(dragon540)
#include <algorithm>
#include <ctime>
#include <iostream>
#include <vector>

void quicksort(std::vector<int> &vect, int low, int high);
int part(std::vector<int> &vect, int low, int high);

int main()
{
    srand(time(NULL));

    std::vector<int> val = {-25, 119, 32, 54, 623, 20, -2, -4, 8, 11};

    // sorts the array in increasing order
    quicksort(val, 0, 10);

    for (int i = 0; i < 10; i++)
        std::cout << val[i] << " ";

    std::cout << '\n';
    return 0;
}
void quicksort(std::vector<int> &vect, int low, int high)
{
    if (low < high)
    {
        int pi = part(vect, low, high);

        quicksort(vect, low, pi - 1);
        quicksort(vect, pi + 1, high);
    }
}
// sort a sub array partially in increasing order
int part(std::vector<int> &vect, int low, int high)
{
    int pivotIndex = low + (rand() % (high - low + 1));
    int pivot = vect[pivotIndex];
    int l = low - 1;

    std::swap(vect[pivotIndex], vect[high]);

    for (int i = low; i < high; ++i)
        if (vect[i] < pivot)
        {
            ++l;
            std::swap(vect[l], vect[i]);
        }
    std::swap(vect[l + 1], vect[high]);

    return l + 1;
}
