/*
 * Part of Cosmos by OpenGenus Foundation
 */

var arrayLength;

function heap_root(inputArray, i) {
  var left = 2 * i + 1;
  var right = 2 * i + 2;
  var max = i;

  if (left < arrayLength && inputArray[left] > inputArray[max]) {
    max = left;
  }

  if (right < arrayLength && inputArray[right] > inputArray[max]) {
    max = right;
  }

  if (max != i) {
    swap(inputArray, i, max);
    heap_root(inputArray, max);
  }
}

function swap(inputArray, index_A, index_B) {
  var temp = inputArray[index_A];

  inputArray[index_A] = inputArray[index_B];
  inputArray[index_B] = temp;
}

function heapSort(inputArray) {
  arrayLength = inputArray.length;

  for (var i = Math.floor(arrayLength / 2); i >= 0; i -= 1) {
    heap_root(inputArray, i);
  }

  for (i = inputArray.length - 1; i > 0; i--) {
    swap(inputArray, 0, i);
    arrayLength--;
    heap_root(inputArray, 0);
  }
}
