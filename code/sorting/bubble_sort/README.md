# Bubble Sort
**Bubble Sort** is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in wrong order. In computer graphics it is popular for its capability to detect a very small error (like swap of just two elements) in almost-sorted arrays and fix it with just linear complexity (2n). For example, it is used in a polygon filling algorithm, where bounding lines are sorted by their x coordinate at a specific scan line (a line parallel to x axis) and with incrementing y their order changes (two elements are swapped) only at intersections of two lines.

## Overview
**First Pass:**
( 5 1 4 2 8 ) –> ( 1 5 4 2 8 ), Here, algorithm compares the first two elements, and swaps since 5 > 1.
<br>
( 1 5 4 2 8 ) –>  ( 1 4 5 2 8 ), Swap since 5 > 4.
<br>
( 1 4 5 2 8 ) –>  ( 1 4 2 5 8 ), Swap since 5 > 2.
<br>
( 1 4 2 5 8 ) –> ( 1 4 2 5 8 ), Now, since these elements are already in order (8 > 5), algorithm does not swap them.
<br>
**Second Pass:**
( 1 4 2 5 8 ) –> ( 1 4 2 5 8 )
<br>
( 1 4 2 5 8 ) –> ( 1 2 4 5 8 ), Swap since 4 > 2
<br>
( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )
<br>
( 1 2 4 5 8 ) –>  ( 1 2 4 5 8 )
Now, the array is already sorted, but our algorithm does not know if it is completed. The algorithm needs one whole pass without any swap to know it is sorted.
<br>
**Third Pass:**
( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )
<br>
( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )
<br>
( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )
<br>
( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )

## Complexity
- O(n*n): Occurs when array is reverse sorted, n is the number of elements in the given array. 
- O(n): Occurs when the array is already sorted, n is the number of elements in the given array.

## Further reading
[Wikipedia - Bubble sort](https://en.wikipedia.org/wiki/Bubble_sort)

---

<p align="center">
	A massive collaborative effort by <a href="https://github.com/OpenGenus/cosmos">OpenGenus Foundation</a> 
</p>

---
