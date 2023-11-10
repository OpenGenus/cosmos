Kadane's Algorithm is commonly known for **Finding the largest sum of a subarray** in linear time O(N).

A **Subarray** of an n-element array is an array composed from a contiguous block of the original array's elements. For example, if array = [1,2,3] then the subarrays are  [1], [2], [3], [1,2], [2,3] and [1,2,3] . Something like  [1,3] would not be a subarray as it's not a contiguous subsection of the original array.

So,
 We need to look for all positive contiguous segments of the array (maximum_ending_here is used for this). And then, keep track of maximum sum contiguous segment among all positive segments (maximum_overall is used for this). Each time we get maximum_ending_here greater than maximum_overall, update maximum_overall.

So, this is covered in a greater detail in this article.

Link to the article: https://iq.opengenus.org/kadane-algorithm/