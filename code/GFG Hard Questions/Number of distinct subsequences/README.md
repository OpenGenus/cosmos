<h2><a href="https://practice.geeksforgeeks.org/problems/number-of-distinct-subsequences0909/1">Number of distinct subsequences</a></h2><h3>Difficulty Level : Hard</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given a string consisting of lower case English alphabets, the task is to find the number of distinct subsequences of the string<br><strong>Note:</strong> Answer can be very large, so, ouput will be answer modulo <strong>10<sup>9</sup>+7</strong>.</span></p>
<p><strong><span style="font-size: 18px;">Example 1:</span></strong></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong> <br>s = "gfg"</span>
<span style="font-size: 18px;"><strong>Output:</strong> <br>7
<strong>Explanation:</strong> <br>The seven distinct subsequences are "", "g", "f", "gf", "fg", "gg" and "gfg" .</span></pre>
<p><strong><span style="font-size: 18px;">Example 2:</span></strong></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong> <br>s = "ggg"</span>
<span style="font-size: 18px;"><strong>Output:</strong> <br>4
<strong>Explanation:</strong> <br>The four distinct subsequences are "", "g", "gg", "ggg".</span></pre>
<p><span style="font-size: 18px;"><strong>Your task:</strong><br>You do not need to read any input or print anything. The task is to complete the function <strong>distinctSubsequences()</strong>, which takes a string as input and returns an integer. </span></p>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity:</strong>&nbsp;O(|str|)<br><strong>Expected Auxiliary Space:</strong>&nbsp;O(|str|)</span></p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong></span><br><span style="font-size: 18px;">1 ≤ |s| ≤ 10<sup>5</sup><br>s contains lower case English alphabets</span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Strings</code>&nbsp;<code>Dynamic Programming</code>&nbsp;<code>Data Structures</code>&nbsp;<code>Algorithms</code>&nbsp;