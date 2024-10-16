# Problem Link:
[LEPERMUT](https://www.codechef.com/problems/LEPERMUT/)

# Description
The Little Elephant likes permutations. This time he has a permutation A[1], A[2], ..., A[N] of numbers 1, 2, ..., N.

He calls a permutation A good, if the number of its inversions is equal to the number of its local inversions. The number of inversions is equal to the number of pairs of integers (i; j) such that 1 ≤ i < j ≤ N and A[i] > A[j], and the number of local inversions is the number of integers i such that 1 ≤ i < N and A[i] > A[i+1].

The Little Elephant has several such permutations. Help him to find for each permutation whether it is good or not. Print YES for a corresponding test case if it is good and NO otherwise.