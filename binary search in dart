void main() {
  List<int> arr = [0, 1, 3, 4, 5, 8, 9, 22];
  int userValue = 3;
  int min = 0;
  int max = arr.length - 1;
  binarySearch(arr, userValue, min, max);
}

binarySearch(List<int> arr, int userValue, int min, int max) {
  if (max >= min) {
    print('min $min');
    print('max $max');
    int mid = ((max + min) / 2).floor();
    if (userValue == arr[mid]) {
      print('your item is at index: ${mid}');
    } else if (userValue > arr[mid]) {
      binarySearch(arr, userValue, mid + 1, max);
    } else {
      binarySearch(arr, userValue, min, mid - 1);
    }
  }
  return null;
}
