# Problem Link:
[TADELIVE](https://www.codechef.com/problems/TADELIVE)

# Description
Andy and Bob are the only two delivery men of Pizza-chef store. Today, the store received N orders. It's known that the amount of tips may be different when handled by different delivery man. More specifically, if Andy takes the ith order, he would be tipped Ai dollars and if Bob takes this order, the tip would be Bi dollars.

They decided that they would distribute the orders among themselves to maximize the total tip money. One order will be handled by only one person. Also, due to time constraints Andy cannot take more than X orders and Bob cannot take more than Y orders. It is guaranteed that X + Y is greater than or equal to N, which means that all the orders can be handled by either Andy or Bob.

Please find out the maximum possible amount of total tip money after processing all the orders.

Input
The first line contains three integers N, X, Y.
The second line contains N integers. The ith integer represents Ai.
The third line contains N integers. The ith integer represents Bi.
Output
Print a single integer representing the maximum tip money they would receive.
Constraints
All test:
1 ≤ N ≤ 105
1 ≤ X, Y ≤ N; X + Y ≥ N
1 ≤ Ai, Bi ≤ 104
10 points:

1 ≤ N ≤ 20
30 points:

1 ≤ N ≤ 5000
60 points:
1 ≤ N ≤ 105
Example
Input:
5 3 3
1 2 3 4 5
5 4 3 2 1

Output:
21
Explanation
Bob will take the first three orders (or the first two) and Andy will take the rest (of course).