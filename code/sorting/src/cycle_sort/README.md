# Cycle Sort
Cycle sort is an in-place, unstable sorting algorithm, a comparison sort that is theoretically optimal in terms of the total number of writes to the original array, unlike any other in-place sorting algorithm. 

It is based on the idea that array to be sorted can be divided into cycles. Cycles can be visualized as a graph. We have n nodes and an edge directed from node i to node j if the element at i-th index must be present at j-th index in the sorted array.

## Explanation
Given an element a, we can find the index at which it will occur in the sorted list by simply counting the number of elements in the entire list that are smaller than a, in the following way:

![image1](https://upload.wikimedia.org/wikipedia/commons/thumb/1/10/Cyclesort-cycle.svg/523px-Cyclesort-cycle.svg.png)

> Image credits: wikipedia

## Algorithm

```
procedure cycle_sort 
    (var a: sort_array; n: array_size);  
  var i, j: array_size; 
    save, temp: array_element; 
 begin 
        for i := 1 to n do 
        begin 
          j := a[i].key; 
          if i ≠ j then 
          begin 
            save := a[i]; 
            repeat 
              temp := a[j]; 
              a[j] := save; 
              save := temp; 
              j := save.key; 
           until i = j { repeat }; 
           a[i] := save; 
         end { if i ≠ j }; 
       end {for i: = 1 to n } 
end { procedure special_cycle_sort }; 

```

## Complexity
**Time complexity**
- Worst, average and best case time complexity: **O(n<sup>2</sup>)**


**Space complexity**
- Worst case: **O(n)** total
- Auxillary space: **O(1)**

---
<p align="center">
	A massive collaborative effort by <a href="https://github.com/OpenGenus/cosmos">OpenGenus Foundation</a> 
</p>

---