// Part of Cosmos by OpenGenus Foundation

package main

import "fmt"

type graph map[int][]int

func reverseSlice(s []int) []int {
	for i, j := 0, len(s)-1; i < j; i, j = i+1, j-1 {
		s[i], s[j] = s[j], s[i]
	}
	return s
}

func reverseGraph(g graph) graph {
	rev := make(graph)
	for n, adj := range g {
		for _, m := range adj {
			rev[m] = append(rev[m], n)
		}
	}
	return rev
}

func topoSort(g graph) []int {
	var sorted []int
	var visited = make(map[int]bool)

	var visit func(int)
	visit = func(n int) {
		if visited[n] {
			return
		}
		visited[n] = true
		for _, m := range g[n] {
			visit(m)
		}
		sorted = append(sorted, n)
	}

	for i := range g {
		visit(i)
	}

	return reverseSlice(sorted)
}

func longestPath(g graph) []int {
	s := topoSort(g)
	rev := reverseGraph(g)

	dist := make(map[int]int)
	from := make(map[int]int)
	for n := range g {
		dist[n] = -1
		from[n] = -1
	}
	maxNode := s[0] // last node on the longest path
	for _, n := range s {
		for _, m := range rev[n] {
			if dist[n] < dist[m]+1 {
				from[n] = m
				dist[n] = dist[m] + 1
			}
		}
		if dist[n] > dist[maxNode] {
			maxNode = n
		}
	}

	var path []int
	for n := maxNode; n != -1; n = from[n] {
		path = append(path, n)
	}

	return reverseSlice(path)
}

func main() {
	g := graph{
		0: {1, 2},
		1: {2, 3},
		2: {4, 5, 3},
		3: {4, 5},
		4: {5},
		5: {},
	}
	fmt.Println(longestPath(g))
}
