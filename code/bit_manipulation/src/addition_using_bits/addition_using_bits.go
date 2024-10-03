package main

import "fmt"

// Part of Cosmos by OpenGenus Foundation
func bitwiseAddition(n, m int) int {
  for m != 0 {
    var carry int = n & m; // Variable carry keeps track of bits that carry over
    n = n ^ m;             // This adds up the individual bits
    m = carry << 1;        // Shift carry over bits so they can be added
  }
  return n;
}

func bitwiseAdditionRecursive(n, m int) int {
  if m == 0 {
    return n
  } else {
    var carry int = n & m
    return bitwiseAdditionRecursive(n ^ m, carry << 1)
  }
}
