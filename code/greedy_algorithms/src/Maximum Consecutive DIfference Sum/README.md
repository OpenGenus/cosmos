<h2> Maximize the sum of consecutive differences in a circular array </h2>
<p>Given an array A with values <strong>&nbsp; <em>a<sub>1</sub>, a<sub>2</sub>, a<sub>3</sub>, a<sub>4</sub>,..., a<sub>n</sub></em></strong>. Now, arrange all elements of array A such that sum of absolute differences of consecutive elements is maximum, i.e consider after an arrangement the array is <strong><em>b<sub>1</sub>, b<sub>2</sub>, b<sub>3</sub>, b<sub>4</sub>,..., b<sub>n</sub></em></strong> then maximize <code>|<em>b<sub>1</sub>-b<sub>2</sub>| + |<em>b<sub>2</sub>-b<sub>3</sub>| + |<em>b<sub>3</sub>-b<sub>4</sub>| + ..... + |<em>b<sub>n-1</sub>-b<sub>n</sub>| + |<em>b<sub>n</sub>-b<sub>1</sub>|</code>.</p>
<h3>Algorithm</h3>
<p>This problem can be easily solved by greedy approach by ensuring that values with greater difference remains closer so that sum of differences becomes maximum and it can be done by placing largest and smallest consecutive.</p>
<p>Approach is given below:</p>
<pre>
1. Lets array is a<sub>1</sub>,a<sub>2</sub>,a<sub>3</sub>,a<sub>4</sub>,...,a<sub>n</sub>.
2. After sorting array is b<sub>1</sub>,b<sub>2</sub>,b<sub>3</sub>,b<sub>4</sub>,...,b<sub>n</sub>.
3. Then arrangement b<sub>1</sub>,b<sub>n</sub>,b<sub>2</sub>,b<sub>n-1</sub>,...,b<sub>n/2</sub>,b<sub>(n/2)+1</sub> gives the maximum sum of consecutive differences.  
</pre>
</div>
<div id="algorithm">
</div>
<h3>Pseudocode</h3>
The pseudocode of given Problem is as follows:
<pre>
<code>1. Sort the given array A in non-decreasing order.</code>
<code>2. Declare an array S. </code>
<code>3. Initialise two pointers <strong><em>front</em></strong> and <strong><em>end</em></strong> pointing first and last element of sorted array respectively. </code>
<code>4. Append two elements in array S pointed by pointers <strong><em>front</em></strong> and <strong><em>end</em></strong> and increase <strong><em>front</em></strong> by 1 and decrease <strong><em>end</em></strong> by 1. </code>
<code>5. Repeat Step-4 untill <em><strong>front</strong></em> is not equal to <em><strong>end</strong></em>. </code>
</pre>

### Complexity

   Time Complexity: <code>O(nlog(n))</code>
