// Segregate positive and negative numbers in an array
// Here, we try to place all negative numbers to the left
// and all positive elements to the right in O(n) time.
// We can achieve this using Sorting also. But that takes O(nlogn) time.
#include <iostream>
#include <cstdlib>

// Similar to the partition function in Quicksort
// with pivot as 0
void segregate_pos_neg(int a[], int n) {
    int left = 0;
    int right = n - 1;
    while (1) {
        while (a[left] < 0 && left < right)
            left++;
        while (a[right] > 0 && left < right)
            right--;
        if (left < right) {
            int temp = a[left];
            a[left] = a[right];
            a[right] = temp;
        } else
            break;
    }
}

int main() {
    int n;
    std::cout << "Enter the size of the array :  ";
    std::cin >> n;
    // allocating heap memory for array
    int *a = new int[n];
    std::cout << "Enter the values of the array  : \n";
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    segregate_pos_neg(a, n);
    std::cout << "Array after partition function\n";
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << "\t";
    }
}

/*
Enter the size of the array :  8
Enter the values of the array  :
-1 4 5 9 -12 -15 7 21
Array after partition function
-1	-15	-12	9	5	4	7	21
*/
