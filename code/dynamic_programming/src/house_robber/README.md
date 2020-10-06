# House Robber

## Description

Given a list of non-negative integers representing the amount of money in a house, determine the maximum amount of money a robber can rob tonight given that he cannot rob adjacent houses.

## Solution

e.g [1,2,3]<br>
Considering the constraint,<br>
robber has choice 1: houses with amount 1 and 3<br>
Or choice 2: house with amount 2<br>

Thus, 1st choice gives the maximum amount of money.<br>

Considering n is the current house to be robbed<br>
choice 1: memo[n]+memo[n-2]<br>
choice 2: memo[n-1]<br>

The solution can be represented as the following expression:<br>
Maximum((memo[n]+memo[n-2]), memo[n-1])<br>

## Time and Space complexity

Time complexity: O(n), n is number of elements in the input array<br>
Space complexity: O(n), space is required for the array
