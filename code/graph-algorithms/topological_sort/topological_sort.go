package main

import "fmt"

type graph map[int][]int

const (
	white = iota
	grey
	black
)

func reverse(s []int) []int {
	for i, j := 0, len(s)-1; i < j; i, j = i+1, j-1 {
		s[i], s[j] = s[j], s[i]
	}
	return s
}

func topoSort(g graph) []int {
	var sorted []int
	var marks = make(map[int]int)

	var visit func(int) bool
	visit = func(n int) (hasCycle bool) {
		if marks[n] == black {
			return false
		}
		if marks[n] == grey {
			return true
		}
		marks[n] = grey
		for _, m := range g[n] {
			if visit(m) {
				return true
			}
		}
		marks[n] = black
		sorted = append(sorted, n)
		return false
	}

	for i := range g {
		if visit(i) {
			return nil
		}
	}

	return reverse(sorted)
}

func main() {
	// consider following graph
	//
	// 1----->2----->5
	// |     ^^
	// |    / |
	// |   /  |
	// |  /   |
	// v /    |
	// 4----->3
	//
	// one of the solution would be
	//
	//   /-------------v
	//  1 -> 4 -> 3 -> 2 -> 5
	//        \--------^

	g := graph{
		1: {2, 4},
		2: {5},
		3: {2},
		4: {2, 3},
		5: {},
	}
	fmt.Println(topoSort(g))

	// sorting of a graph with cycle is not possible
	//
	// 1--->2
	//     ^|
	//    / |
	//   /  |
	//  /   v
	// 3<---4

	cycle := graph{
		1: {2},
		2: {4},
		3: {2},
		4: {3},
	}
	fmt.Println(topoSort(cycle))
}
