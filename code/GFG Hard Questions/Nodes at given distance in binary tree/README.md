<h2><a href="https://practice.geeksforgeeks.org/problems/nodes-at-given-distance-in-binary-tree/1">Nodes at given distance in binary tree</a></h2><h3>Difficulty Level : Hard</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given a binary tree, a target node in the binary tree, and an integer value k, find all the nodes that are at distance k from the given target node. No parent pointers are available.<br><strong>Note</strong>: </span></p>
<ul>
<li><span style="font-size: 18px;">You have to return the list in sorted order.</span></li>
<li><span style="font-size: 18px;">The tree will <strong>not </strong>contain <strong>duplicate </strong>values.</span></li>
</ul>
<p><strong><span style="font-size: 18px;">Example 1:</span></strong></p>
<pre><span style="font-size: 18px;"><strong>Input:      </strong>
          20
        /    \
      8       22 
    /   \
   4    12 
       /   \
      10    14</span>
<span style="font-size: 18px;">Target Node = 8
K = 2</span>
<span style="font-size: 18px;"><strong>Output:</strong> 10 14 22</span>
<span style="font-size: 18px;"><strong>Explanation: </strong>The three nodes at distance 2
from node 8 are 10, 14, 22.</span>
<span style="font-size: 18px;"><img style="height: 240px; width: 173px;" src="https://media.geeksforgeeks.org/wp-content/uploads/20190426123252/Btree1.jpg" alt=""></span>
</pre>
<p><span style="font-size: 18px;"><strong>Example 2:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:      </strong>
         20
       /    \
      7      24
    /   \
   4     3
        /  
       1    </span>
<span style="font-size: 18px;">Target Node = 7
K = 2</span>
<span style="font-size: 18px;"><strong>Output:</strong> 1 24</span>
</pre>
<p><span style="font-size: 18px;"><strong>Your Task: &nbsp;</strong><br>You don't need to read input or print anything. Complete the function<strong> KDistanceNodes()</strong> which takes the root of the tree, target, and K as input parameters and returns a list of nodes at k distance from target in a sorted order.</span></p>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity: </strong>O(N*logN)<br><strong>Expected Auxiliary Space: </strong>O(Height of tree)</span></p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ N ≤ 10<sup>5</sup><br>1 ≤ data of node ≤ 10<sup>9</sup><br>1 ≤ target ≤ 10<sup>9</sup><br>1 ≤ k ≤ 20</span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Flipkart</code>&nbsp;<code>Accolite</code>&nbsp;<code>Amazon</code>&nbsp;<code>Microsoft</code>&nbsp;<code>Samsung</code>&nbsp;<code>Hike</code>&nbsp;<code>Ola Cabs</code>&nbsp;<code>Walmart</code>&nbsp;<code>Goldman Sachs</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Tree</code>&nbsp;<code>Data Structures</code>&nbsp;