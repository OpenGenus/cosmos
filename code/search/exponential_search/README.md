# cosmos

# Exponential Search

## When can we use this algorithm?
- When the given array is sorted
- And when it is unbounded

Exponential search involves two steps:

- Find range where element is present
- Do Binary Search in above found range.

**Pseudo code**
```python
function exponential_search(array,key)
size = length(array)

    if (size == 0)
        return NOT_FOUND


    bound = 1
    while (bound < size and arr[bound] < key)
        bound *= 2;


    return binary_search(arr, key, bound/2, min(bound, size));

```

## How to find the range where element may be present?
In each step, the algorithm compares the search key value with the key value at the current search index. If the element at the current index is smaller than the search key, the algorithm repeats, skipping to the next search index by doubling it, calculating the next power of 2. If the element at the current index is larger than the search key, the algorithm now knows that the search key, if it is contained in the list at all, is located in the interval formed by the previous search index, 2j - 1, and the current search index, 2j. The binary search is then performed with the result of either a failure, if the search key is not in the list, or the position of the search key in the list.

## Time complexity of algorithm:
- O(log(i)), where i is the index of the serach key in
the array 

## Applications of Exponential Search:

- Exponential Binary Search is particularly useful for unbounded searches, where size of array is infinite. Please refer Unbounded Binary Search for an example.

- It works better than Binary Search for bounded arrays also when the element to be searched is closer to the first element.

---

<p align="center">
	A massive collaborative effort by <a href="https://github.com/OpenGenus/cosmos">OpenGenus Foundation</a>
</p>

---
