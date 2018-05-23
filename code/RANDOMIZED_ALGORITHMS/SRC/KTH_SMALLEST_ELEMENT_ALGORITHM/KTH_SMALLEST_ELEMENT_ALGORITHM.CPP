#include <iostream>
#include <climits>
#include <cstdlib>
using namespace std;
// Part of Cosmos by OpenGenus Foundation
int randomPartition(int arr[], int l, int r);


// QuickSort based method. ASSUMPTION: ELEMENTS IN ARR[] ARE DISTINCT
int kthSmallest(int arr[], int l, int r, int k)
{
    // If k is smaller than number of elements in array
    if (k > 0 && k <= r - l + 1)
    {
        // Partition the array around a random element and
        // get position of pivot element in sorted array
        int pos = randomPartition(arr, l, r);

        // If position is same as k
        if (pos - l == k - 1)
            return arr[pos];
        if (pos - l > k - 1) // If position is more, recur for left subarray
            return kthSmallest(arr, l, pos - 1, k);

        // Else recur for right subarray
        return kthSmallest(arr, pos + 1, r, k - pos + l - 1);
    }


    return INT_MAX;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Standard partition process of QuickSort().  It considers the last
// element as pivot and moves all smaller element to left of it and
// greater elements to right. This function is used by randomPartition()
int partition(int arr[], int l, int r)
{
    int x = arr[r], i = l;
    for (int j = l; j <= r - 1; j++)
        if (arr[j] <= x)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
    swap(&arr[i], &arr[r]);
    return i;
}

// Picks a random pivot element between l and r and partitions
// arr[l..r] arount the randomly picked element using partition()
int randomPartition(int arr[], int l, int r)
{
    int n = r - l + 1;
    int pivot = rand() % n;
    swap(&arr[l + pivot], &arr[r]);
    return partition(arr, l, r);
}


int main()
{
    int n;
    int k;
    int arr[1000000];
    cout << "Enter the no. of elements in array" << endl;
    cin >> n;
    cout << "Enter the elements of the array seprated by single space" << endl;
    for (int x = 0; x < n; x++)
        cin >> arr[x];
    cout << "Enter k (nth smallest element to be find)" << endl;
    cin >> k;
    cout << endl;
    cout << "kth smallest element is  " << kthSmallest(arr, 0, n - 1, k);
    cout << endl;
    return 0;
}
