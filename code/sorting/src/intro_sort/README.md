# Intro Sort
Introsort or introspective sort is the best sorting algorithm around. It is a **hybrid sorting algorithm** and thus uses three sorting algorithm to minimise the running time, i.e., **Quicksort, Heapsort and Insertion Sort**.

## Explanation
Introsort begins with quicksort and if the recursion depth goes more than a particular limit it switches to Heapsort to avoid Quicksort’s worse case **O(n<sup>2</sup>)** time complexity. It also uses insertion sort when the number of elements to sort is quite less.

Thus, it first creates a partition, and 3 cases arrive from here:
1. If the partition size is such that there is a possibility to exceed the maximum depth limit then, the Introsort switches to Heapsort. We define the maximum depth limit as 2 * logn.
2. If the partition size is too small then Quicksort decays to Insertion Sort. We define this cutoff as 16 (due to research). So if the partition size is less than 16 then we will do insertion sort.
3. If the partition size is under the limit and not too small (i.e., between 16 and `(2 * log(N))`, then it performs a simple quicksort.

## Algorithm
```
procedure sort(A : array):
    let maxdepth = ⌊log(length(A))⌋ × 2
    introsort(A, maxdepth)

procedure introsort(A, maxdepth):
    n ← length(A)
    if n ≤ 1:
        return  // base case
    else if maxdepth = 0:
        heapsort(A)
    else:
        p ← partition(A)  
        introsort(A[0:p], maxdepth - 1)
        introsort(A[p+1:n], maxdepth - 1)
```

## Complexity
**Time complexity**
Worst, average and best case time complexity: **O(n * logn)**

**Space complexity**
**O(log N)** auxiliary space

---
<p align="center">
	A massive collaborative effort by <a href="https://github.com/OpenGenus/cosmos">OpenGenus Foundation</a> 
</p>

---