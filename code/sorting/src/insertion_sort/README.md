# Insertion Sort
Insertion sort iterates through an array by taking one input element at each iteration, and grows a sorted output. With each iteration, insertion sorts removes the element at the current index, finds its correct position in the sorted output list, and inserts it there. This is repeated until no elements remain.
It is highly recommended to use Insertion Sort for sorting small or nearly sorted lists.
## Explanation
![Wiki image](https://upload.wikimedia.org/wikipedia/commons/0/0f/Insertion-sort-example-300px.gif)
> Image credits: Wikimedia Commons

## Algorithm
1. Get unsorted array/list
2. Set 'marker' for sorted section after first element in array/list
3. Select first unsorted number
4. Swap number with left elements until it is in correct position in sorted sub-array
5. Move sorted section marker over to the right one position
6. Repeat steps 3 through 5 until no more elements exist in unsorted sub-array.


## Complexity
**Time Complexity:**
- Worst case: **O(n<sup>2</sup>)**
- Average: **O(n<sup>2</sup>)**
- Best case: **O(n)**

**Space Complexity:**
- Average: **O(n)**

<p align="center">
	Refer to <a href="https://iq.opengenus.org/insertion-sort-analysis/">Insertion Sort Analysis</a> for more explanation.
</p>

---
<p align="center">
	A massive collaborative effort by <a href="https://github.com/OpenGenus/cosmos">OpenGenus Foundation</a> 
</p>
 
---
