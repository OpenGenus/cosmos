<h2><a href="https://practice.geeksforgeeks.org/problems/next-happy-number4538/1">Next Happy Number</a></h2><h3>Difficulty Level : Hard</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">For a given non-negative integer <strong>N</strong>, find the next smallest Happy Number. A number is called <strong>Happy</strong> if it leads to 1 after a sequence of steps. Wherein at each step the number is replaced by the sum of squares of its digits that is, if we start with Happy Number and keep replacing it with sum of squares of its digits, we reach 1 at some point. </span><br>&nbsp;<br><span style="font-size: 18px;"><strong>Example 1:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:
</strong>N = 8<strong>
Output:
</strong>10<strong>
Explanation:</strong>
Next happy number after 8 is 10 since
1*1 + 0*0 = 1</span>
</pre>
<p><span style="font-size: 18px;"><strong>Example 2:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:
</strong>N = 10<strong>
Output
</strong>13<strong>
Explanation:
</strong>After 10, 13 is the smallest happy number because
1*1 + 3*3 = 10, so we replace 13 by 10 and 1*1 + 0*0 = 1</span><span style="font-size: 18px;">.</span></pre>
<p><span style="font-size: 18px;"><strong>Your Task:</strong><br>You don't need to read input or print anything. Your task is to complete the function <strong>nextHappy()</strong>&nbsp;which takes&nbsp;an integer&nbsp;<strong>N</strong>&nbsp;as input parameters&nbsp;and returns an integer, next Happy number after N.</span></p>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity:</strong> O(Nlog<sub>10</sub>N)<br><strong>Expected Space Complexity:</strong> O(1)</span><br>&nbsp;<br><span style="font-size: 18px;"><strong>Constraints:</strong><br>1&lt;=N&lt;=10<sup>5</sup></span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Recursion</code>&nbsp;<code>Algorithms</code>&nbsp;