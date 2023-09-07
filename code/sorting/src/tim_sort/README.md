# Tim Sort
Tim Sort was first implemented in 2002 by Tim Peters for use in Python. It allegedly came from the understanding that most sorting algorithms are born in schoolrooms, and not designed for practical use on real world data. Tim Sort is a hybrid stable sorting algorithm that takes advantage of common patterns in data, and utilizes a combination of improved Merge sort and Binary Insertion sort along with some internal logic to optimize the manipulation of large scale real world data.

## Explanation

Tim Sort was designed to take advantage of runs of consecutive ordered elements that already exist in most real-world data, natural runs. It iterates over the data collecting elements into runs and simultaneously putting those runs in a stack. Whenever the runs on the top of the stack match a merge criterion, they are merged together. This goes on until all data is traversed; then, all runs are merged two at a time and only one sorted run remains. The advantage of merging ordered runs instead of merging fixed size sub-lists (as done by traditional mergesort) is that it decreases the total number of comparisons needed to sort the entire list.

Each run has a minimum size, which is based on the size of the input and it is defined at the start of the algorithm. If a run is smaller than this minimum run size, insertion sort is used to add more elements to the run until the minimum run size is reached.

Tim sort uses Binary insertion sort and improved merge sort by using galloping in a combination. Binary insertion sort is the best method to sort when data is already or partially sorted and merge sort is best when the input is large.

##Algorithm

* Establish a minrun size that is a power of 2 (usually 32, never more than 64 or your Binary Insertion Sort will lose efficiency)
* Find a run in the first minrun of data.
* If the run is not at least minrun in length, use Insertion Sort to grab subsequent or prior items and insert them into the run until it is the correct minimum size.
* Repeat until the entire array is divided into sorted subsections.
* Use the latter half of Merge Sort to join the ordered arrays.

## Complexity
**Time complexity**
- Worst Case: 
	- **O(n logn)**
- Average Case: **O(n logn)**
- Best Case: **O(n)**

**Space Complexity**: **O(n)** auxillary space

---
<p align="center">
	A massive collaborative effort by <a href="https://github.com/OpenGenus/cosmos">OpenGenus Foundation</a> 
</p>

---
