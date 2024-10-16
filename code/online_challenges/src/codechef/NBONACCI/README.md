# Problem link

[NBONACCI](https://www.codechef.com/problems/NBONACCI).

# Description

An N-bonacci sequence is an infinite sequence F1,F2,… such that for each integer i>N, Fi is calculated as f(Fi−1,Fi−2,…,Fi−N), where f is some function. A XOR N-bonacci sequence is an N-bonacci sequence for which f(Fi−1,Fi−2,…,Fi−N)=Fi−1⊕Fi−2⊕…⊕Fi−N, where ⊕
denotes the bitwise XOR operation.

Recently, Chef has found an interesting sequence S1,S2,…, which is obtained from prefix XORs of a XOR N-bonacci sequence F1,F2,…. Formally, for each positive integer i, Si=F1⊕F2⊕…⊕Fi. You are given the first N elements of the sequence F, which uniquely determine the entire sequence S.

You should answer Q queries. In each query, you are given an index k and you should calculate Sk. It is guaranteed that in each query, Sk does not exceed 10^50.
