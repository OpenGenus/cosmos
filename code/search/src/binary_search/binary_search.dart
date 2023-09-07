/*
 Part of Cosmos by OpenGenus Foundation
*/

import 'dart:math';

// Binary Search Recursive
int binarySearchRecursive(List arr, int l, int r, int x) {
  if (r >= l) {
    int mid = l + ((r - l) / 2).floor();
    if (arr[mid] == x) {
      return mid;
    }
    if (arr[mid] > x) {
      return binarySearchRecursive(arr, l, mid - 1, x);
    } else {
      return binarySearchRecursive(arr, mid + 1, r, x);
    }
  }
  return -1;
}

// Binary Search Iterative
int binarySearchIterative(List arr, int l, int r, int x) {
  // While right is greater than or equal to left
  while (r >= l) {
    // find middle of array
    var mid = l + ((r - l) ~/ 2).toInt();
    // if the middle is equal to x return mid as the index
    if (arr[mid] == x) {
      return mid;
    }
    // if x is less than the middle element of the array search left
    if (x < arr[mid]) {
      r = mid - 1;
    }
    // if x is greater than the middle element of the array search right
    else {
      l = mid + 1;
    }
  }
  // If x is not found within the array return -1
  return -1;
}

List<int> randomIntList({required int length, int range = 5}) {
  Random rand = Random();
  List<int> result = [for (var i = 0; i < length; i++) rand.nextInt(range)];
  return result;
}

int main() {
  List arr = randomIntList(length: 75, range: 275);
  arr.sort();
  int x = 136;
  print(arr);
  print(
      "Find Index | Binary Search Recursive: ${binarySearchRecursive(arr, 0, arr.length - 1, x)}");
  print(
      "Find Index | Binary Search Iterative: ${binarySearchIterative(arr, 0, arr.length - 1, x)}");
  print("Find Index | List.indexOf Method: ${arr.indexOf(x)}");
  return 0;
}
