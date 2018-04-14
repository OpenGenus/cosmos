# Bucket Sort
Bucket sort is a sorting algorithm that works by distributing the elements of an array into a number of buckets. Then, we apply a sorting algorithm, **insertion sort** for best optimisation to sort elements in each bucket, and finally, take the elements out of buckets in order and put them back to original array to get the sorted result.

## Explanation

![fig1](https://upload.wikimedia.org/wikipedia/commons/6/61/Bucket_sort_1.svg)

Elements are first distributed among bins/buckets

![fig2](https://upload.wikimedia.org/wikipedia/commons/e/e3/Bucket_sort_2.svg)

Then, elements are sorted within each bucket.

## Algorithm
Bucket sort is mainly useful when input is uniformly distributed over a range.

If input is an n element array arr[i] with all elements lying in the range: [0.0, 1.0], and uniformly distributed in the same range, the algorithm is:

**bucket_sort(arr[ ], n)**
1. Create n empty buckets/lists.
2. Do for every array element arr[i]
		Insert arr[i] into bucket[n * array[i]]
3. Sort individual buckets by insertion sort
4. Concatenate all sorted buckets in their order, into one sorted list.		

## Complexity
The complexity of bucket sort isn’t constant depending on the input.
However, in **average case**, bucket sort has time complexity of **O(n)**, while it's **worst case time complexity is: O(n^2)**.

---

<p align="center">
	A massive collaborative effort by <a href="https://github.com/OpenGenus/cosmos">OpenGenus Foundation</a> 
</p>

---
