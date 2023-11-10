# Problem Link:

[CASH](https://www.codechef.com/FEB20B/problems/CASH/)

# Description

There are N bags with coins in a row (numbered 1 through N); for each valid i, the i - th bag contains A(i) coins. Chef should make the number of coins in each bag divisible by a given integer K in the following way:

- choose an integer c between 0 and N (inclusive)
- take some coins from the first c bags ― formally, for each i (1 ≤ i ≤ c), he may choose any number of coins between 0 and A(i) inclusive and take them out of the i-th bag
- move some of these coins to some of the last N−c bags ― formally, for each i ( c+1 ≤ i ≤ N), he may place a non-negative number of coins in the i-th bag

The number of coins placed in the last N−c bags must not exceed the number of coins taken out from the first c bags, but there may be some coins left over. Let's denote the number of these coins by RR. You should find the smallest possible value of RR.