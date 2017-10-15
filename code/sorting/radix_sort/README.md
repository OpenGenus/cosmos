# Radix sort

**Radix sort** is a non-comparative integer sorting algorithm that sorts data with integer keys by grouping keys by the individual digits which share the same significant position and value.

## Overview

The idea of Radix Sort is to do digit by digit sort starting from least significant digit to most significant digit. Radix sort uses counting sort as a subroutine to sort. Two classifications of radix sorts are **least significant digit (LSD) radix sorts** and **most significant digit (MSD) radix sorts**. LSD radix sorts process the integer representations starting from the least digit and move towards the most significant digit. MSD radix sorts work the other way around.

## Algorithm

1. Do following for each digit i where i varies from least significant digit to the most significant digit.
   1. Sort input array using counting sort (or any stable sort) according to the i’th digit. 1a

**Example**

Original, unsorted list:

  ```170, 45, 75, 90, 802, 24, 2, 66```
  
Sorting by least significant digit (1s place) gives: **Notice that we keep 802 before 2, because 802 occurred before 2 in the original list, and similarly for pairs 170 & 90 and 45 & 75**

  ```170, 90, 802, 2, 24, 45, 75, 66```

Sorting by next digit (10s place) gives: **Notice that 802 again comes before 2 as 802 comes before 2 in the previous list**
  
  ```802, 2, 24, 45, 66, 170, 75, 90```

Sorting by most significant digit (100s place) gives:
  
  ```2, 24, 45, 66, 75, 90, 170, 802```
  
  ## Running Time
  
 Let there be d digits in input integers. Radix Sort takes O(d*(n+b)) time where b is the base for representing numbers, for example, for decimal system, b is 10. What is the value of d? If k is the maximum possible value, then d would be O(logb(k)). So overall time complexity is O((n+b) * logb(k)). Which looks more than the time complexity of comparison based sorting algorithms for a large k. Let us first limit k. Let k <= nc where c is a constant. In that case, the complexity becomes O(nLogb(n)). But it still doesn’t beat comparison based sorting algorithms.
What if we make value of b larger?. What should be the value of b to make the time complexity linear? If we set b as n, we get the time complexity as O(n). In other words, we can sort an array of integers with range from 1 to nc if the numbers are represented in base n (or every digit takes log2(n) bits).

## Further Reading

https://en.wikipedia.org/wiki/Radix_sort
