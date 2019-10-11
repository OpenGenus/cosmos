/**
 * Perform a pigeonhole sort on an array of ints.
 * @param {Array} - array of ints
 * @returns {Array} - sorted array of ints
 */
function pigeonholeSort(array) {
  // Figure out the range. This part isn't really the algorithm, it's
  // figuring out the parameters for it.
  const max = Math.max(...array);
  const min = Math.min(...array);
  const numHoles = max - min + 1;

  // Create pigeonholes
  let holes = Array(numHoles).fill(0);

  // Populate pigeonholes with items
  for (let item of array) {
    holes[item - min] += 1;
  }

  let sortedArray = [];
  for (let i = 0; i < holes.length; i++) {
    while (holes[i] > 0) {
      sortedArray.push(i + min);
      holes[i] -= 1;
    }
  }
  return sortedArray;
}

/* For example:
let array = [5, 2, 8, 9, 10, 1, 3];
console.log(pigeonholeSort(array));
> [ 1, 2, 3, 5, 8, 9, 10 ]
*/
