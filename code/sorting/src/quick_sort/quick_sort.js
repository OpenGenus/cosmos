/*Part of Cosmos by OpenGenus Foundation*/
//here a is the array name

/*low is the initial index for sorting 
i.e. 0 for sorting whole array*/

/*high is the ending index for sorting 
i.e. array's length for sorting whole array*/

/*expected call for the function is as follows:
quickSort(array, 0, array.length -1);*/

function quickSort(a, low, high) {
  var i = low;
  var j = high;
  var temp;
  var k = (low + high) / 2; //k is pivot index
  var pivot = parseInt(
    a[k.toFixed()]
  ); /*k may be a fraction, toFixed takes it to the nearest integer*/

  while (i <= j) {
    while (parseInt(a[i]) < pivot) i++;

    while (parseInt(a[j]) > pivot) j--;

    if (i <= j) {
      temp = a[i];
      a[i] = a[j];
      a[j] = temp;
      i++;
      j--;
    }
  }

  if (low < j) quickSort(a, low, j);
  if (i < high) quickSort(a, i, high);
  return a;
}
