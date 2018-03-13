// implementation by looping
function binarySearch(array, key) {
  var lo = 0,
    hi = array.length - 1,
    mid,
    element;
  while (lo <= hi) {
    mid = Math.floor((lo + hi) / 2, 10);
    element = array[mid];
    if (element < key) {
      lo = mid + 1;
    } else if (element > key) {
      hi = mid - 1;
    } else {
      return mid;
    }
  }
  return -1;
}

// implementation by recursion
/**
 *
 * @param {* number[]} arr - the sorted array to be searched in
 * @param {* number} value - the value to be searched
 * @param {* number} low - the start index of the search range
 * @param {* number} high - the end index of the search range
 */
function binarySearchByRecursion(arr, value, low, high) {
  var start = low === undefined ? 0 : low;
  var end = high === undefined ? arr.length - 1 : high;
  var middle = Math.floor((start + end) / 2);
  if (end === start + 1 && arr[middle] !== value && arr[start] !== value) {
    return -1;
  }
  if (arr[start] === value) {
    return start;
  } else if (arr[end] === value) {
    return end;
  } else if (arr[middle] === value) {
    return middle;
  } else {
    if (arr[middle] > value) {
      return binarySearchByRecursion(arr, value, start, middle);
    } else {
      return binarySearchByRecursion(arr, value, middle, end);
    }
  }
}
