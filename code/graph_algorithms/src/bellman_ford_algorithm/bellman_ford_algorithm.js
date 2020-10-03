/**
 * Part of Cosmos by OpenGenus
 * Javascript program for Bellman Ford algorithm.
 * Given a graph and a source vertex, it finds the
 * shortest path to all vertices from source vertex.
 */

class Graph {
  constructor(noOfVertices) {
    this.V = noOfVertices;
    this.graph = [];
  }

  addEdge(u, v, w) {
    this.graph.push([u, v, w]);
  }

  printSolution(dist) {
    console.log("Vertex Distance from Source");
    for (let v = 0; v < this.V; v++) {
      console.log(`${v} -> ${dist[v]}`);
    }
  }

  bellmanFord(src) {
    let dist = Array(this.V).fill(Infinity);
    dist[src] = 0;

    for (let i = 0; i < this.V - 1; i++) {
      for (const [u, v, w] of this.graph) {
        if (dist[u] != Infinity && dist[u] + w < dist[v]) {
          dist[v] = dist[u] + w;
        }
      }
    }

    // Check for negative weight cycle
    for (const [u, v, w] of this.graph) {
      if (dist[u] != Infinity && dist[u] + w < dist[v]) {
        console.log("Negative Weight Cycle is Present");
        return;
      }
    }

    this.printSolution(dist);
  }
}

g = new Graph(5);
g.addEdge(0, 1, -1);
g.addEdge(0, 2, 4);
g.addEdge(1, 2, 3);
g.addEdge(1, 3, 2);
g.addEdge(1, 4, 2);
g.addEdge(3, 2, 5);
g.addEdge(3, 1, 1);
g.addEdge(4, 3, -3);
g.bellmanFord(0);
