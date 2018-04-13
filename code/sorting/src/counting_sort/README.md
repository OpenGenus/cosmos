# Counting Sort
Counting sort is a a very time-efficient (and somewhat space-inefficient) algorithm based on keys between a specific range. It works by counting the number of objects having distinct key values (kind of hashing)and then doing some arithmetic to calculate the position of each object in the output sequence.

## Explanation
![image1](https://3.bp.blogspot.com/-jJchly1BkTc/WLGqCFDdvCI/AAAAAAAAAHA/luljAlz2ptMndIZNH0KLTTuQMNsfzDeFQCLcB/s1600/CSortUpdatedStepI.gif)

> Image credits: https://efficientalgorithms.blogspot.in/


## Algorithm

```
    Counting_sort(A, k)
              n = length[A]
              create array B[n] & C[k+1]
              for i=0 to k
                 C[i] = 0
              for i = 1 to n
                 C[A[i]]++
              for i = 1 to k
                 C[i] = C[i] + C[i - 1]
              for i = n to 1
                 B[C[A[i]]] = A[i]
                 C[A[i]]--
```

## Complexity
**Time complexity**
**O(n+k)** where **n** is the number of elements in input array and **k** is the range of input.

**Space Comlexity**: `O(n+k)`

---
<p align="center">
	A massive collaborative effort by <a href="https://github.com/OpenGenus/cosmos">OpenGenus Foundation</a> 
</p>

---