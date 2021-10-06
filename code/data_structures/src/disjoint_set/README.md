<h1>DISJOINT SET</h1>

<h2>Description</h2>
<h3>Disjoint set is a data structure that stores a collection of disjoint (non-overlapping) sets. Equivalently, it stores a partition of a set into disjoint subsets. It provides operations for adding new sets, merging sets (replacing them by their union), and finding a representative member of a set.</h3>

<h2>Functions</h2>
<h3>Union() : Join two subsets into a single subset.</h3>
<h3>Find() :  Determine which subset a particular element is in. This can be used for determining if two elements are in the same subset.</h3>

<h2>Time Complexity</h2>
<h3>Union() : O(n) </h3>
<h3>Find() : O(n) [Without path compression]</h3>
<h3>Find() : O(log n) [With path compression]</h3>

