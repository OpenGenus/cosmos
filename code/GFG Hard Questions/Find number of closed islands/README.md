<h2><a href="https://practice.geeksforgeeks.org/problems/find-number-of-closed-islands/1">Find number of closed islands</a></h2><h3>Difficulty Level : Hard</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given a <a href="https://www.geeksforgeeks.org/program-to-check-if-a-matrix-is-binary-matrix-or-not/">binary matrix</a> <strong>mat[][]</strong> of dimensions <strong>NxM</strong> such that 1 denotes land and <strong>0</strong> denotes water. Find the number of closed islands in the given matrix. </span></p>
<p><span style="font-size: 18px;"><strong>Note:</strong> A closed island is a group of <strong>1s</strong> surrounded by only <strong>0s</strong> on all the boundaries <strong>(except diagonals)</strong>. In simple words, a closed island is an island whose none of the <strong>1s</strong> lie on the edges of the matrix.</span></p>
<p><span style="font-size: 18px;"><strong>Example 1:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong></span>
<span style="font-size: 18px;">N = 5, M = 8
mat[][] =</span> <span style="font-size: 18px;">{{0, 0, 0, 0, 0, 0, 0, 1},&nbsp;
           {0, 1, 1, 1, 1, 0, 0, 1},&nbsp;
           {0, 1, 0, 1, 0, 0, 0, 1},&nbsp;
           {0, 1, 1, 1, 1, 0, 1, 0},&nbsp;
           {1, 0, 0, 0, 0, 1, 0, 1}}</span>
<span style="font-size: 18px;"><strong>Output:</strong>
2
<strong>Explanation</strong>:
</span><span style="font-size: 18px;">mat[][] =&nbsp;{{0, 0, 0, 0, 0, 0, 0, 1},&nbsp;
           {0, <strong>1, 1, 1, 1, </strong>0, 0, 1},&nbsp;
           {0, <strong>1</strong>, 0, <strong>1</strong>, 0, 0, 0, 1},&nbsp;
           {0, <strong>1, 1, 1, 1, </strong>0, <strong>1</strong>, 0},&nbsp;
           {1, 0, 0, 0, 0, 1, 0, 1}}&nbsp;
There are 2 closed islands. The islands in dark are closed because they are completely surrounded by 0s (water). There are two more islands in the last column of the matrix, but they are not completely surrounded by 0s. Hence they are not closed islands. </span>
</pre>
<p><span style="font-size: 18px;"><strong>Example 2:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong></span>
<span style="font-size: 18px;">N = 3, M = 3
mat[][] = {{1, 0, 0},
           {0, 1, 0},
           {0, 0, 1}}</span>
<span style="font-size: 18px;"><strong>Output: <br></strong></span><span style="font-size: 18px;">1<strong><br>Explanation:<br></strong>mat[][] = {{1, 0, 0},<br>          {0, <strong>1</strong>, 0},<br>          {0, 0, 1}}<br>There is just a one closed island.</span></pre>
<p><span style="font-size: 18px;"><strong>Your task:</strong></span><br><span style="font-size: 18px;">You dont need to read input or print anything. Your task is to complete the function <strong>closedIslands()</strong>&nbsp;which takes two integers N and M, and a 2D binary matrix mat as input parameters and returns the number of closed islands.</span></p>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity: </strong>O(N*M)<br><strong>Expected Auxiliary Space:&nbsp;</strong>O(N*M)</span></p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ N,M ≤ 500<br><br></span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Google</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>DFS</code>&nbsp;<code>Matrix</code>&nbsp;<code>Graph</code>&nbsp;<code>BFS</code>&nbsp;<code>union-find</code>&nbsp;<code>Data Structures</code>&nbsp;<code>Algorithms</code>&nbsp;