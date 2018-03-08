# Rod Cutting
Given a rod of length n units and an array of prices p<sub>i</sub> for rods of length i = 1, 2, . . . ,n. Determine the maximum revenue r <sub>n</sub> obtainable by cutting the rod and selling the pieces.
**For Example - **
Let the table of prices be - 
length (i) | 1|2|3|4|5|6|7|8|9|10  
-----------|--|-|-|-|-|--|-|--|--|------------  
price (p<sub>i</sub>)|1|5|8|9|10|17|17|20|24|30

For a rod of length n = 4, maximum revenue is obtained by cutting the rod into two pieces each of length 2 and the maximum revenue obtained is 10.

 
## Explanation
This problem satisfies both properties of Dynamic programming and can be solved by the following recurrence relation.


### Recurrence Relation
r<sub>n</sub> = max (p<sub>i</sub> + r<sub>n-i</sub>)   for all 1 <= i <= n

## Complexity
Time complexity : O(n^2)
Space complexity : O(n)

---
<p align="center">
	A massive collaborative effort by <a href="https://github.com/OpenGenus/cosmos">OpenGenus Foundation</a> 
</p>

---

