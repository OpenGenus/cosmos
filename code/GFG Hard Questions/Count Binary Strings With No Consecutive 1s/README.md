<h2><a href="https://practice.geeksforgeeks.org/problems/37f36b318a7d99c81f17f0a54fc46b5ce06bbe8c/1">Count Binary Strings With No Consecutive 1s</a></h2><h3>Difficulty Level : Hard</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given an integer <strong>N</strong>. Your task is to find the number of binary strings of length <strong>N</strong> having no consecutive 1s.<br>As the number can be large, return the answer modulo&nbsp;10^9+7.</span></p>
<p><span style="font-size: 18px;"><strong>Example 1:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong>
N = 3
<strong>Output:</strong>
5
<strong>Explanation:</strong>
All the binary strings of length 3 having</span>
<span style="font-size: 18px;">no consecutive 1s are "000", "001", "101",
"100" and "010".</span>
</pre>
<p><span style="font-size: 18px;"><strong>Example 2:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>
N = 2
<strong>Output:</strong>
3
<strong>Explanation: </strong>
All the binary strings of length 2 having no 
consecutive 1s are "10", "00" and "01".</span>
</pre>
<p><span style="font-size: 18px;"><strong>Your Task:</strong><br>You dont need to read input or print anything. Complete the function <strong>countStrings</strong><strong>() </strong>which takes the integer&nbsp;<strong>N&nbsp;</strong>as the input parameter, and returns the number of binary strings of length <strong>N&nbsp;</strong>with no consecutive 1s.</span></p>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity:</strong>&nbsp;O(log(N))<br><strong>Expected Auxiliary Space:</strong>&nbsp;O(Height of the recursive call stack)</span></p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ N&nbsp;≤ 10<sup>18</sup></span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Swiggy</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>number-theory</code>&nbsp;<code>Mathematical</code>&nbsp;<code>Fibonacci</code>&nbsp;<code>Algorithms</code>&nbsp;