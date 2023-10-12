#include <iostream>
#include <vector>

using namespace std;

// Function to perform insertion sort on a subarray
void insertionSort(vector<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

// Function to merge two subarrays
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> leftArr(n1);
    vector<int> rightArr(n2);

    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }

    for (int i = 0; i < n2; i++) {
        rightArr[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
        }
    }

    while (i < n1) {
        arr[k++] = leftArr[i++];
    }

    while (j < n2) {
        arr[k++] = rightArr[j++];
    }
}

// Function to perform merge sort with insertion sort optimization
void mergeSort(vector<int>& arr, int left, int right, int k) {
    if (right - left + 1 <= k) {
        insertionSort(arr, left, right);
    } else if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid, k);
        mergeSort(arr, mid + 1, right, k);

        merge(arr, left, mid, right);
    }
}

int main() {
    cout << "Merge Sort with Insertion Sort Optimization" << endl;

    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cout << "Enter the threshold for insertion sort (e.g., 10): ";
    cin >> k;

    mergeSort(arr, 0, n - 1, k);

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
