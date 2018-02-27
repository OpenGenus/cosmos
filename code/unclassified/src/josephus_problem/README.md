# Josephus Problem  

Josephus Problem is theoretical Counting Game Problem.  
n number of person stand in a circle and are numbered from 1 to n in clockwise direction.  
Starting from 1 in clockwise direction each person kills k<sup>th</sup> person next to him and this continues till
a single person is left. The problem is to choose a suitable postion in initial circle to avoid execution.

## Solution

Let J(n,k) represent the position of survivor when there are n person and k denotes count of each step i.e. k-1 person 
are skipped and k<sup>th</sup> person is executed.

### Recurrence Relation  
`J(1,k) = 1`
`J(n,k) = (J(n-1,k) + k-1 ) mod n +1`

---

<p align="center">
	A massive collaborative effort by <a href="https://github.com/OpenGenus/cosmos">OpenGenus Foundation</a> 
</p>

---
