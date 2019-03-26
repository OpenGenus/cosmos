/**
 * Sleep Sort Implementation in JavaScript
 *
 * @author  Ahmar Siddiqui <ahmar.siddiqui@gmail.com>
 * @github @ahhmarr
 * @date   07/Oct/2017
 * Part of Cosmos by OpenGenus Foundation
 */

function sleepNumber(number) {
  // The timeout is (n^2) so that close numbers are no longer close.
  // Example: 1 is really close to 2, but 1^2 isn't close to 2^2.
  setTimeout(function() {
    console.log(number);
  }, number * number);
}

function sleepSort(array) {
  for (i = 0; i < array.length; ++i) {
    sleepNumber(array[i]);
  }
}

// Generate 100 random numbers for sorting.
randoms = [];
for (var i = 0; i < 100; ++i) {
  // Random number between 1 - 100
  randomInt = Math.floor(Math.random() * 100 + 1);
  randoms.push(randomInt);
}

// Sort said random numbers.
sleepSort(randoms);
