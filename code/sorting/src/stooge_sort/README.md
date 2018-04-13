# Stooge Sort
Stooge sort is a recursive sorting algorithm.
The algorithm is defined as follows:
1) If the value at the start is larger than the value at the end, swap them.
2) If there are 3 or more elements in the list, then:
    * Stooge sort the initial 2/3 of the list
    * Stooge sort the final 2/3 of the list
    * Stooge sort the initial 2/3 of the list again

## Explanation
![image](https://cdncontribute.geeksforgeeks.org/wp-content/uploads/stoogeSort.png)

> Image credits: geeksforgeeks

Input: `2 4 5 3 1`

Output: `1 2 3 4 5`


## Algorithm
```
function stoogesort(array L, i = 0, j = length(L)-1)
     if L[i] > L[j] then
         L[i] ↔ L[j]
     if (j - i + 1) > 2 then
         t = (j - i + 1) / 3
         stoogesort(L, i  , j-t)
         stoogesort(L, i+t, j)
         stoogesort(L, i  , j-t)
     return L
```

## Complexity
**Time complexity**: 
O(n<sup>(log3/log1.5)</sup>) = **O(n<sup>2.709</sup>)**

**Space complexity**:
Worst case space complexity: **O(n)**

---
<p align="center">
    A massive collaborative effort by <a href="https://github.com/OpenGenus/cosmos">OpenGenus Foundation</a> 
</p>

---