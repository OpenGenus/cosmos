/* Part of Cosmos by OpenGenus Foundation */
package main

import "fmt"

type UnionFind struct {
	root []int
	size []int
}

// New returns an initialized list of Size N
func New(N int) *UnionFind {
	return new(UnionFind).init(N)
}

// Constructor initializes root and size arrays
func (uf *UnionFind) init(N int) *UnionFind {
	uf = new(UnionFind)
	uf.root = make([]int, N)
	uf.size = make([]int, N)

	for i := 0; i < N; i++ {
		uf.root[i] = i
		uf.size[i] = 1
	}

	return uf
}

// Union connects p and q by finding their roots and comparing their respective
// size arrays to keep the tree flat
func (uf *UnionFind) Union(p int, q int) {
	qRoot := uf.Root(q)
	pRoot := uf.Root(p)

	if uf.size[qRoot] < uf.size[pRoot] {
		uf.root[qRoot] = uf.root[pRoot]
		uf.size[pRoot] += uf.size[qRoot]
	} else {
		uf.root[pRoot] = uf.root[qRoot]
		uf.size[qRoot] += uf.size[pRoot]
	}
}

// Root or Find traverses each parent element while compressing the
// levels to find the root element of p
// If we attempt to access an element outside the array it returns -1
func (uf *UnionFind) Root(p int) int {
	if p > len(uf.root)-1 {
		return -1
	}

	for uf.root[p] != p {
		uf.root[p] = uf.root[uf.root[p]]
		p = uf.root[p]
	}

	return p
}

// Root or Find
func (uf *UnionFind) Find(p int) int {
	return uf.Root(p)
}

// Check if items p,q are connected
func (uf *UnionFind) Connected(p int, q int) bool {
	return uf.Root(p) == uf.Root(q)
}

func main() {
	uf := New(10)
	uf.Union(3, 4)
	uf.Union(3, 8)
	uf.Union(0, 8)
	uf.Union(1, 3)
	uf.Union(7, 9)
	uf.Union(5, 9)

	for i := 0; i < 10; i++ {
		for j := i + 1; j < 10; j++ {
			if uf.Connected(i, j) {
				fmt.Printf("%d and %d are are in the same component\n", i, j)
			}
		}
	}
}
