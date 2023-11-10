<h2><a href="https://practice.geeksforgeeks.org/problems/d064cc0468a5c2bb7817ecd7c1bc59ce25e23613/1">Minimum BST Sum Subtree</a></h2><h3>Difficulty Level : Hard</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given a <strong>binary tree </strong>and a <strong>target</strong>, find the number of node in the minimum sub-tree with the given sum equal to the target which is also a binary search tree.</span></p>

<p><strong><span style="font-size:18px">Example 1:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
           13
         /    \
       5       23
      / \      / \
     N   17   N   N
&nbsp;        /
&nbsp;       16
<strong>Target</strong>: 38
<strong>Output:</strong> 3
<strong>Explanation</strong>: 5,17,16 is the smallest subtree
with length 3.</span></pre>

<p>&nbsp;</p>

<p><strong><span style="font-size:18px">Example 2:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
             7
           /   \
          N    23
             /   \
            10    23
&nbsp;          /  \   / \
&nbsp;         N   17 N   N
<strong>Target</strong>: 73
<strong>Output:</strong> -1
<strong>Explanation</strong>: No subtree is bst for the given target.</span></pre>

<p><span style="font-size:18px"><strong>Your Task:</strong> &nbsp;<br>
You don't need to read input or print anything. Your task is to complete the function <strong>minSubtreeSumBST</strong>() which takes the tree <strong>root</strong> and <strong>target</strong> as input parameters which is a <strong>binary Tree </strong>and returns the length of the minimum subtree having a sum equal to the target but which is a&nbsp;<strong>binary search tree</strong>.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity</strong>: O(N), where N is no. of nodes</span><br>
<span style="font-size:18px"><strong>Expected Space Complexity:&nbsp;</strong>O(h), where h is the height of the tree</span><br>
<br>
<span style="font-size:18px"><strong>Constraints:</strong><br>
1 &lt;= N &lt;= 10^5</span></p>
</div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Binary Search Tree</code>&nbsp;<code>Tree</code>&nbsp;<code>Data Structures</code>&nbsp;<code>Algorithms</code>&nbsp;