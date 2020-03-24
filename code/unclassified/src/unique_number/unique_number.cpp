#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <vector>

void display_unique(std::vector<int> arr, int n) {
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; ++i) {
        while (i < n - 1 && arr[i] == arr[i + 1])
            i++;
        std::cout << arr[i] << " ";
    }
}

int main() {
    int n, val;
    std::cout << "Enter the size of array : \n";
    std::cin >> n;
    std::vector<int> arr;
    cout << "Enter the values for the array : \n";
    for (int i = 0; i < n; ++i) {
        std::cin >> val;
        arr.push_back(val);
    }
    std::cout << "The unique elements are : \n";
    display_unique(arr, n);

    return 0;
}

/*Sample Input- Output
Enter the size of array :
5
Enter the values for the array :
12 34 15 12 16
The unique elements are :
12 15 16 34
*/
