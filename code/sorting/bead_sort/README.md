# Bead sort

**Bead sort**, also called **gravity sort**, is a natural sorting algorithm. Both digital and analog hardware implementations of bead sort can achieve a sorting time of *O*(*n*); however, the implementation of this algorithm tends to be significantly slower in software and can only be used to sort lists of positive integers. Also, it would seem that even in the best case, the algorithm requires *O*(*n^2*) space.

## Overview

The bead sort operation can be compared to the manner in which beads slide on parallel poles, such as on an abacus. However, each pole may have a distinct number of beads. Initially, it may be helpful to imagine the beads suspended on vertical poles. In Step 1, put *n* rows of beads on *m* vertical poles from left to right, *n* is the length of the array to be sorted, *m* is the max num in the array.

If we then allow the beads to fall, the rows now represent the same integers in sorted order. Row 1 contains the largest number in the set, while row *n* contains the smallest.

## Complexity

- *O*(1): The beads are all moved simultaneously in the same time unit, as would be the case with the simple physical example above. This is an abstract complexity, and cannot be implemented in practice.
- *O*(S), where S is the sum of the integers in the input set: Each bead is moved individually. This is the case when bead sort is implemented without a mechanism to assist in finding empty spaces below the beads, such as in software implementations.

## Further reading

[Wikipedia - Bead sort](https://en.wikipedia.org/wiki/Bead_sort)

---

<p align="center">
	A massive collaborative effort by <a href="https://github.com/OpenGenus/cosmos">OpenGenus Foundation</a> 
</p>

---