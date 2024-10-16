/* Part of Cosmos by OpenGenus Foundation */

function divide(dividend, divisor) {
  if (divisor === 0) {
    return "undefined";
  }

  const isPositive = dividend > 0 && divisor > 0;
  dividend = Math.abs(dividend);
  divisor = Math.abs(divisor);

  var answer = 0;
  while (dividend >= divisor) {
    let temp = divisor;
    let i = 1;
    while (dividend >= temp) {
      dividend -= temp;
      answer += i;
      i <<= 1;
      temp <<= 1;
    }
  }

  if (!isPositive) {
    answer = -answer;
  }

  return answer;
}

function test() {
  var testCases = [[9, 4], [-10, 3], [103, -10], [-9, -4], [0, -3], [2, 0]];

  testCases.forEach(test =>
    console.log(`${test[0]} / ${test[1]} = ${divide(test[0], test[1])}`)
  );
}

test();
