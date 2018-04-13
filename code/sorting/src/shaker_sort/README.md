# Shaker Sort 

Shakersort or cocktail sort is a _**bidirectional**_ variation of bubble sort. 
In shaker sort, n elements are sorted in `n/2` phases. Each phase of shaker sort consists of a left to right bubbling pass followed by a right to left bubbling pass. In a bubbling pass pairs of adjacent elements are compared and swapped if they are out of order. 
This algorithm differs from bubble sort in that it works in both directions. 
In the first, the lightest element ascends to the end of the list and in the second heaviest element descends to the beginning of the list (or vice versa).

## Explanation
Example : Let us consider an example array: **(5 1 4 2 8 0 2)**

First Forward Pass:
```
(5 1 4 2 8 0 2) ? (1 5 4 2 8 0 2), Swap since 5 > 1
(1 5 4 2 8 0 2) ? (1 4 5 2 8 0 2), Swap since 5 > 4
(1 4 5 2 8 0 2) ? (1 4 2 5 8 0 2), Swap since 5 > 2
(1 4 2 5 8 0 2) ? (1 4 2 5 8 0 2)
(1 4 2 5 8 0 2) ? (1 4 2 5 0 8 2), Swap since 8 > 0
(1 4 2 5 0 8 2) ? (1 4 2 5 0 2 8), Swap since 8 > 2
```
After first forward pass, greatest element of the array will be present at the last index of array.

First Backward Pass:
```
(1 4 2 5 0 2 8) ? (1 4 2 5 0 2 8)
(1 4 2 5 0 2 8) ? (1 4 2 0 5 2 8), Swap since 5 > 0
(1 4 2 0 5 2 8) ? (1 4 0 2 5 2 8), Swap since 2 > 0
(1 4 0 2 5 2 8) ? (1 0 4 2 5 2 8), Swap since 4 > 0
(1 0 4 2 5 2 8) ? (0 1 4 2 5 2 8), Swap since 1 > 0
```
After first backward pass, smallest element of the array will be present at the first index of the array.

Second Forward Pass:
```(0 1 4 2 5 2 8) ? (0 1 4 2 5 2 8)
(0 1 4 2 5 2 8) ? (0 1 2 4 5 2 8), Swap since 4 > 2
(0 1 2 4 5 2 8) ? (0 1 2 4 5 2 8)
(0 1 2 4 5 2 8) ? (0 1 2 4 2 5 8), Swap since 5 > 2
```
Second Backward Pass:
```(0 1 2 4 2 5 8) ? (0 1 2 2 4 5 8), Swap since 4 > 2```

Now, the array is already sorted, but our algorithm doesn’t know if it is completed. The algorithm needs to complete this whole pass without any swap to know it is sorted.
```
(0 1 2 2 4 5 8) ? (0 1 2 2 4 5 8)
(0 1 2 2 4 5 8) ? (0 1 2 2 4 5 8)
```

## Algorithm
```
procedure cocktailShakerSort( A : list of sortable items ) defined as:
  do
    swapped := false
    for each i in 0 to length( A ) - 2 do:
      if A[ i ] > A[ i + 1 ] then // test whether the two elements are in the wrong order
        swap( A[ i ], A[ i + 1 ] ) // let the two elements change places
        swapped := true
      end if
    end for
    if not swapped then
      // we can exit the outer loop here if no swaps occurred.
      break do-while loop
    end if
    swapped := false
    for each i in length( A ) - 2 to 0 do:
      if A[ i ] > A[ i + 1 ] then
        swap( A[ i ], A[ i + 1 ] )
        swapped := true
      end if
    end for
  while swapped // if no elements have been swapped, then the list is sorted
end procedure
```

## Complexity
**Time complexity**
- Worst Case: **O(n<sup>2</sup>)**
- Average Case: **O(n<sup>2</sup>)**
- Best Case: **O(n)**

**Space complexity**: **O(n)** auxillary

---

<p align="center">
	A massive collaborative effort by <a href="https://github.com/OpenGenus/cosmos">OpenGenus Foundation</a> 
</p>

---
