// implementation by looping
function binarySearchLooping(array, key) {
  let lo = 0,
    hi = array.length - 1;

  while (lo <= hi) {
    let mid = Math.floor((lo + hi) / 2, 10);
    let element = array[mid];
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
function binarySearchByRecursion(arr, value, low = 0, high = arr.length - 1) {
  const mid = Math.floor((start + end) / 2);
  if (end === start + 1 && arr[mid] !== value && arr[start] !== value) {
    return -1;
  }

  if (arr[start] === value) {
    return start;
  } else if (arr[end] === value) {
    return end;
  } else if (arr[mid] === value) {
    return mid;
  } else {
    return arr[mid] > value
      ? binarySearchByRecursion(arr, value, start, mid)
      : binarySearchByRecursion(arr, value, mid, end);
  }
}
