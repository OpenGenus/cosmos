# Unbounded Knapsack

## Description

Its an unbounded knapsack problem as we can use 1 or more instances of any resource. A simple 1D array, say dp[ W + 1 ] can be used such that dp[i] stores the maximum value which can achieved using all items and i capacity of knapsack. Note that we use 1D array here which is different from classical knapsack where we used 2D array. Here number of items never changes. We always have all items available.

## Solution

We will maintain an array knapsack[ W + 1 ] where ` j ` index stores the maximum value that can be fitted in a knapsack of capacity ` j `.
Then, knapsack [ W ] gives the maximum value that can fitted in the knapsack of given weight i.e ` W `.
- Let us find the structure of the optimal solution.
- Let knapsack ( j ) denotes the maximum value that can be fitted in a knapsack of weight ` j `.
- While computing knapsack ( j ), we need to decide whether to select or reject an instance of a weight ` i `.
- If we reject all the weights, then knapsack ( j ) = knapsack ( j – 1 ) and
- If we select an instance of weight ` i `, then
- knapsack ( j ) = maximum [ knapsack ( j – W ( i ) ) + V ( i ) for i = 0, … , n – 1 ]
- Thus, the structure of the optimal solution is defined recursively as :
- knapsack [ j ] = max ( knapsack [ j – 1 ] , { knapsack [ j – w [ i ] ] + v [ i ] for i = 0…n-1 } )

# Refrences
This Solution has been referred from 
- www.geeksforgeeks.org
- csegeek.com

---

<p align="center">
A massive collaborative effort by <a href="https://github.com/opengenus/cosmos">OpenGenus Foundation</a>
</p>

---
