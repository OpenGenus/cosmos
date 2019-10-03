/* Part of Cosmos by OpenGenus Foundation */
/* Program to find an element in a sorted array using Exponential search. */

function binarySearch(arr, left, right, element) {
  if (right >= left) {
    const mid = left + Math.floor((right - left) / 2);

    if (arr[mid] == element) {
      return mid;
    } else if (arr[mid] > element) {
      return binarySearch(arr, left, mid - 1, element);
    } else {
      return binarySearch(arr, mid + 1, right, element);
    }
  }

  return -1;
}

function exponentialSearch(arr, element) {
  if (arr[0] == element) {
    return 0;
  }

  let i = 1;
  const arrLength = arr.length;
  while (i < arrLength && arr[i] <= element) {
    i *= 2;
  }

  return binarySearch(arr, i / 2, Math.min(i, arrLength), element);
}

const arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
const element = 4;

const found = exponentialSearch(arr, element);
if (found == -1) {
  console.log("Error | Not found");
} else {
  console.log("Found | At position", found + 1);
}
