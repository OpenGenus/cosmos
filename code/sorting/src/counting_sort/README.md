*** Counting Sort ***

## Overview

Counting sort is used to sort a collection of objects that have their keys as small integers. It works by counting the number of objects that have distinct key value and using the value of those counts to determine their position in the sorted array. Since we only need to traverse the array once, the running time is linear , i.e. O(n) where n are the number of elements in the array to be sorted.

Although the time complexity for the algorithm is less, it uses an extra space of O(m) where m is the value of the maximum element in the array.


## Example

Input data: 1, 4, 1, 2, 7, 5, 2
  1) Take a count array to store the count of each unique object.
  Index:     0  1  2  3  4  5  6  7  8  9
  Count:     0  2  2  0   1  1  0  1  0  0
 
  2) Output each object from the count sequence while it's count >=1 followed by decreasing its count by 1.
  For the above count array we will start with 1 and store it in sorted array 2 times followed by storing 2 again 2 times.

## Complexity

- Time complexity = O(n) where n is the number of elements in the input array
- Space comeplexity = O(m) where m is the value of the maximum element in the array.
To save the extra space for output array we can re-write the input array.

## Further Reading

https://en.wikipedia.org/wiki/Counting_sort

Your personal library of every algorithm and data structure code that you will ever encounter.

A large scale collaboration of [OpenGenus](https://github.com/opengenus)