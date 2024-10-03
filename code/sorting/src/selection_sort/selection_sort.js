// Part of Cosmos by OpenGenus Foundation
function selectionSort(inputArray) {
  var len = inputArray.length;
  for (var i = 0; i < len; i++) {
    var minAt = i;
    for (var j = i + 1; j < len; j++) {
      if (inputArray[j] < inputArray[minAt]) minAt = j;
    }

    if (minAt != i) {
      var temp = inputArray[i];
      inputArray[i] = inputArray[minAt];
      inputArray[minAt] = temp;
    }
  }
  return inputArray;
}
