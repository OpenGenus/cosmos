#include <cstdlib>
#include <iostream>
#include <vector>

void merge(std::vector<int> arr, std::vector<int> arr1, std::vector<int> arr2) {
    int k = 0;
    for (int val : arr1) {
        arr[k] = val;
        k++;
    }
    for (int val : arr2) {
        arr[k] = val;
        k++;
    }

    std::cout << "Merged array : \n";
    for (int val : arr)
        std::cout << val << "\t";
}

int main() {
    int n1, n2;
    std::cout << "Enter the size of array 1 : \n";
    std::cin >> n1;
    std::cout << "Enter the size of array 2: \n";
    std::cin >> n2;
    std::vector<int> arr1(n1);
    std::vector<int> arr2(n2);
    std::vector<int> arr(n1 + n2);
    std::cout << "Enter the values for array1 : \n";
    for (int i = 0; i < n1; ++i) {
        int val;
        std::cin >> val;
        arr1[i] = val;
    }

    std::cout << "Enter the values for array2 : \n";
    for (int i = 0; i < n2; ++i) {
        int val;
        std::cin >> val;
        arr2[i] = val;
    }
    merge(arr, arr1, arr2);
}

/*Sample Input Output
Enter the size of array 1 :
5
Enter the size of array 2:
2
Enter the values for array1 :
10 12 14 16 18
Enter the values for array2 :
-10 -20
Merged array :
10	12	14	16	18	-10	-20
*/
