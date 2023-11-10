#include <iostream>
#include <vector>
#include <stack>

using namespace std;


int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}


void quickSort(vector<int>& arr, int low, int high) {
    stack<pair<int, int>> stk;
    stk.push({low, high});

    while (!stk.empty()) {
        pair<int, int> current = stk.top();
        stk.pop();
        low = current.first;
        high = current.second;

        int pivotIndex = partition(arr, low, high);

        if (pivotIndex - 1 > low) {
            stk.push({low, pivotIndex - 1});
        }

        if (pivotIndex + 1 < high) {
            stk.push({pivotIndex + 1, high});
        }
    }
}

int main() {
    cout << "Quick Sort using Stack" << endl;

    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
