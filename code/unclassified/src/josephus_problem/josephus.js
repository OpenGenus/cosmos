function josephus(n, k) {
  // Returns the safe position of n items
  // that have every kth item counted out
  // Note that the indice returned is zero-indexed
  if (n == 1) {
    return 0;
  }

  return (josephus(n - 1, k) + k) % n;
}

function test(n, k, expected) {
  const result = josephus(n, k);
  if (result == expected) {
    console.log('PASS');
  } else {
    console.log(`FAIL: josephus(${n}, ${k}) result ${result} does not match ${expected}`);
  }
}

test(1, 10, 0);
test(13, 2, 10);
test(8, 2, 0);
test(1000, 2, 976);
