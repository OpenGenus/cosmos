package main

import "fmt"

// Part of Cosmos by OpenGenus Foundation

/**************************************
 * Structures
 **************************************/

// Define set structure (golang has no built-in set)
// Usage:
//
//    s := make(set)                // Create empty set
//    s := set{7: true, 21: true}   // Create set with values
//    _, exist := s[7]              // Check if 7 is in the set
//    s[2] = true                   // Add 2 to the set
//    delete(s, 7)                  // Remove 7 from the set
type set map[int]bool

// Define Graph structure
type Graph struct {
  adjList map[int]set
}

// Create a graph and initialize its adjacency list,
// and return a pointer to it.
func createGraph() *Graph {
  var g = Graph{}
  g.adjList = make(map[int]set)
  return &g
}

// Add an edge between the two given nodes.
// If a node does not exist in the graph yet, add it.
func (g *Graph) addEdge(node1 int, node2 int) {
  // Check if node1 is already in the graph
  if g.adjList[node1] == nil {
    // Nope. Add it
    g.adjList[node1] = make(set)
  }
  g.adjList[node1][node2] = true

  // Check if node2 is already in the graph
  if g.adjList[node2] == nil {
    // Nope. Add it
    g.adjList[node2] = make(set)
  }
  g.adjList[node2][node1] = true
}

/**************************************
 * Algorithm
 **************************************/

// Perform a depth first search from the given node
// and apply the given function to each node.
func dfs(g *Graph, current int, visited set, visitFunction func(int)) {
  if _, seen := visited[current]; seen {
    return
  }

  visited[current] = true
  visitFunction(current)

  for neighbour := range g.adjList[current] {
    dfs(g, neighbour, visited, visitFunction)
  }
}


/**************************************
 * Tests
 **************************************/

// Test the dfs algorithm on this graph:
//
//      1
//     / \
//    /   \
//   2     5
//  / \   / \
// 3 - 4 6   7
//
// Should output: 1 2 3 4 5 6 7, OR SIMILAR (example: 1 2 4 3 5 7 6)
//
// NOTE: the output order may vary because we used a for range loop,
//       and according to the spec (https://golang.org/ref/spec#For_statements):
//       "The iteration order over maps is not specified and is not guaranteed
//       to be the same from one iteration to the next."
//
//          => Output may vary but will always be right from algorithmic POV.
func main() {
  graph := createGraph()
  graph.addEdge(1, 2)
  graph.addEdge(2, 3)
  graph.addEdge(2, 4)
  graph.addEdge(3, 4)
  graph.addEdge(1, 5)
  graph.addEdge(5, 6)
  graph.addEdge(5, 7)

  visited := make(set)

  dfs(graph, 1, visited, func(node int) {
    fmt.Print(node, " ")
  })
}