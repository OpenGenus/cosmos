<h2><a href="https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1">Palindromic Partitioning</a></h2><h3>Difficulty Level : Hard</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given a string <strong>str</strong>,&nbsp;a partitioning of the string is a&nbsp;palindrome partitioning&nbsp;if every sub-string of the partition is a palindrome.&nbsp;Determine the fewest cuts needed for palindrome partitioning of the given string.</span></p>

<p><br>
<strong><span style="font-size:18px">Example 1:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input:</strong> str = "ababbbabbababa"
<strong>Output:</strong> 3
<strong>Explaination:</strong> After 3 partitioning substrings 
are "a", "babbbab", "b", "ababa".</span>
</pre>

<p><strong><span style="font-size:18px">Example 2:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input:</strong> str = "aaabba"
<strong>Output:</strong> 1
<strong>Explaination:</strong> The substrings after 1
partitioning are "aa" and "abba".</span></pre>

<p><br>
<span style="font-size:18px"><strong>Your Task:</strong><br>
You do not need to read input or print anything, Your task is to complete the function <strong>palindromicPartition()</strong> which takes the string str as the input parameter and returns the minimum number of partitions required.</span></p>

<p><br>
<span style="font-size:18px"><strong>Expected Time Complexity:</strong> O(n*n) [n is the length of the string str]<br>
<strong>Expected Auxiliary Space:</strong> O(n*n)</span></p>

<p><br>
<span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ length of str ≤ 500</span></p>
</div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Amazon</code>&nbsp;<code>Microsoft</code>&nbsp;<code>Google</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Dynamic Programming</code>&nbsp;<code>Algorithms</code>&nbsp;