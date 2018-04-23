# Heap Sort
Heap sort is a comparison based, simple and efficient sorting algorithm. There are two main parts to the process:
* A heap is built from the unsorted data. The algorithm separates the unsorted data from the sorted data.
* The largest element from the unsorted data is moved into an array

Thus, Heap Sort uses a heap to sort the given elements. 

## Explanation
![image](https://www.codingeek.com/wp-content/uploads/2016/07/Heapsort-example.gif)

> Image credits: https://www.codingeek.com/

## Algorithm
``` 
		Heapify (A, i)

            l ← left [i]
            r ← right [i]
            if l ≤ heap-size [A] and A[l] > A[i]
                then largest ← l
                else largest ← i
            if r ≤ heap-size [A] and A[i] > A[largest]
                then largest ← r
            if largest  ≠ i
                then exchange A[i] ↔ A[largest]
                    Heapify (A, largest)
```

## Complexity
**Time Complexity**:
Worst, average and best case time complexity: **O(n * log n)**

**Space complexity**: `O(1)`

---
<p align="center">
	A massive collaborative effort by <a href="https://github.com/OpenGenus/cosmos">OpenGenus Foundation</a> 
</p>

---