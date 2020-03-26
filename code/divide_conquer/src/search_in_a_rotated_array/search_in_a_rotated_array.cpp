/*
Problem statement :
Given a sorted and rotated array A of N distinct elements which is rotated
at some point, and given an element K. The task is to find the index of
the given element K in the array A.
*/

#include <iostream>
#define ll long long int

ll findPivot(ll arr[], ll low, ll high) {

  while (low < high) {
    // find mid element
    ll mid = low + (high - low) / 2;

    if (arr[mid] < arr[0]) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }

  if (arr[low] < arr[0]) {
    return low;
  } else {
    // pivot element does not exist
    return -1;
  }
}

ll findAns(ll arr[], ll k, ll low, ll high) {

  while (low < high) {
    // find mid element
    ll mid = low + (high - low) / 2;

    if (arr[mid] == k) {
      return mid;
    }

    if (arr[mid] >= k) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }

  if (arr[low] == k) {
    return low;
  } else {
    // element does not exist in array
    return -1;
  }
}

int main() {
  ll test, n, k, pivot;
  std::cin >> test; // no. of test cases

  while (test--) {
    std::cin >> n; // size of array
    ll arr[n];
    for (ll i = 0; i < n; i++) {
      std::cin >> arr[i];
    }
    std::cin >> k; // element to be searched

    pivot = findPivot(arr, 0, n - 1); // find pivot element

    if (pivot == -1) {
      // if pivot element does not exist, elements are
      // in ascending order in whole array
      std::cout << findAns(arr, k, 0, n - 1) << "\n";
    } else {
      if (k >= arr[0]) {
        std::cout << findAns(arr, k, 0, pivot - 1) << "\n";
      } else {
        std::cout << findAns(arr, k, pivot, n - 1) << "\n";
      }
    }
  }

  return 0;
}

/*

Input:
3
9
5 6 7 8 9 10 1 2 3
10
3
3 1 2
1
4
3 5 1 2
6

Output:
5
1
-1

*/

