#include <iostream>
using namespace std;

void swapit(int *x, int *y)         //function to swap two integer values(passed by value)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int Mpartition(int arr[], int low, int high)        
    //functon to return the position of pivot after arranging smaller elements to its left and larger elements to its right 
{
    int i = low - 1;    //i points to the last element that was smaller than the pivot while traversing 
    int j = low;        //j points to the current element while traversing 
    for (; j < high; j++)       
        if (arr[high] < arr[j])
        {
            i++;
            swapit(&arr[j], &arr[i]);
        }
    swapit(&arr[high], &arr[i + 1]);        //swaps the pivot with the first element sequentially that is greater than the pivot
    return i + 1;

}

void quicksort(int arr[], int low, int high)        // function which implements divide and conquer
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
