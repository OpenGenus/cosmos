/* Part of Cosmos by OpenGenus Foundation */
"use strict";

function towerOfHanoi(n, from_rod, to_rod, aux_rod) {
  if (n >= 1) {
    // Move a tower of n-1 to the aux rod, using the dest rod.
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);

    // Move the remaining disk to the dest peg.
    console.log("Move disk from Tower ", from_rod, " to Tower ", to_rod);

    // Move the tower of `n-1` from the `aux_rod` to the `dest rod` using the `source rod`.
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
  }
  return;
}

towerOfHanoi(3, "A", "C", "B");
