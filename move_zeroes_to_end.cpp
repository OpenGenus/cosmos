#include <iostream>
#include <stdlib.h>

void move_zeroes(int arr[], int a[], int n) {
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != 0) {
            arr[k] = a[i];
            k++;
        }
    }
    for (int i = k; i < n; i++) {
        arr[i] = 0;
    }

    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
}

int main() {
    int n;
    std::cout << "Enter the size of array : \n";
    std::cin >> n;
    int a[n], arr[n];
    std::cout << "Enter the values for the array : \n";
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
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
