#include <algorithm>
#include <iostream>
#include <stdlib.h>
using namespace std;

void display_unique(int arr[], int n) {
  sort(arr, arr + n);
  for (int i = 0; i < n; ++i) {
    while (i < n - 1 && arr[i] == arr[i + 1])
      i++;
    cout << arr[i] << " ";
  }
}

int main() {
  int n;
  cout << "Enter the size of array : \n";
  cin >> n;
  int arr[n];
  cout << "Enter the values for the array : \n";
  for (int i = 0; i < n; ++i)
    cin >> arr[i];
  cout << "The unique elements are : \n";
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

