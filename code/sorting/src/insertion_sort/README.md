## Insertion Sort

**Overview:**

Algorithm will construct a sorted array/list of elements one item at a time. With each iteration, the algorithm takes one element from the input data, identifies the ordered location in the new sorted array/list, then inserts the element. This is repeated until all the input data has been orderly inserted into the array/list.

The algorithm thus divides the array into two parts: sorted and unsorted parts. The sorted part contains all the elements in the sorted order and we insert each element from the unsorted part in the sorted part according to their value until the array is sorted.

**Example:**

The following table shows the steps for sorting the sequence {3, 7, 4, 9, 5, 2, 6, 1}. In each step, the key under consideration is in round brackets. The key that was moved (or left in place because it was biggest yet considered) in the previous step is shown in square brackets.

(3) 7 4 9 5 2 6 1

[3]  (7) 4 9 5 2 6 1

3 [7]  (4) 9 5 2 6 1

3 [4] 7 (9) 5 2 6 1

3 4 7 [9]  (5) 2 6 1

3 4 [5] 7 9 (2) 6 1

[2] 3 4 5 7 9 (6) 1

2 3 4 5 [6] 7 9 (1)

[1] 2 3 4 5 6 7 9

**Time Complexity:**
- O(n*n) : where n is the number of elements to be sorted in the input array

** Further Reading:**
https://en.wikipedia.org/wiki/Insertion_sort