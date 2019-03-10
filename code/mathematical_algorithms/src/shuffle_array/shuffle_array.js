/* Part of Cosmos by OpenGenus Foundation */

//shuffle_array - Randomly shuffle an array
//Note: This method changes the original array.

function shuffle_array(arr) {
  if (!Array.isArray(arr)) {
    //If not an array return arr
    return arr;
  }
  return arr.sort((a, b) => {
    return Math.random() - 0.5;
  });
}
