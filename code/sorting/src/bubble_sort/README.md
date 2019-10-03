# Bubble Sort
**Bubble Sort** is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in wrong order. 
In computer graphics it is popular for its capability to detect a very small error (like swap of just two elements) in almost-sorted arrays and fix it with just linear complexity (2n). For example, it is used in a polygon filling algorithm, where bounding lines are sorted by their x coordinate at a specific scan line (a line parallel to x axis) and with incrementing y their order changes (two elements are swapped) only at intersections of two lines.

## Explanation
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

## Algorithm
```
begin BubbleSort(list)

   for unsorted_end in list[n...1]
      for unsorted_beg of list[1...unsorted_end-1]
         if list[unsorted_beg] > list[unsorted_beg+1]
            swap(list[unsorted_beg], list[unsorted_beg+1])
         end if
      end for
   end for
   
   return list
   
end BubbleSort
```


## Complexity
**Time complexity**
- Average and worst case: **O(n<sup>2</sup>)**
- Best case: **O(n)**

**Space complexity**: : **O(1)** auxillary

---

<p align="center">
	A massive collaborative effort by <a href="https://github.com/OpenGenus/cosmos">OpenGenus Foundation</a> 
</p>

---
