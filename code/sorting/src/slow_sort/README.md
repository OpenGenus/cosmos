# Slow Sort

Slowsort is a recursive algorithm. It sorts in-place.
It is a stable sort. (It does not change the order of equal-valued keys.)

## Explantation

Input : {4, -9, 5, 8,-2, 4 78}
Output: {-9, -2, 4, 4, 5, 8, 78}

## Algorithm

function slowsort(A[], i, j)
    if i ≥ j then
        return
    m := floor( (i+j)/2 )
    slowsort(A, i, m)                  
    slowsort(A, m+1, j)                
    if A[j] < A[m] then
        swap A[j] , A[m]               
    slowsort(A, i, j-1)

## Complexity

Runtime T(n) = 2T(n/2)+T(n-1)+1

## Wiki Link

https://en.wikipedia.org/wiki/Slowsort

---
<p align="center">
	A massive collaborative effort by <a href="https://github.com/OpenGenus/cosmos">OpenGenus Foundation</a> 
</p>

---