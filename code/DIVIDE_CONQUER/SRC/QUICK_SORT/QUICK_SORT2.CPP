#include <iostream>
using namespace std;

void swapit(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int Mpartition(int arr[], int low, int high)
{
    int i = low - 1;
    int j = low;
    for (; j < high; j++)
        if (arr[high] < arr[j])
        {
            i++;
            swapit(&arr[j], &arr[i]);
        }
    swapit(&arr[high], &arr[i + 1]);
    return i + 1;

}

void quicksort(int arr[], int low, int high)
{

    if (low < high)
    {
        int pi = Mpartition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }

}
int main()
{
    int arr[] = {14, 15, 13, 44, 56, 23, 8, 78, 36, 72};
    int arrsize = sizeof(arr) / sizeof(arr[0]) - 1;
    quicksort(arr, 0, arrsize);
    for (int i = 0; i < 9; i++)
        cout << arr[i] << endl;

}
