/**
 * Cycle Sort Implementation in JavaScript
 *
 * @author  Ahmar Siddiqui <ahmar.siddiqui@gmail.com>
 * @github @ahhmarr
 * @date   07/Oct/2017
 * Part of Cosmos by OpenGenus Foundation
 */

const cycleSort = array => {
  // last record will already be in place
  for (let start = 0; start < array.length - 1; start++) {
    let record = array[start];

    // find where to put the record
    let pos = start;
    for (let i = start + 1; i < array.length; i++) {
      if (array[i] < record) pos += 1;
    }

    // if the record is already there, this is not a cycle
    if (pos == start) continue;

    // otherwise, put the record there or right after any duplicates
    while (record == array[pos]) {
      pos++;
    }
    const swap = array[pos];
    array[pos] = record;
    record = swap;

    // rotate the rest of the cycle
    while (pos != start) {
      // find where to put the record
      pos = start;
      for (let i = start + 1; i < array.length; i++) {
        if (array[i] < record) pos += 1;
      }

      // put the record there or right after any duplicates
      while (record == array[pos]) {
        pos += 1;
      }
      const swap = array[pos];
      array[pos] = record;
      record = swap;
    }

    return array;
  }
};

console.log(cycleSort([3, 2, 1, 4]));
