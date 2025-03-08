# Problem link

[XORIER](https://www.codechef.com/problems/XORIER/)

# Description

Chef is stuck at the following problem. Help him solve it!

Chef has a sequence of integers A1,A2,…,AN. He should find the number of pairs (i,j) such that 1 ≤ i < j ≤ N and the bitwise XOR of Ai and Aj can be written as a sum of two (not necessarily different) prime numbers with the same parity (both odd or both even).

# Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N.
The second line contains N space-seprated integers A1,A2,…,AN.
# Output
For each test case, print a single line containing one integer — the number of valid pairs.

# Constraints
1≤T≤10
1≤N≤105
1≤Ai≤106 for each valid i

# Subtasks
Subtask #1 (10 points): 1≤N≤103
Subtask #2 (90 points): original constraints

# Example Input
1
5
2 4 8 1 3
# Example Output
3
# Explanation
Example case 1: The three valid pairs are (1,2), (1,3) and (2,3). For example, A1⊕A2=2⊕4=6=3+3.
