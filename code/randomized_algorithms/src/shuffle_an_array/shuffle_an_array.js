// Part of Cosmos by OpenGenus Foundation

// This is a JavaScript implementation of Fisher-Yates shuffle based on
// [lodash/shuffle.js](https://github.com/lodash/lodash/blob/master/shuffle.js).
// This use `crypto` module if possible to provide stronger pseudo randomness.

const provideRandomSeed = (function() {
  if (require && require.resolve && require.resolve("crypto")) {
    const crypto = require("crypto");
    return function() {
      return crypto.randomBytes(1)[0] / 255;
    };
  } else {
    return Math.random;
  }
})();

/**
 * Creates an array of shuffled values.
 *
 * @param {Array} array The array to shuffle.
 * @returns {Array} Returns the new shuffled array.
 * @example
 *
 * shuffle([1, 2, 3, 4])
 * // => [3, 1, 4, 2]
 */
module.exports = function shuffle(array) {
  const length = array == null ? 0 : array.length;
  if (!length) {
    return [];
  }

  let index = -1;
  const lastIndex = length - 1;
  const result = Array.from(array);
  while (++index < length) {
    const rand =
      index + Math.floor(provideRandomSeed() * (lastIndex - index + 1));
    const value = result[rand];
    result[rand] = result[index];
    result[index] = value;
  }

  return result;
};
