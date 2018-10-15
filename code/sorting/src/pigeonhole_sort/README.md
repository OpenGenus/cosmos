# Pigeonhole Sort
The Pigeonhole sort is a sorting technique that is used when the range of keys is relatively small. 
An array of pigeonholes (buckets, chunks of RAM) is reserved for each possible key value. The records from the unsorted list are scanned and copied into their respective pigeonholes based on their key values. Then, the contents of the pigeonholes are copied in sequence to the final destination.


## Explanation
Pigeonhole sort works in the following way:

![image1](https://cdncontribute.geeksforgeeks.org/wp-content/uploads/countingsort.png)

> Image credits: geeksforgeeks

It is similar to counting sort, but differs in that it "moves items twice: once to the bucket array and again to the final destination [whereas] counting sort builds an auxiliary array then uses the array to compute each item's final destination and move the item there".


## Algorithm

1. Find minimum and maximum values in array. Let the minimum and maximum values be ‘min’ and ‘max’ respectively. Also find range as ‘max-min-1’.
2. Set up an array of initially empty “pigeonholes” with the same size as that of the range.
3. Visit each element of the array and then put each element in its pigeonhole. An element `arr[i]` is put in hole at index `arr[i]` – min.
4. Start the loop all over the pigeonhole array in order and put the elements from non- empty holes back into the original array.

## Complexity
**Time complexity**: `O(N + n)` 
 where **N** is the range of key values and **n** is the input size

**Space complexity**: `O(N + n)` 

---
<p align="center">
	A massive collaborative effort by <a href="https://github.com/OpenGenus/cosmos">OpenGenus Foundation</a> 
</p>

---