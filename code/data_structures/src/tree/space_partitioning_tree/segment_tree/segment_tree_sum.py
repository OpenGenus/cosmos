# Part of Cosmos by OpenGenus Foundation


class SegmentTree:
    def __init__(self, arr):
        self.n = len(arr)  # number of elements in array
        self.arr = arr  # stores given array
        self.segtree = [0] * (
            4 * self.n
        )  # stores segment tree, space required is 4 * (number of elements in array)
        self.build(0, 0, self.n - 1)

    def build(self, node, i, j):  # Time Complexity: O(n)
        if i == j:
            # Leaf node
            self.segtree[node] = self.arr[i]
            return
        # Recurse on left and right children
        mid = i + (j - i) / 2
        left = 2 * node + 1  # left child index
        right = 2 * node + 2  # right child index
        self.build(left, i, mid)
        self.build(right, mid + 1, j)
        # Internal node will be the sum of its two children
        self.segtree[node] = self.segtree[left] + self.segtree[right]

    def queryHelper(self, node, i, j, lo, hi):
        if j < lo or i > hi:
            # range represented by a node is completely outside the given range
            return 0
        if lo <= i and j <= hi:
            # range represented by a node is completely inside the given range
            return self.segtree[node]
        # range represented by a node is partially inside and partially outside the given range
        mid = i + (j - i) / 2
        left = 2 * node + 1  # left child index
        right = 2 * node + 2  # right child index
        q1 = self.queryHelper(left, i, mid, lo, hi)
        q2 = self.queryHelper(right, mid + 1, j, lo, hi)
        return q1 + q2

    # wrapper to queryHelper
    def query(self, i, j):  # Time Complexity: O(log n)
        return self.queryHelper(0, 0, self.n - 1, i, j)

    def updateHelper(self, node, i, j, idx, val):
        if i == j:
            # Leaf Node
            self.arr[i] += val
            self.segtree[node] += val
            return
        mid = i + (j - i) / 2
        left = 2 * node + 1  # left child index
        right = 2 * node + 2  # right child index

        if i <= idx and idx <= mid:
            # update in left child
            self.updateHelper(left, i, mid, idx, val)
        else:
            # update in right child
            self.updateHelper(right, mid + 1, j, idx, val)
        # update internal nodes
        self.segtree[node] = self.segtree[left] + self.segtree[right]

    # wrapper to updateHelper
    def update(self, idx, val):  # Time Complexity: O(log n)
        self.updateHelper(0, 0, self.n - 1, idx, val)


arr = [1, 2, 3, -1, 5]
tree = SegmentTree(arr)
tree.update(3, 5)  # arr[3] = 4
print(tree.query(0, 3))
