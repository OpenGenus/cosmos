# Problem Link:
[Beautiful Triplets](https://www.hackerrank.com/challenges/beautiful-triplets/problem)

# Description
Given a sequence of integers a, a triplet (a[i], a[j], a[k]) is beautiful if:
1. i < j < k
2. a[j] - a[i] = a[k] - a[j] = d
Given an increasing sequenc of integers and the value of d, count the number of beautiful triplets in the sequence.

For example, the sequence arr = [2, 2, 3, 4, 5] and d = 1. There are three beautiful triplets, by index: [i, j, k] = [0, 2, 3], [1, 2, 3], [2, 3, 4]. To test the first triplet, arr[j] - arr[i] = 3 - 2 = 1 and arr[k] - arr[j] = 4 - 3 = 1.