//  divide conquer | inversion count | Javascript
//  Part of Cosmos by OpenGenus Foundation

function mergeSort(arr, size) {
  if (array.length === 0 || array.length === 1) return 0;
  var temp = [];
  return mergeSortHelper(arr, temp, 0, size - 1);
}

function mergeSortHelper(arr, temp, left, right) {
  var inv_count,
    mid = 0;
  if (right > left) {
    mid = (right + left) / 2;

    /* sum the number of inversions from all parts */
    inv_count = mergeSortHelper(arr, temp, left, mid);
    inv_count += mergeSortHelper(arr, temp, mid + 1, right);

    inv_count += merge(arr, temp, left, mid + 1, right);
  }
  return inv_count;
}

function merge(arr, temp, left, mid, right) {
  var inv_count = 0;

  var i = left;
  var j = mid;
  var k = left;

  while (i <= mid - 1 && j <= right) {
    if (arr[i] <= arr[j]) {
      temp[k++] = arr[i++];
    } else {
      temp[k++] = arr[j++];

      /* remaining elements in subarray arr[i] to arr[mid] are sorted and grater than arr[j] */
      inv_count = inv_count + (mid - i);
    }
  }

  /* Copy remaining elements*/
  while (i <= mid - 1) temp[k++] = arr[i++];
  while (j <= right) temp[k++] = arr[j++];

  /*merge into original array*/
  for (i = left; i <= right; i++) arr[i] = temp[i];

  return inv_count;
}

console.log(mergeSort([5, 10, 4, 8, 2], 5));
