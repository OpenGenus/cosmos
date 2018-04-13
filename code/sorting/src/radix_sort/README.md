# Radix Sort
Radix sort is a **non-comparative integer sorting algorithm**. 
It works by doing digit by digit sort starting from least significant digit to most significant digit. Radix sort uses counting sort as a subroutine to sort the digits in each place value. This means that for a three-digit number in base 10, counting sort will be called to sort the 1's place, then it will be called to sort the 10's place, and finally, it will be called to sort the 100's place, resulting in a completely sorted list. 

## Explanation
Consider the following example:

Original, unsorted list:

```170, 45, 75, 90, 802, 2, 24, 66```

Sorting by least significant digit (1s place) gives:

```170, 90, 802, 2, 24, 45, 75, 66```

Notice that we keep 802 before 2, because 802 occurred before 2 in the original list, and similarly for pairs 170 & 90 and 45 & 75.
Sorting by next digit (10s place) gives:

```802, 2, 24, 45, 66, 170, 75, 90```

Notice that 802 again comes before 2 as 802 comes before 2 in the previous list.
Sorting by most significant digit (100s place) gives:

```2, 24, 45, 66, 75, 90, 170, 802```

It is important to realize that each of the above steps requires just a single pass over the data, since each item can be placed in its correct bucket without having to be compared with other items.
Some radix sort implementations allocate space for buckets by first counting the number of keys that belong in each bucket before moving keys into those buckets. The number of times that each digit occurs is stored in an array. Consider the previous list of keys viewed in a different way:

```170, 045, 075, 090, 002, 024, 802, 066```

The first counting pass starts on the least significant digit of each key, producing an array of bucket sizes:
```
2 (bucket size for digits of 0: 170, 090)
2 (bucket size for digits of 2: 002, 802)
1 (bucket size for digits of 4: 024)
2 (bucket size for digits of 5: 045, 075)
1 (bucket size for digits of 6: 066)
```

A second counting pass on the next more significant digit of each key will produce an array of bucket sizes:
```
2 (bucket size for digits of 0: 002, 802)
1 (bucket size for digits of 2: 024)
1 (bucket size for digits of 4: 045)
1 (bucket size for digits of 6: 066)
2 (bucket size for digits of 7: 170, 075)
1 (bucket size for digits of 9: 090)
```
A third and final counting pass on the most significant digit of each key will produce an array of bucket sizes:
```
6 (bucket size for digits of 0: 002, 024, 045, 066, 075, 090)
1 (bucket size for digits of 1: 170)
1 (bucket size for digits of 8: 802)
```
At least one LSD radix sort implementation now counts the number of times that each digit occurs in each column for all columns in a single counting pass. Other LSD radix sort implementations allocate space for buckets dynamically as the space is needed.

## Algorithm
```
Radix-Sort (list, n) 
   shift = 1 
   for loop = 1 to keysize do 
      for entry = 1 to n do 
         bucketnumber = (list[entry].key / shift) mod 10 
         append (bucket[bucketnumber], list[entry]) 
      list = combinebuckets() 
      shift = shift * 10 
```

## Complexity
**Time complexity**
- Worst, average and best case time complexity: `O(nk)`
Where, **n** is the input numbers with maximum **k** digits.

If the numbers are of finite size, the algorithm runs in `O(n)` asymptotic time. 

**Space complexity**: `O(n + k)`

---
<p align="center">
	A massive collaborative effort by <a href="https://github.com/OpenGenus/cosmos">OpenGenus Foundation</a> 
</p>

---