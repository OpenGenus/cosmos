#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n, i;
    std::cin >> n;           // size of array element
    std::vector<int> arr(n); // declaration of vector
    for (i = 0; i < n; ++i) {
        std::cin >> arr[i]; // input
    }
    std::sort(arr.begin(), arr.end()); // sort the vector
    std::vector<int>::iterator it = unique(arr.begin(), arr.end());
    arr.resize(distance(arr.begin(), it)); // resizing the array
    std::cout << arr.size() << "\n"; // display the size of the updated element.
    for (i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << " "; // display of unique elements in the array
    }
}
