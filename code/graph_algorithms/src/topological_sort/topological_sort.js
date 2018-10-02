/**
 * Part of Cosmos by OpenGenus
 * Javascript program to find topological Sort order of a Directed Acyclic Graph.
 * Topological sorting for Directed Acyclic Graph (DAG) is a linear
 * ordering ofvertices such that for every directed edge uv,1
 * vertex u comes before v in the ordering.
 */

class Graph {
  constructor(noOfVertices) {
    this.V = noOfVertices;
    this.graph = Array(noOfVertices)
      .fill([])
      .map(a => a.slice());
    this.topSortOrder = [];
  }

  addEdge(u, v) {
    this.graph[u].push(v);
  }

  printSolution() {
    console.log("The Topological Sort Order of the given graph is: ");
    console.log(this.topSortOrder.slice(0, this.V - 1));
  }

  topologicalSortUtil(v, visited) {
    visited[v] = true;

    for (const i of this.graph[v]) {
      if (visited[i] === false) {
        this.topologicalSortUtil(i, visited);
      }
    }

    this.topSortOrder.unshift(v); // insert element at the beginning
  }

  topologicalSort() {
    let visited = Array(this.V).fill(false);

    for (let i = 0; i < this.V; i++) {
      if (visited[i] === false) {
        this.topologicalSortUtil(i, visited);
      }
    }

    this.printSolution();
  }
}

g = new Graph(6);
g.addEdge(5, 2);
g.addEdge(5, 0);
g.addEdge(4, 0);
g.addEdge(4, 1);
g.addEdge(2, 3);
g.addEdge(3, 1);

g.topologicalSort();
