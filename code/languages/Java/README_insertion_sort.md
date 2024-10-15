# Insertion Sort

Insertion sort is an algorithm for sorting arrays/lists that operates by iterating through the array and inserting each element into its place within the sorted part of the array. In the best case (where array is already sorted) its runtime would be linear, or $O(n)$, and in the worst case (where the array is in reverse order) its runtime would be quadratic, or $O(n^2)$, so it is quite nice for sorting smaller arrays, but quickly becomes impractical for larger arrays.

Steps:

1. Begin with the second element of the array.
2. Compare it to the first element, and swap them if the second element is smaller, doing nothing otherwise.
3. Move on to the third element of the array, comparing it to the second element and then the first element, swapping if smaller, or staying in place and moving on to the next step otherwise.
4. Repeat until the end of the array is reached.
