#include <iostream>
#include <stdlib.h>

void merge(int arr[], int arr1[], int arr2[], int n1, int n2) {
  int k = 0;
  for (int i = 0; i < n1; ++i) {
    arr[k] = arr1[i];
    k++;
  }
  for (int i = 0; i < n2; ++i) {
    arr[k] = arr2[i];
    k++;
  }
}

int main() {
  int n1, n2;
  std::cout << "Enter the size of array 1 : \n";
  std::cin >> n1;
  std::cout << "Enter the size of array 2: \n";
  std::cin >> n2;
  int arr1[n1], arr2[n2], arr[n1 + n2];
  std::cout << "Enter the values for array1 : \n";
  for (int i = 0; i < n1; i++)
    std::cin >> arr1[i];
  std::cout << "Enter the values for array2 : \n";
  for (int i = 0; i < n2; i++)
    std::cin >> arr2[i];
  merge(arr, arr1, arr2, n1, n2);
  std::cout << "Merged array : \n";
  for (int i = 0; i < n1 + n2; i++)
    std::cout << arr[i] << "\t";
}

