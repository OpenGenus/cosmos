// dynamic programming | binomial coefficient | javascript js
// Part of Cosmos by OpenGenus Foundation

/*Call the function with desired values of n and k.
'ar' is the array name.*/

function binomialCoefficient(n, k) {
  if (k > n) {
    console.log("Not possible.");
    return;
  }

  const ar = [n + 1];
  for (let i = 0; i < n + 1; i++) {
    ar[i] = [n + 1];
  }

  for (i = 0; i < n + 1; i++) {
    for (let j = 0; j < n + 1; j++) {
      if (i == j || j == 0) {
        ar[i][j] = 1;
      } else if (j > i) {
        break;
      } else {
        ar[i][j] = ar[i - 1][j - 1] + ar[i - 1][j];
      }
    }
  }

  console.log(ar[n][k]);
}
