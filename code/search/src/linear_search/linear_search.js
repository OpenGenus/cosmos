/*
 * Part of Cosmos by OpenGenus Foundation
 */

/*
 * Input    :   An integer array and the element to be searched
 * Output   :   If found returns the index of element or else -1
 * Example  :
 *              var index = linearSearch([1, 2, 3, 4, 7, 8], 8);
 *
 */
function linearSearch(arr, element) {
  for (var i = 0; i < arr.length; i++) {
    if (arr[i] === element) {
      return i;
    }
  }
  return -1;
}
