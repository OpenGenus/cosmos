// Memorization
function numCoins(S, i, N, mem) {
  if (i < 0 || N < 0) {
    return 0;
  } else if (N === 0) {
    return 1;
  } else {
    var memIndex = i.toString() + "-" + N.toString();
    if (mem[memIndex] !== undefined) {
      return mem[memIndex];
    } else {
      mem[memIndex] =  numCoins(S, i - 1, N, mem) // i-th coin excluded
        + numCoins(S, i, N - S[i], mem); // take one i-th coin
      return mem[memIndex];
    }
  }
}

// TODO: Implement with tabular method
