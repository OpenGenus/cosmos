function fibonacciSearch(ar, x, n) {
  var secondPreceding = 0,
    firstPreceding = 1;
  var nextNum = secondPreceding + firstPreceding;

  while (nextNum < n) {
    secondPreceding = firstPreceding;
    firstPreceding = nextNum;
    nextNum = secondPreceding + firstPreceding;
  }

  var range = -1;

  while (nextNum > 1) {
    var i = min(range + firstPreceding, n - 1);

    if (x < ar[i]) {
      nextNum = nextNum - firstPreceding;
      firstPreceding = firstPreceding - secondPreceding;
      secondPreceding = nextNum - firstPreceding;
    } else if (x > ar[i]) {
      nextNum = firstPreceding;
      firstPreceding = secondPreceding;
      secondPreceding = nextNum - firstPreceding;
      range = i;
    } else {
      return i;
    }
  }

  if (firstPreceding && ar[range + 1] == x) {
    return range + 1;
  }

  return -1;
}
function min(a, b) {
  return a > b ? b : a;
}
