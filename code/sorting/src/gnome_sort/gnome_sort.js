function gnomeSort(arr) {
  let index = 0;

  while (index <= arr.length) {
    if (index > 0 && arr[index - 1] > arr[index]) {
      let tmp = arr[index];
      arr[index] = arr[index - 1];
      arr[index - 1] = tmp;
      --index;
    } else {
      --index;
    }
  }
}

// test case
const a = [3, 6, 2, 9, 8, 1, 4, 0, 3, 7, 7];
console.log(gnomeSort(a));
