# Selection Sort
Selection sort is a simple sorting algorithm. It is an in-place comparison-based algorithm in which the list is divided into two parts, the sorted part at the left end and the unsorted part at the right end. Initially, the sorted part is empty and the unsorted part is the entire list.

The smallest element is selected from the unsorted array and swapped with the leftmost element, and that element becomes a part of the sorted array. This process continues moving unsorted array boundary by one element to the right.

This algorithm is not suitable for large data sets as its average and worst case complexity is **Ο(n * n)**, where **n** is the number of items.

## Explanation
Consider the following example:

![image](https://he-s3.s3.amazonaws.com/media/uploads/2888f5b.png)

> Image credits: Hackerearth

Input: `[7 5 4 2]`

Output: `[2 4 5 7]`

## Pseudocode
```
SelectionSort(A):
  for j ← 1 to n-1
    smallest ← j
    for i ← j + 1 to n
      if A[i] < A[smallest]
        smallest ← i
    Swap A[j] ↔ A[smallest]
```


## Complexity
**Time complexity**
- Worst case: **O(n<sup>2</sup>)**
- Average case: **&theta;(n<sup>2</sup>)**
- Best case: **&#937;(n<sup>2</sup>)**

**Space complexity**: **O(1)** auxillary

---
<p align="center">
	A massive collaborative effort by <a href="https://github.com/OpenGenus/cosmos">OpenGenus Foundation</a> 
</p>

---