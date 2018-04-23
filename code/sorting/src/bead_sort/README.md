# Bead sort
**Bead sort**, also called **gravity sort**, is a natural sorting algorithm. 
In this algorithm, the idea is to represent positive integers by a set of beads, like those in an abacus. Beads are attached to vertical rods and appear to be suspended in air just before sliding down (a number is read by counting the number of beads horizontally). After these beads fall due to gravity, we get a sorted sequence of numbers from top to bottom.

## Explanation

![image1](https://raw.githubusercontent.com/pooyahatami/Algorithm-Sort-Bead/master/img/Blank-ERD-Data-Flow-Page-1.png)

Sorting of `{3, 4, 1, 2}` using Bead Sort. Beads fall down one by one if there is space below.

## Algorithm
1. Find size, **n** and maximum element, **m** of the given array `A[]`.
2. Allocate memory and mark the beads such that there are n levels/rows and m rods/columns.
3. For all n in `A[]`, drop **n** beads(one bead per rod) along the rods, such that no bead is already present below it.
4. Repeat step 3 till a sorted sequence of numbers is obtained from top to bottom.
5. Put sorted values in array using beads.


## Complexity
**Time complexity**
- **O(1)**: All beads are dropped simultaneously in a single operation. It cannot be implemented in practice.

- **O(n<sup>0.5</sup>)**: It’s the estimation for the physical model, in which beads slide down along the greased spokes. The time of free fall is proportional to the square root of the maximum height, which is proportional to n.

- **O(n)**: The beads are moved one row at a time.
- **O(S)**: where S is the sum of the integers in the input set: Each bead is moved individually. 

**Space complexity**: **O(n<sup>2</sup>)**

---
<p align="center">
	A massive collaborative effort by <a href="https://github.com/OpenGenus/cosmos">OpenGenus Foundation</a> 
</p>

---