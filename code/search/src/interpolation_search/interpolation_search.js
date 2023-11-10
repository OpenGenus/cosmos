// implementation with looping
function interpolationSearchRecursion(
  arr,
  value,
  low = 0,
  high = arr.length - 1
) {
  if (arr.length === 0 || (arr.length === 1 && arr[0] !== value)) {
    return -1;
  }

  let mid =
    low +
    parseInt(((value - arr[low]) / (arr[high] - arr[low])) * (arr.length - 1));
  if (mid < 0 || mid >= arr.length) {
    return -1;
  }

  if (arr[mid] === value) {
    return mid;
  } else if (arr[mid] > value) {
    return interpolationSearchRecursion(arr, value, low, mid - 1);
  } else {
    return interpolationSearchRecursion(arr, value, mid + 1, high);
  }
}

// implementation with recursion
function interpolationSearchLooping(arr, value) {
  let low = 0,
    high = arr.length - 1;

  while (low < high) {
    let mid = parseInt(
      ((value - arr[low]) / (arr[high] - arr[low])) * (arr.length - 1)
    );
    if (arr[mid] === value) {
      return mid;
    } else if (arr[mid] > value) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  if (arr[low] === value) {
    return low;
  } else {
    return -1;
  }
}

// test case
const a = [0, 1, 2, 3, 3, 4, 6, 7, 7, 8, 9];

interpolationSearchRecursion(a, 7);
interpolationSearchRecursion(a, 9);
interpolationSearchRecursion(a, -2);

interpolationSearchLooping(a, 7);
interpolationSearchLooping(a, 9);
interpolationSearchLooping(a, -2);
