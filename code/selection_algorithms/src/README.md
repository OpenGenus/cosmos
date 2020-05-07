# cosmos
Your personal library of every algorithm and data structure code that you will ever encounter.

A large scale collaboration of [OpenGenus](https://github.com/opengenus)


## Quickselect 

Quickselect is a selection algorithm to find the k-th smallest element in an unordered list. It is related to the quick sort sorting algorithm.

The algorithm is similar to QuickSort. The difference is, instead of recurring for both sides (after finding pivot), it recurs only for the part that contains the k-th smallest element. The logic is simple, if index of partitioned element is more than k, then we recur for left part. If index is same as k, we have found the k-th smallest element and we return. If index is less than k, then we recur for right part. This reduces the expected complexity from O(n log n) to O(n), with a worst case of O(n^2).

The important part in quick select is partition.

Partition in quick select picks a pivot (either randomly or first/last element). Then it rearranges the list in a way that all elements less than pivot are on left side of pivot and others on right. It then returns index of the pivot element.

Now here we are finding kth smallest element. After partition cases are:

* k == pivot. Then you have already found kth smallest. This is because the way partition is working. There are exactly k - 1 elements that are smaller than the kth element.
* k < pivot. Then kth smallest is on the left side of pivot.
* k > pivot. Then kth smallest is on the right side of pivot. And to find it you actually have to find k-pivot smallest number on right.


**Important Points:**

1.Like quicksort, it is fast in practice, but has poor worst-case performance. 

2.The partition process is same as QuickSort, only recursive code differs.
