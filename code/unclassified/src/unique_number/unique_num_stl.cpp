#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;
int main() 
{
  int n, i;
  cin >> n;           // size of array element
  vector<int> arr(n); // declaration of vector
  for (i = 0; i < n; i++) 
  {
    cin >> arr[i]; // input
  }
  sort(arr.begin(), arr.end()); // sort the vector
  vector<int>::iterator it = unique(arr.begin(), arr.end());
  arr.resize(distance(arr.begin(), it)); // resizing the array
  cout << arr.size() << "\n"; // display the size of the updated element.
  for (i = 0; i < arr.size(); i++) 
  {
    cout << arr[i] << " "; // display of unique elements in the array
  }
}
