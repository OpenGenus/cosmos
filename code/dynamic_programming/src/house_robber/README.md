# House Robber

## Description

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

## Solution

If the robber robs two adjacent houses, alarm will set off. Thus, the robber should rob alternate houses.

e.g [1,2,3,4]
Consider each element in array represents the amount of money each house has.
The robber has following choice of houses to rob either 1,3 or 2,4 or 1,4

Quick note, the solution involves dynamic programming.

Read ahead to know detailed explanation of solution.

These choices seems a bit overwhelming, how about we start simple.

Now, say a street has only one house e.g [2] The robber will only rob that house.

How about two houses? e.g. [1,2]
The robber will rob the house with maximum amount of money i.e. 2 (index 1) in this case.

How about three houses? e.g [1,2,3]
When robber is at 1st house (0 index), the robber is clueless if he should rob it or leave it. As next house might have larger stash. So he is going sneak in the 1st house, memo its stash and move ahead.
Following similar approach he will sneak into the last house.
Now, the robber has two choices
1. Rob the current house and the house before its immediate neighbour i.e 3 and 1, total 4
2. Rob maximum of immediate neighbour and the house before it i.e. Maximum(2,1)

The answer is obvious, the robber will rob maximum of these two choices.

Now if a street has more houses, he will sneak into the house, consider it as a last one and memo the amount he will get by following above decision making process.
Now this memo is simulated in programming using an array. The approach of noting intermediate results
is considered as dynamic programming.

We can write an expression for above two choices.

Maximum((memo[n]+memo[n-2]), memo[n-1]), where n is the current house to be robbed.

## Time and Space complexity

Time complexity: O(n), n is number of elements in the input array
Space complexity: O(n), space is required for the array
