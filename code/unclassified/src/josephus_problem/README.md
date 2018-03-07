# Josephus Problem Algorithm

Josephus Problem is a theoretical Counting Game Problem.  
n people stand in a circle and are numbered from 1 to n in clockwise direction.  
Starting from 1 in clockwise direction each person kills the k<sup>th</sup> person next to him and this continues till
a single person is left. The task is to choose a suitable position in initial circle to avoid execution.

## Explanation

![When k is 1](http://www.exploringbinary.com/wp-content/uploads/Josephus8.png)
>Image credits: ([Exploring Binary](http://www.exploringbinary.com/powers-of-two-in-the-josephus-problem/))

### Recurrence Relation 

`J(1,k) = 1`

`J(n,k) = (J(n-1,k) + k-1 ) mod n +1`

## Complexity

Time complexity = O(n)

---
<p align="center">
	A massive collaborative effort by <a href="https://github.com/OpenGenus/cosmos">OpenGenus Foundation</a> 
</p>

---
