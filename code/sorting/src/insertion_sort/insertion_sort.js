// Part of Cosmos by OpenGenus Foundation
function insertionSort(array) {
  var length = array.length;

  for (var i = 1; i < length; i++) {
    var temp = array[i];
    for (var j = i - 1; j >= 0 && array[j] > temp; j--) {
      array[j + 1] = array[j];
    }
    array[j + 1] = temp;
  }

  return array;
}
// insertionSort([1,2,3,4,58,99,1])
