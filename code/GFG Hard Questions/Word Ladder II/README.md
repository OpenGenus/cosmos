<h2><a href="https://practice.geeksforgeeks.org/problems/word-ladder-ii/1">Word Ladder II</a></h2><h3>Difficulty Level : Hard</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given two distinct words <strong>startWord</strong> and <strong>targetWord</strong>, and a list&nbsp;denoting <strong>wordList</strong>&nbsp;of unique words of equal lengths. </span> <span style="font-size:18px">Find all shortest transformation sequence(s) from startWord to targetWord. You can return them in any order possible.</span><br>
<span style="font-size:18px">Keep&nbsp;the following conditions in mind:</span></p>

<ul>
	<li><span style="font-size:18px">A word can only consist of lowercase characters.</span></li>
	<li><span style="font-size:18px">Only one letter can be changed in each transformation.</span></li>
	<li><span style="font-size:18px">Each transformed word must exist in the wordList including the targetWord.</span></li>
	<li><span style="font-size:18px">startWord may or may not be part of the&nbsp;wordList.</span><span style="font-size:18px"> </span></li>
	<li><span style="font-size:18px">Return an empty list if there is no such transformation sequence.</span></li>
</ul>

<p><span style="font-size:18px">The first part of this problem can be found <a href="https://practice.geeksforgeeks.org/problems/word-ladder/1/">here</a>.</span></p>

<p><br>
<strong><span style="font-size:18px">Example 1:</span></strong></p>

<pre><strong><span style="font-size:18px">Input:
</span></strong><span style="font-size:18px">startWord = "der", targetWord = "dfs",
wordList = {"des","der","dfr","dgt","dfs"}
<strong>Output:
</strong>der dfr dfs
der des dfs
<strong>Explanation:
</strong>The length of the smallest transformation is 3.
And the following are the only two ways to get
to targetWord:-
"der" -&gt; "des" -&gt; "dfs".</span>
<span style="font-size:18px">"der" -&gt; "dfr" -&gt; "dfs".</span>
</pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>startWord = "gedk", targetWord = "geek", 
wordList = {"geek", "gefk"}
<strong>Output:
</strong>"gedk" -&gt; "geek"</span>
</pre>

<p><br>
<span style="font-size:18px"><strong>Your Task:</strong><br>
You don't need to read or print anything, Your task is to complete the function&nbsp;findSequences<strong>()&nbsp;</strong>which takes startWord, targetWord and wordList as input parameter and returns a list of list of strings of the shortest transformation sequence from startWord to targetWord.<br>
<strong>Note: </strong>You don't have to return -1 in case of no possible sequence. Just return the Empty List.</span></p>

<p><br>
<span style="font-size:18px"><strong>Expected Time Compelxity:&nbsp;</strong>O(N*(logN * M * 26))<br>
<strong>Expected Auxiliary Space:&nbsp;</strong>O(N * M) where N = length of wordList and M = |wordList<sub>i</sub>|</span></p>

<p><br>
<span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ N ≤ 100<br>
1 ≤ M ≤ 10</span></p>
</div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Flipkart</code>&nbsp;<code>Amazon</code>&nbsp;<code>Microsoft</code>&nbsp;<code>Adobe</code>&nbsp;<code>Google</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Graph</code>&nbsp;<code>BFS</code>&nbsp;<code>Data Structures</code>&nbsp;<code>Algorithms</code>&nbsp;