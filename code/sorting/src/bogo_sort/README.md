# Bogosort
Bogosort or **permutation sort** is an extremely inefficient sorting algorithm. This is due to it's random nature: it randomly generates permutations of it's input until it finds one that is sorted. It has no use in practical applications.

## Explanation
Consider an array: `[ 2 3 5 0 1 ]`

```
5 3 2 0 1 (1st shuffling)
1 3 2 5 0 (2nd shuffling)
1 0 2 5 3 (2nd shuffling)
.
.
.
0 1 2 3 5 (nth shuffling) - Sorted Array
```
Where, **n** is unknown as this algorithm does not tell, in which step the resultant permutation will be sorted.

## Algorithm
```
while not in_order(list) do
	shuffle (list)
done
```

## Complexity
**Time complexity**
- Worst case: **O(&#8734;)**
- Average case: **O(n * n!)**
- Best case: **O(n)** 

**Space complexity**: **O(1)** auxillary

---
<p align="center">
	A massive collaborative effort by <a href="https://github.com/OpenGenus/cosmos">OpenGenus Foundation</a> 
</p>
---   