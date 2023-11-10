/**
 *
 * @param {string} longest One of the two strings for biggest common suffix
 * @param {string} shortest One of the two strings for biggest common suffix. It serves terminating condition for algorithm
 * @param {number} accumulator counter for common characters found
 * @returns {number} counter for no of characters matched
 */
const countMaxSuffix = (longest, shortest, accumulator) => {
  if (shortest.length == 0 || shortest.slice(-1) != longest.slice(-1))
    return accumulator;

  return countMaxSuffix(
    longest.slice(0, -1),
    shortest.slice(0, -1),
    ++accumulator
  );
};

/**
 *
 * @param {string} first One of the two strings for biggest common suffix
 * @param {string} second One of the two strings for biggest common suffix. It serves terminating condition for algorithm
 * @returns {string} suffix biggest suffix of given two strings
 */
const findBiggestSuffix = (first, second) => {
  if (first.length <= 0 || second.length <= 0) {
    return 'No Suffix';
  }

  const [shortest, longest] = [first, second].sort();
  const charsMatched = countMaxSuffix(longest, shortest, 0);

  return charsMatched == 0 ? 'No Suffix' : longest.slice(-charsMatched);
};

// Tests
console.log(findBiggestSuffix('abcdef', 'def')); // def
console.log(findBiggestSuffix('abc', 'abc')); // abc
console.log(findBiggestSuffix('abcdef', 'abc')); // 'No Suffix'
