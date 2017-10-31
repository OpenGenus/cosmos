# Bubble Sort
The Bubble Sort is a comparison sort algorithm. It has an average performance of O(n*n).

Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in wrong order.

Example:
First Pass:
( 5 1 4 2 8 ) –> ( 1 5 4 2 8 ), Here, algorithm compares the first two elements, and swaps since 5 > 1.
( 1 5 4 2 8 ) –>  ( 1 4 5 2 8 ), Swap since 5 > 4
( 1 4 5 2 8 ) –>  ( 1 4 2 5 8 ), Swap since 5 > 2
( 1 4 2 5 8 ) –> ( 1 4 2 5 8 ), Now, since these elements are already in order (8 > 5), algorithm does not swap them.
## Procedure
1. Run through the list.
2. Compare each adjacent pair of element
3. Swap elements if not in correct order
4. Repeat until no swap is needed


Collaborative effort by [OpenGenus](https://github.com/opengenus)