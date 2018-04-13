# Gnome Sort
Gnome sort (or Stupid sort) is a sorting algorithm which is similar to insertion sort, except that moving an element to its proper place is accomplished by a series of swaps, as in bubble sort. 
Gnome Sort is based on the technique used by the standard Dutch Garden Gnome, i.e., how he sorts a line of flower pots. Basically, he looks at the flower pot next to him and the previous one; if they are in the right order he steps one pot forward, otherwise he swaps them and steps one pot backwards. Boundary conditions: if there is no previous pot, he steps forwards; if there is no pot next to him, he is done. 


## Explanation
Consider the given array:
   `arr = [34 2 10 -9]`

1. Underlined elements are the pair under consideration.
2. **Red** colored are the pair which needs to be swapped.
3. Result of the swapping is colored as **blue**.

![image1](https://www.geeksforgeeks.org/wp-content/uploads/gnomesort.png)

> Image credits: geeksforgeeks


## Algorithm
```
procedure gnomeSort(a[]):
    pos := 0
    while pos < length(a):
        if (pos == 0 or a[pos] >= a[pos-1]):
            pos := pos + 1
        else:
            swap a[pos] and a[pos-1]
            pos := pos - 1
```

## Complexity
**Time complexity**
- Worst Case: **O(n<sup>2</sup>)**
- Average Case: **O(n<sup>2</sup>)**
- Best Case: **O(n)**

**Space complexity**: **O(1)** auxillary space

---
<p align="center">
	A massive collaborative effort by <a href="https://github.com/OpenGenus/cosmos">OpenGenus Foundation</a> 
</p>

---