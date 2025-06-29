# Segment Tree

A **Segment Tree** is a binary tree used for answering **range queries** (like sum, min, max) and performing **point or range updates** efficiently in logarithmic time.

## Variants

- `segment_tree.cpp`: Basic segment tree supporting range sum queries and point updates.
- `segment_tree_lazy.cpp`: Segment tree with **lazy propagation** to support range updates efficiently.

## Time Complexity

| Operation     | Basic Segment Tree | With Lazy Propagation |
|---------------|--------------------|------------------------|
| Build         | O(N)               | O(N)                   |
| Point Update  | O(log N)           | O(log N)               |
| Range Query   | O(log N)           | O(log N)               |
| Range Update  | N/A                | O(log N)               |

Where `N` is the size of the input array.

## Sample Usage

```cpp
// Basic segment tree
SegmentTree st(data);
st.update(index, value);
st.query(left, right);

// Segment tree with lazy propagation
SegmentTreeLazy st(data);
st.updateRange(left, right, delta);
st.queryRange(left, right);
