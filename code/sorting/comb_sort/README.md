# Comb sort

## Overview

In bubble sort, when any two elements are compared, they always have a *gap* (distance from each other) of 1. The basic idea of comb sort is that the gap can be much more than 1. The inner loop of bubble sort, which does the actual *swap*, is modified such that gap between swapped elements goes down (for each iteration of outer loop) in steps of a "shrink factor" *k*: [ *n*/*k*, *n*/*k*2, *n*/*k*3, ..., 1 ].

The gap starts out as the length of the list *n* being sorted divided by the shrink factor *k* (generally 1.3) and one pass of the aforementioned modified bubble sort is applied with that gap. Then the gap is divided by the shrink factor again, the list is sorted with this new gap, and the process repeats until the gap is 1. At this point, comb sort continues using a gap of 1 until the list is fully sorted. The final stage of the sort is thus equivalent to a bubble sort, but by this time most turtles have been dealt with, so a bubble sort will be efficient.

## Further reading

[Wikipedia - Comb sort](https://en.wikipedia.org/wiki/Comb_sort)

A large scale collaboration of [OpenGenus](https://github.com/opengenus)