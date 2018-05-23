// Part of Cosmos by OpenGenus Foundation

import java.util.LinkedList

class Dfs(private val vertices: Int) {

    // Array of lists for Adjacency List Representation
    private val adj: List<LinkedList<Int>> = (0 until vertices).map { LinkedList<Int>() }

    // Function to add an edge into the Graph
    fun addEdge(vertex: Int, weight: Int) {
        adj[vertex].add(weight)  // Add weight to vertex's list.
    }

    // A function used by DFS
    private fun dfsUtil(vertex: Int, visited: BooleanArray) {
        // Mark the current node as visited and print it
        visited[vertex] = true
        print("$vertex ")

        // Recur for all the vertices adjacent to this vertex
        adj[vertex].filter { !visited[it] }.forEach { dfsUtil(it, visited) }
    }

    // The function to do DFS traversal. It uses recursive DfsUtil()
    fun traverse(startVertex: Int) {
        // Call the recursive helper function to print DFS traversal
        dfsUtil(startVertex, BooleanArray(vertices))
    }
}

fun main(args: Array<String>) {
    val graph = Dfs(4)

    graph.addEdge(0, 1)
    graph.addEdge(0, 2)
    graph.addEdge(1, 2)
    graph.addEdge(2, 0)
    graph.addEdge(2, 3)
    graph.addEdge(3, 3)

    println("Following is Depth First Traversal " + "(starting from vertex 2)")
    graph.traverse(2)
    println()
}