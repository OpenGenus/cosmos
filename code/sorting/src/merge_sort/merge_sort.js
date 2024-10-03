var a = [34, 203, 3, 746, 200, 984, 198, 764, 9];
// Part of Cosmos by OpenGenus Foundation
function mergeSort(arr) {
  if (arr.length < 2) return arr;

  var middle = parseInt(arr.length / 2);
  var left = arr.slice(0, middle);
  var right = arr.slice(middle, arr.length);

  return merge(mergeSort(left), mergeSort(right));
}

function merge(left, right) {
  var result = [];

  while (left.length && right.length) {
    if (left[0] <= right[0]) {
      result.push(left.shift());
    } else {
      result.push(right.shift());
    }
  }

  while (left.length) result.push(left.shift());

  while (right.length) result.push(right.shift());

  return result;
}

console.log(mergeSort(a));
