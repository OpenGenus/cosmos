# Cosmos

![alt text](https://i.imgur.com/EbHZd1J.png)
# Jump Search  

Jump Search is a searching algorithm for sorted arrays. The idea is to skip some elements by jumping head in the array. In order of time complexity: Linear Search O(n) < Jump Search  O(√n) < Binary Search O(Log n). However, Jump Search has an advantage over Binary search in that you will only ever traverse backwards one time.

## Procedure
1. Set the step length to be equal to the √n, and the previous to be the 0th index
2. Compare the value of the step element with the target value.
3. If they match, it is returned.
4. If the step value is less than the target value, set previous to be to be current step, jump again. 
5. If the step value is greater than the target value, reverse linear search until value is found, or until previous is reached.

[Jump Search Wikipedia](https://en.wikipedia.org/wiki/Jump_search)

---

<p align="center">
	A massive collaborative effort by <a href="https://github.com/OpenGenus/cosmos">OpenGenus Foundation</a> 
</p>

---
