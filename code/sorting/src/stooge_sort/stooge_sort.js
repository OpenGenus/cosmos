// Part of Cosmos by OpenGenus Foundation
function stoogeSort(a) {
  function sort(left, right) {
    if (a[left] > a[right]) {
      [a[left], a[right]] = [a[right], a[left]];
    }

    if (right - left > 1) {
      const third = Math.floor((right - left + 1) / 3);
      sort(left, right - third);
      sort(left + third, right);
      sort(left, right - third);
    }
  }
  sort(0, a.length - 1);
}

let l = [4, 7, 2, 8, 1, 9, 3];
stoogeSort(l);
console.log(l);
