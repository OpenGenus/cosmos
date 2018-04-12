# Counting Sort
Counting sort is a a very time-efficient (and somewhat space-inefficient) algorithm based on keys between a specific range. It works by counting the number of objects having distinct key values (kind of hashing)and then doing some arithmetic to calculate the position of each object in the output sequence.

## Explanation
![image1](https://3.bp.blogspot.com/-jJchly1BkTc/WLGqCFDdvCI/AAAAAAAAAHA/luljAlz2ptMndIZNH0KLTTuQMNsfzDeFQCLcB/s1600/CSortUpdatedStepI.gif)

> Image credits: https://efficientalgorithms.blogspot.in/


## Algorithm

```
    Counting_sort(A, k)
              for i ← 1 to k do
                 c[i] ← 0
              for j ← 1 to n do
                 c[A[j]] ← c[A[j]] + 1
              //c[i] now contains the number of elements equal to i

              for i ← 2 to k do
                 c[i] ← c[i] + c[i-1]
              // c[i] now contains the number of elements ≤ i

              for j ← n downto 1 do
                 B[c[A[i]]] ← A[j]
                 c[A[i]] ← c[A[j]] - 1
              return B
```

## Complexity
**Time complexity**
O(n+k) where n is the number of elements in input array and k is the range of input.

**Space Comlexity**: O(n+k)

---
<p align="center">
	A massive collaborative effort by <a href="https://github.com/OpenGenus/cosmos">OpenGenus Foundation</a> 
</p>

---