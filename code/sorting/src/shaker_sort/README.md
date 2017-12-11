# Shaker Sort / Coctail Sort

Shakersort is a _**bidirectional**_ variation of bubble sort. 
This is stable sorting algorithm with time complexity _**O(n*n)**_.

## Description

This algorithm differs from bubble sort in that it works in both directions. 
In the first, the lightest element ascends to the end of the list and in the second heaviest element descends to the beginning of the list (or vice versa)
.

### Pseudocode
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

---

<p align="center">
	A massive collaborative effort by <a href="https://github.com/OpenGenus/cosmos">OpenGenus Foundation</a> 
</p>

---
