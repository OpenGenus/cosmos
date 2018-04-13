# Comb sort
The comb sort is a variant of bubble sort.
In comb sort, gaps (distance of two items from each other) are introduced. The gap in bubble sort is 1. The gap starts out as a large value, and, after each traversal, the gap is lessened, until it becomes 1, where the algorithm basically degrades to a bubble sort. Thus, it removes more than one inversion counts with one swap and performs better than bubble sort.

## Explanation
![image1](http://1.bp.blogspot.com/-vzzP48EI-o4/VcNpjHTeA9I/AAAAAAAAAw0/i-0Cf909o2Y/s1600/comb_sort.png)

## Algorithm

```
 function combsort(array input)

    gap := input.size // Initialize gap size
    shrink := 1.3 // Set the gap shrink factor
    sorted := false

    loop while sorted = false
        // Update the gap value for a next comb
        gap := floor(gap / shrink)
        if gap > 1
            sorted := false // We are never sorted as long as gap > 1
        else
            gap := 1
            sorted := true // If there are no swaps this pass, we are done
        end if
        // A single "comb" over the input list
        i := 0
        loop while i + gap < input.size // See Shell sort for a similar idea
            if input[i] > input[i+gap]
                swap(input[i], input[i+gap])
                sorted := false
                // If this assignment never happens within the loop,
                // then there have been no swaps and the list is sorted.
             end if
             i := i + 1
         end loop
     end loop
 end function
```

## Complexity
**Time complexity**
- Worst case: **O(n<sup>2</sup>)**
- Best case: **O(n)**

**Space complexity**: **O(1)** auxillary

---

<p align="center">
	A massive collaborative effort by <a href="https://github.com/OpenGenus/cosmos">OpenGenus Foundation</a> 
</p>

---
