# Box Stacking

## Description

Given a set of n types of 3D rectangular boxes, find the maximum height
that can be reached stacking instances of these boxes. Some onservations:

- A box can be stacked on top of another box only if the dimensions of the
2D base of the lower box are each strictly larger than those of the 2D base
of the higher box.
- The boxes can be rotated so that any side functions as its base.
- It is allowable to use multiple instances of the same type of box.

## Solution

This problem can be seen as a variation of the dynamic programming
problem LIS (longest increasing sequence). The steps to solve the problem are:

1) Compute the rotations of the given types of boxes.
2) Sort the boxes by decreasing order of area.
3) Find the longest increasing sequence of boxes.

---

<p align="center">
A massive collaborative effort by <a href="https://github.com/opengenus/cosmos">OpenGenus Foundation</a>
</p>

---
