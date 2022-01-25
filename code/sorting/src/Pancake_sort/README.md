# Pancake sort

Who doesnt't like to have a pancake in the breakfast with Maple syrup and some fruits and ice cream, everyone right!! If you are a pancake lover then you might be able to connect with this problem.
Everyone loves to make pancake until its time to flip them at the right time and not making it burn or break

# What is exactly Pancake sort

Just like its name, it resembles sorting pancakes on a plate with a spatula, where you can only flip some of the top pancakes in the plate using spatula.
The goal is to sort the sequence in as few reversals as possible.

# Lets Solve

This is very close to resemblance with selection sort as we one by one place maximum element at the end and reduce the size of current array by one. 

# Explanation

We are given an array arr[] and size of arr[] be n, sort the array by performing a series of pancake flips.

In one pancake flip we do the following steps:

1.Choose an integer k where 1 <= k <= arr.length.
2.reverse the sub-array arr[0...k-1] (0-indexed).

# Approach

The idea behind pancake sort is similar to Selection Sort. In every iteration, we find the maximum element in the sequence and place it at the end, and reduce the size of the sequence by one.
Given an array of integers Arr:

Write a function flip(Arr, i) that reverses the order of the first i elements in the array arr.
Write a function pancakeSort(Arr) that sorts and returns the input array. You are allowed to use only the function flip in order to make changes in the array.

# Algorithm 

Let the given array be Arr[] and size of the array be 'n'

Start from the current size 'n' and reduce the current size by one while it is greater than one. Let the current size be c. Do the following for every 'c'.
Find the index 'i' of the maximum element in Arr[0....c-1].
Call flip(Arr,i)
Call flip(Arr,c-1)

Example - 

```initial pancake order : [3, 5, 2, 1, 7, 6, 4]```

First flip : [3, 5, 2, 1, 7, 6, 4]
after first flip : [7, 1, 2, 5, 3, 6, 4]

Second flip : [7, 1, 2, 5, 3, 6, 4]
after second flip : [4, 6, 3, 5, 2, 1, 7]

Third flip : [4, 6, 3, 5, 2, 1, 7]
after third flip : [6, 4, 3, 5, 2, 1, 7]

Fourth flip : [6, 4, 3, 5, 2, 1, 7]
after fourth flip : [1, 2, 5, 3, 4, 6, 7]

Fifth flip : [1, 2, 5, 3, 4, 6, 7]
after fifth flip : [5, 2, 1, 3, 4, 6, 7]

Sixth flip : [5, 2, 1, 3, 4, 6, 7]
after sixth flip : [4, 3, 1, 2, 5, 6, 7]

Seventh flip : [4, 3, 1, 2, 5, 6, 7]
after seventh flip : [2, 1, 3, 4, 5, 6, 7]

Eight flip : [2, 1, 3, 4, 5, 6, 7]
after eighth flip : [1, 2, 3, 4, 5, 6, 7]

# Time and Space Complexity

The number of flips required to sort the array is in the order of 'n'. In the best case, the array is sorted and no flips are required. In the worst case, the array consists of alternating smallest and largest numbers ([0, 9, 1, 8, 2, 7, 3, 6, 5, 4]) and requires 2n-3 flips. Therefore, in terms of number of flips the time complexity is O(n).
Since the only operation considered here is "flip", the comparisons become irrelevant. So, the comparison operations for finding the maximum element of the current array is ignored and time complexity is only represented in terms of the number of flips, also known as the pancake number.

```Worst case time complexity: Θ(n)```
```Average case time complexity: Θ(n)```
```Space complexity: Θ(n)```

