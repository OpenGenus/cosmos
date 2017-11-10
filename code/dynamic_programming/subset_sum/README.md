# cosmos
Your personal library of every algorithm and data structure code that you will ever encounter

Collaborative effort by [OpenGenus](https://github.com/opengenus)

### Subset Sum Problem

In computer science, the subset sum problem is an important problem in complexity theory and cryptography.
The problem is this: Given a set of non-negative integers and an integer s, does any non-empty subset sum to s?
Subset sum can also be thought of as a special case of the knapsack problem. One interesting special 
case of subset sum is the partition problem, in which s is half of the sum of all elements in the set.

#### The algorithm

Let isSubsetSum(int set[], int n, int s) be the function to find whether there is a subset of set[] 
with sum equal to s, where n is the number of elements in set[].

The isSubsetSum problem can be divided into two subproblems

(a) Include the last element, recur for n = n-1, sum = sum – set[n-1]
                                                                 (b) Exclude the last element, recur for n = n-1.

If any of the above the above subproblems return true, then return true.

#### Using Dynamic Programming

We create a boolean 2D table subset[][] and fill it in bottom up manner. The value of 
subset[i][j] will be true if there is a subset of set[0..j-1] with sum equal to i, otherwise false. 
Finally, we return subset[sum][n].

For example, for n = 4 set = {3,2,7,1} and s = 6

![](https://github.com/arijitkar98/al-go-rithms/blob/master/dp/subset_sum/Subset-Sum_Problem.jpg)

The answer is true.
