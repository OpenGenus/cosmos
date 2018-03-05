# Josephus Problem  

Josephus Problem is a theoretical Counting Game Problem.  
n people stand in a circle and are numbered from 1 to n in clockwise direction.  
Starting from 1 in clockwise direction each person kills the k<sup>th</sup> person next to him and this continues till
a single person is left. The task is to choose a suitable position in initial circle to avoid execution.

## Explaination

For example, if n = 5 and k = 2, then the safe position is 3. Firstly, the person at position 2 is executed, then person at position 4 is executed, then person at position 1 is killed. Finally, the person at position 5 is executed. So the person at position 3 survives.  

If n = 7 and k = 3, then the safe position is 4. The persons at positions 3, 6, 2, 7, 5, 1 are executed in order, and person at position 4 survives.

Let J(n,k) represent the position of survivor when there are n person and k denotes count of each step i.e. k-1 person are skipped and k<sup>th</sup> person is executed.

We observe that after the first kill i.e. the killing of second person we have n-1 people so problem can be reduced to find safest position with n-1 people when person on position k is executed.

### Recurrence Relation 

`J(1,k) = 1`
`J(n,k) = (J(n-1,k) + k-1 ) mod n +1`
