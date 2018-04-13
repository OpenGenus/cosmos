# Quicksort

Quicksort is a fast sorting algorithm that takes a **divide-and-conquer approach** for sorting lists. It picks one element as a pivot element and partitions the array around it such that: left side of pivot contains all the elements that are less than the pivot element and right side contains all elements greater than the pivot. 

## Explanation
Following example explains how the pivot value is found in an array.

![image](https://www.tutorialspoint.com/data_structures_algorithms/images/quick_sort_partition_animation.gif)

> Image credits: tutorialspoint

The pivot value divides the list into two parts and recursively, we find the pivot for each sub-lists until all lists contains only one element.

## Algorithm
```
procedure partition(A, start, end) is
    pivot := A[end]
    i := start - 1    
    for j := start to end - 1 do
        if A[j] < pivot then
            i := i + 1
            swap A[i] with A[j]
    swap A[i + 1] with A[end]
    return i + 1

procedure quicksort(A, start, end) is
    if start < end then
        p := partition(A, start, end)
        quicksort(A, start, p - 1 )
        quicksort(A, p + 1, end)
```

The entire array is sorted by `quicksort(A, 0, length(A)-1)`.

## Complexity
**Time complexity**
- Worst case: **O(n<sup>2</sup>)**
- Average case: **O(n * log n)**
- Best case:
	- **O(n * log n)** for simple partition
	- **O(n)** for three-way partition and equal keys

**Space complexity**
- Worst case: **O(n)** auxiliary (naive)
- Average case: **O(log n)** auxiliary

---

<p align="center">
	A massive collaborative effort by <a href="https://github.com/OpenGenus/cosmos">OpenGenus Foundation</a> 
</p>

---