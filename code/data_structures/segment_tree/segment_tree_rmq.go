/*
 * Segment Tree
 * Update: 1 point
 * Query: Range
 * Query Type: Range Minimum Query
 */
package main

import "fmt"

type SegmentTree struct {
	N    int
	tree []int
}

func Min(x int, y int) int {
	if x < y {
		return x
	}
	return y
}

func (stree *SegmentTree) Initialize(n int) {
	stree.N = n
	stree.tree = make([]int, 4*n)
}

func (stree *SegmentTree) build(arr []int, idx int, l int, r int) {
	if l == r {
		stree.tree[idx] = arr[l]
		return
	}

	mid := (l + r) / 2

	stree.build(arr, 2*idx+1, l, mid)
	stree.build(arr, 2*idx+2, mid+1, r)
	stree.tree[idx] = Min(stree.tree[2*idx+1], stree.tree[2*idx+2])
}

func (stree *SegmentTree) Build(arr []int) {
	stree.build(arr, 0, 0, stree.N-1)
}

func (stree *SegmentTree) update(idx int, l int, r int, pos int, val int) {
	if l == r {
		stree.tree[idx] = val
		return
	}

	mid := (l + r) / 2

	if pos <= mid {
		stree.update(2*idx+1, l, mid, pos, val)
	} else {
		stree.update(2*idx+2, mid+1, r, pos, val)
	}

	stree.tree[idx] = Min(stree.tree[2*idx+1], stree.tree[2*idx+2])
}

func (stree *SegmentTree) Update(pos int, val int) {
	stree.update(0, 0, stree.N-1, pos, val)
}

func (stree *SegmentTree) query(idx int, l int, r int, ql int, qr int) int {
	if ql <= l && r <= qr {
		return stree.tree[idx]
	}

	mid := (l + r) / 2
	minLeft := 1<<31 - 1
	minRight := 1<<31 - 1

	if ql <= mid {
		minLeft = stree.query(2*idx+1, l, mid, ql, qr)
	}

	if qr > mid {
		minRight = stree.query(2*idx+2, mid+1, r, ql, qr)
	}

	return Min(minLeft, minRight)
}

func (stree *SegmentTree) Query(ql int, qr int) int {
	return stree.query(0, 0, stree.N-1, ql, qr)
}

func main() {
	arr := []int{1, 2, 3, 4, 5}
	n := len(arr)

	var stree SegmentTree
	stree.Initialize(n)
	stree.Build(arr)

	fmt.Printf("RMQ from 2 to 4: %v\n", stree.Query(1, 3))
	fmt.Printf("RMQ from 1 to 5: %v\n", stree.Query(0, 4))

	stree.Update(2, 7)
	fmt.Println("Change to 7")
	fmt.Printf("RMQ from 3 to 5: %v\n", stree.Query(2, 4))
	fmt.Printf("RMQ from 1 to 5: %v\n", stree.Query(0, 4))
}
