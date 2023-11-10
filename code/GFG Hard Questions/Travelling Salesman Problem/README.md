<h2><a href="https://practice.geeksforgeeks.org/problems/travelling-salesman-problem2732/1">Travelling Salesman Problem</a></h2><h3>Difficulty Level : Hard</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given a matrix cost of size n where cost[i][j] denotes the cost of moving from city i to city j. Your task is to complete a tour from the city 0 (0 based index) to all other cities such that you visit each city exactly once and then at the end come back to city 0 in min cost.</span><br>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Example 1:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>cost = {{0,111},{112,0}}
<strong>Output: </strong>223
<strong>Explanation: </strong>We can visit 0-&gt;1-&gt;0 and 
cost = 111 + 112.</span>
</pre>
<p><span style="font-size: 18px;"><strong>Example 2:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>cost = {{0,1000,5000},{5000,0,1000},
{1000,5000,0}}
<strong>Output: </strong>3000
<strong>Explanation: </strong>We can visit 0-&gt;1-&gt;2-&gt;0 and cost 
= 1000+1000+1000 = 3000</span>
</pre>
<p>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Your Task:</strong><br>You don't need to read or print anything. Your task is to complete the function&nbsp;<strong>total_cost()&nbsp;</strong>which takes cost as input parameter and returns the total cost to visit each city exactly once starting from city 0 and again comback to city 0.</span><br>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity:&nbsp;</strong>O(2<sup>n</sup>&nbsp;* n<sup>2</sup>)<br><strong>Expected Space Compelxity:&nbsp;</strong>O(2<sup>n</sup>&nbsp;* n)</span><br>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 &lt;= n &lt;= 20<br>1 &lt;= cost[i][j] &lt;= 10<sup>3</sup></span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Microsoft</code>&nbsp;<code>Samsung</code>&nbsp;<code>Google</code>&nbsp;<code>Opera</code>&nbsp;