The quick sort algorithm runs on **O(nlogn)**. It takes an array and assigns an 
element as a pivot value and splits (paritions) the array to recursively sort 
the pivot value into the correct (sorted) position. However, when the first pivot 
element is either the smallest or largest element, this triggers the algorithms 
worst time complexity: O(n^2). 

Quick Sort Steps: 
1. A pivot is chosen and the array is split into subarrays 
2. Elements that are **less** than the pivot are moved to its left
3. Elements that are **greater** than the pivot are moved to its right
4. Quick sort is recursively called on both subarrays 
