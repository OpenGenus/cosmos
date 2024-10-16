// Reference: https://rosettacode.org/wiki/Sorting_Algorithms/Circle_Sort

const circlesort = (arr, lo, hi, swaps) => {
  let high;
  let low;
  let mid;
  let t;

  if (lo === hi) {
    return swaps;
  }

  high = hi;
  low = lo;
  mid = Math.floor((hi - lo) / 2);

  while (lo < hi) {
    if (arr[lo] > arr[hi]) {
      t = arr[lo];
      arr[lo] = arr[hi];
      arr[hi] = t;
      swaps++;
    }
    lo++;
    hi--;
  }

  if (lo === hi) {
    if (arr[lo] > arr[hi + 1]) {
      t = arr[lo];
      arr[lo] = arr[hi + 1];
      arr[hi + 1] = t;
      swaps++;
    }
  }

  swaps = circlesort(arr, low, low + mid, swaps);
  swaps = circlesort(arr, low + mid + 1, high, swaps);
  return swaps;
};

const x = [6, 7, 8, 9, 2, 5, 3, 4, 1];

while (circlesort(x, 0, x.length - 1, 0)) {
  console.log(x);
}
