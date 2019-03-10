function sd(arr) {
  // calculate standard deviation of array of numbers
  var arr_sum = 0;
  var arr_square_sum = 0;
  for (var i = 0; i < arr.length; ++i) {
    arr_sum += arr[i]; // sum of values in array
    arr_square_sum += arr[i] * arr[i]; // sum of squares of values in array
  }

  var arr_mean = arr_sum / arr.length; // this is E[X]
  var arr_square_mean = arr_square_sum / arr.length; // this is E[X^2]
  var variance = arr_square_mean - arr_mean * arr_mean; // Var(X) = E[X^2] - E[X]^2

  return Math.sqrt(variance);
}

// tests:
sd([12, 65, 91, 52, 18, 72]); // returns 28.41, as expected
sd([-10.6]); // returns 0, as expected
sd([-1, -1, 0, 1, 1]); // returns 0.8944, as expected
