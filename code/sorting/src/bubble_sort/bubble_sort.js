/* Part of Cosmos by OpenGenus Foundation */
function bubbleSort(items) {
  var length = items.length;
  for (var i = length - 1; i >= 0; i--) {
    //Number of passes
    for (var j = length - i; j > 0; j--) {
      //Compare the adjacent positions
      if (items[j] < items[j - 1]) {
        //Swap the numbers
        var tmp = items[j];
        items[j] = items[j - 1];
        items[j - 1] = tmp;
      }
    }
  }
  return items;
}
// var collections = [9, 4, 5, 2, 1, 6, 7, 0, 3];
// bubbleSort(collections);
