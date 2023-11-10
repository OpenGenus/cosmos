<h2><a href="https://practice.geeksforgeeks.org/problems/minimum-window-subsequence/1">Minimum Window Subsequence</a></h2><h3>Difficulty Level : Hard</h3><hr><div class="problems_problem_content__Xm_eO"><p dir="ltr"><span style="font-size:18px">Given strings <strong>str1</strong> and <strong>str2</strong>, find the minimum (contiguous) substring W of str1, so that str2 is a subsequence of W.</span></p>

<p dir="ltr"><span style="font-size:18px">If there is no such window in str1 that covers all characters in str2, return the empty string "". If there are multiple such minimum-length windows, return the one with the left-most starting index.</span><br>
&nbsp;</p>

<p dir="ltr"><strong><span style="font-size:18px">Example 1:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input:</strong> </span>
<span style="font-size:18px">str1: geeksforgeeks</span>
<span style="font-size:18px">str2: eksrg</span>
<strong><span style="font-size:18px">Output: </span></strong>
<span style="font-size:18px">eksforg</span>
<strong><span style="font-size:18px">Explanation: </span></strong>
<span style="font-size:18px">Eksforg satisfies all required conditions. str2 is its subsequence and it is longest and leftmost among all possible valid substrings of str1.</span>
</pre>

<p dir="ltr"><strong><span style="font-size:18px">Example 2:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input:</strong> </span>
<span style="font-size:18px">str1: <code>abcdebdde</code></span>
<span style="font-size:18px">str2: bde</span>
<strong><span style="font-size:18px">Output: </span></strong>
<span style="font-size:18px">bcde</span>
<strong><span style="font-size:18px">Explanation: </span></strong>
<span style="font-size:18px"><code>"bcde" is the answer and "deb" is not a smaller window because the elements of T in the window must occur in order.</code></span></pre>

<p><strong><span style="font-size:18px">Your Task:</span></strong></p>

<p dir="ltr"><span style="font-size:18px">Complete the function string minWindow(string str1, string str2), which takes two strings as input and returns the required valid string as output.</span></p>

<p dir="ltr"><span style="font-size:18px"><strong>Expected Time Complexity:</strong> O(N<sup>2</sup>).</span></p>

<p dir="ltr"><span style="font-size:18px"><strong>Expected Auxiliary Space:</strong> O(N<sup>2</sup>).</span></p>

<p dir="ltr"><strong><span style="font-size:18px">Constraints:</span></strong></p>

<p dir="ltr"><span style="font-size:18px">0 &lt;= str1 &lt;= 1000</span></p>

<p dir="ltr"><span style="font-size:18px">0 &lt;= str2 &lt;= 100</span></p>

<p>&nbsp;</p>
</div>