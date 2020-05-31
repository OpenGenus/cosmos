#include <cstdlib>
#include <iostream>
#include <vector>

void move_zeroes(std::vector<int> arr, std::vector<int> a, int n) {
    int k = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] != 0) {
            arr.push_back(a[i]);
            k++;
        }
    }
    for (int i = k; i < n; ++i) {
        arr.push_back(0);
    }

    for (int i = 0; i < n; ++i)
        std::cout << arr[i] << " ";
}

int main() {
    int n;
    std::cout << "Enter the size of array : \n";
    std::cin >> n;
    std::vector<int> a, arr;
    int val;
    std::cout << "Enter the values for the array : \n";
    for (int i = 0; i < n; i++) {
        std::cin >> val;
        a.push_back(val);
    }
    move_zeroes(arr, a, n);
    return 0;
}

/*Sample Input-Output
Enter the size of array :
8
Enter the values for the array :
12 0 18 13 0 0 11 0
12 18 13 11 0 0 0 0
*/

