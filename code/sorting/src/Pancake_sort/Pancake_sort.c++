#include<bits/stdc++.h>
using namespace std;

void flip(int arr[], int i)                       // Fliping algorithm
{
    int temp, start = 0;
    while (start < i)
    {
        temp = arr[start];
        arr[start] = arr[i];
        arr[i] = temp;
        start++;
        i--;
    }
}

int findMax(int arr[], int n)                   // to find the max element 
{
    int mi = 0;
    for (int i = 0; i < n; ++i)
        if (arr[i] > arr[mi])
            mi = i;
    return mi;
}

void pancakeSort(int arr[], int n)
{
    for (int i = n; i > 1; i--)
    {
        int mi = findMax(arr, i);
        if (mi != i - 1)
        {
            flip(arr, mi);
            flip(arr, i - 1);
        }
    }
}
int main() {

    int n = 6;
    int arr[6] = {5, 3, 4, 2, 1, 6};
    cout << "Input arr: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    pancakeSort(arr, n); // Sort elements in ascending order
    cout << "Output arr: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}