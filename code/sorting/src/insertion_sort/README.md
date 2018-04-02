# Insertion Sort
Insertion sort iterates through an array, taking one input element at each iteration, and grows a sorted output. With each iteration, insertion sorts removes the element at the current index, finds the removed elements position in the sorted output list, and inserts it there. This is repeated until no elements remain.

## Explanation
![Wiki image](https://upload.wikimedia.org/wikipedia/commons/0/0f/Insertion-sort-example-300px.gif)
> Image credits: Wikimedia Commons

## Algorithm
1. Get unsorted array/list
2. Set 'marker' for sorted section after first element in array/list
3. Select first unsorted number
4. Swap number with left until it is in correct position
5. Move sorted section marker over to the right one position
6. Repeat until no more elements exist in unsorted sub-array.


## Complexity
**Time Complexity:**
- Worst case: O(n<sup>2</sup>)
- Average: O(n<sup>2</sup>)
- Best case: O(n)
**Space Complexity:**
- Average: O(n)

---
<p align="center">
	A massive collaborative effort by <a href="https://github.com/OpenGenus/cosmos">OpenGenus Foundation</a> 
</p>

---
