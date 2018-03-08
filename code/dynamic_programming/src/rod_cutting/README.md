# Rod Cutting
Given a rod of length n units and an array of prices p<sub>i</sub> for rods of length i = 1, 2, . . . ,n. Determine the maximum revenue r <sub>n</sub> obtainable by cutting the rod and selling the pieces.

 
## Explanation

Let the table of prices be - 

length (i) | 1|2|3|4|5|6|7|8|9|10  
-----------|--|-|-|-|-|--|-|--|--|------------  
price (p<sub>i</sub>)|1|5|8|9|10|17|17|20|24|30

For a rod of length n = 4

![Eight ways of cutting rod of length 4](https://www.cs.indiana.edu/~achauhan/Teaching/B403/LectureNotes/images/07-rodcutting-example.jpg)

> Image credits: ([CS Indiana](https://www.cs.indiana.edu/~achauhan/Teaching/B403/LectureNotes/images/07-rodcutting-example.jpg))

![Thought Process](https://cdn-images-1.medium.com/max/1400/1*b7bv3tR9kUrcVtvWeXFv4A.png)

> Image credits: ([Medium: Pratik Anand](https://medium.com/@pratikone/dynamic-programming-for-the-confused-rod-cutting-problem-588892796840))

Maximum revenue is obtained by cutting the rod into two pieces each of length 2. Thus, maximum revenue obtained is 10.

This problem satisfies both properties of Dynamic programming and can be solved by the following recurrence relation.


### Recurrence Relation
![Recurrence Relation](https://camo.githubusercontent.com/56668b0cbfac4b80697e6d03d03b54436ca047db/68747470733a2f2f6c617465782e636f6465636f67732e636f6d2f6769662e6c617465783f725f6e2533446d6178253238705f692532302b253230725f2537426e2d31253744253239253230253543746578742537422532307768657265253230253744253230312532302535436c65253230692532302535436c652532306e)

## Complexity
Time complexity : O(n^2)

Space complexity : O(n)

---
<p align="center">
	A massive collaborative effort by <a href="https://github.com/OpenGenus/cosmos">OpenGenus Foundation</a> 
</p>

---

