# Split Array Largest Sum

Given an array nums which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays.

Write an algorithm to minimize the largest sum among these m subarrays.

### Example 1:

    Input: nums = [7,2,5,10,8], m = 2
    Output: 18
    Explanation:
    There are four ways to split nums into two subarrays.
    The best way is to split it into [7,2,5] and [10,8],
    where the largest sum among the two subarrays is only 18.

### Example 2:

    Input: nums = [1,2,3,4,5], m = 2
    Output: 9

    Example 3:

    Input: nums = [1,4,4], m = 3
    Output: 4

 

### Constraints:

    1 <= nums.length <= 1000
    0 <= nums[i] <= 106
    1 <= m <= min(50, nums.length)


## Approach & Solution

We can break this problem into two smaller problems:

1. Given an array (A), number of cuts (CUTS), and the Largest sum of sub-arrays (MAX). Can you use at most CUTS cuts to segment array A into CUTS + 1 sub-arrays, such that the sum of each sub-array is smaller or equal to MAX?
    
2. Given a lower bound (left), an upper bound (right), an unknown bool array (B), and an API uses i as input and tells you whether B[i] is true. If we know there exists an index k, that B[i] is false when i < k, and B[i] is true when i >= k. What is the fastest way to find this k (the lower bound)?

Solution to the first sub-problem :

For the first question, we can follow these steps:

1. For each element in the array, if its value is larger than MAX, we know it's not possible to cut this array into groups that the sum of all groups are smaller than MAX. (Reason is straightforward, if A is [10, 2, 3, 5] and MAX is 6, even you have 3 cuts by which you can cut A as [[10], [2], [3], [5]], the group containing 10 will still be larger than 6).
    
2. Use greedy algorithm to cut A. Use an accumulator ACC to store the sum of the currently processed group, and process elements in A one by one. For each element num, if we add num with ACC and the new sum is still no larger than MAX, we update ACC to ACC + num, which means we can merge num into the current group. If not, we must use a cut before num to segment this array, then num will be the first element in the new group.
    
3. If we didn't go through A but already used up all cuts, then it's not possible only using CUTS cuts to segment this array into groups to make sure sum of each sub-array is smaller than MAX. Otherwise, if we can reach the end of A with cuts left (or use exactly CUTS cuts). It's possible to do so.

Then the first question is solved.

Solution to the second sub-problem :

1. The array B will be something like [false, false, ..., false, true, true, ..., true]. We want to find the index of the first true.
    
2. Use binary search to find this k. Keep a value mid, mid = (left + right) / 2. If B[mid] = false, then move the search range to the upper half of the original search range, a.k.a left = mid + 1, otherwise move search range to the lower half, a.k.a right = mid.

**Why this algorithm is correct...**

1. No matter how we cut the array A, the Largest sum of sub-arrays will fall into a range [left, right]. Left is the value of the largest element in this array. right is the sum of this array. (e.g., Given array [1, 2, 3, 4, 5], if we have 4 cuts and cut it as [[1], [2], [3], [4], [5]], the Largest sum of sub-arrays is 5, it cannot be smaller. And if we have 0 cut, and the only sub-array is [[1, 2, 3, 4, 5]], the Largest sum of sub-arrays is 15, it cannot be larger).
    
2. However, we cannot decide the number of cuts (CUTS), this is an given constraint. But we know there must be a magic number k, which is the smallest value of the Largest sum of sub-arrays when given CUTS cuts. When the Largest sum of sub-arrays is larger than k, we can always find a way to cut A within CUTS cuts. When the Largest sum of sub-arrays is smaller than k, there is no way to do this.

**Example**

For example, given array A [1, 2, 3, 4, 5]. We can use 2 cuts.

1. No matter how many cuts are allowed, the range of the possible value of the Largest sum of sub-arrays is [5, 15].
2. When given 2 cuts, we can tell the magic number k here is 6, the result of segmentation is [[1, 2, 3], [4], [5]].
3. When Largest sum of sub-arrays is in range [6, 15], we can always find a way to cut this array within two cuts. You can have a try.
4. However, when Largest sum of sub-arrays is in range [5, 5], there is no way to do this.
5. This mapped this problem into the second sub-problem. Bool array B here is [5:false, 6:true, 7:true, 8:true, ..., 15:true]. We want to find the index i of the first true in B, which is the answer of this entire question, and by solving the first sub-problem, we have an API that can tell us given an i (Largest sum of sub-arrays), whether B[i] is true (whether we can find a way to cut A to satisfy the constraint).
