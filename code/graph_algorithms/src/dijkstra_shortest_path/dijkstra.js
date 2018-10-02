/**
 * Javascript program for Dijkstra's single
 * source shortest path algorithm. The program is
 * for adjacency matrix representation of the graph
 */

class Graph {
  constructor(noOfVertices) {
    this.V = noOfVertices;
    this.graph = Array(noOfVertices).fill(Array(noOfVertices).fill(0)); // Creates an nxn zero matrix
  }

  printSolution(dist) {
    console.log("Vertex tDistance from source");
    for (let v = 0; v < this.V; v++) {
      console.log(`${v}, t, ${dist[v]}`);
    }
  }

  // A utility function to find the vertex with
  // minimum distance value, from the set of vertices
  // not yet included in shortest path tree
  minDistance(dist, shortestPathSet) {
    let min = Infinity;
    let min_index;

    for (let i = 0; i < this.V; i++) {
      if (dist[i] < min && !shortestPathSet[i]) {
        min = dist[i];
        min_index = i;
      }
    }
    return min_index;
  }

  // Funtion that implements Dijkstra's single source
  // shortest path algorithm for a graph represented
  // using adjacency matrix representation
  dijkstra(src) {
    let dist = Array(this.V).fill(Infinity);
    let shortestPathSet = Array(this.V).fill(false);
    dist[src] = 0;

    for (let i = 0; i < this.V; i++) {
      // Pick the minimum distance vertex from
      // the set of vertices not yet processed.
      // u is always equal to src in first iteration
      let u = this.minDistance(dist, shortestPathSet);

      // Put the minimum distance vertex in the
      // shotest path tree
      shortestPathSet[u] = true;

      // Update dist value of the adjacent vertices
      // of the picked vertex only if the current
      // distance is greater than new distance and
      // the vertex in not in the shotest path tree
      for (let v = 0; v < this.V; v++) {
        if (
          this.graph[u][v] > 0 &&
          !shortestPathSet[v] &&
          dist[v] > dist[u] + this.graph[u][v]
        ) {
          dist[v] = dist[u] + this.graph[u][v];
        }
      }
    }

    this.printSolution(dist);
  }
}

g = new Graph(9);

g.graph = [
  [0, 4, 0, 0, 0, 0, 0, 8, 0],
  [4, 0, 8, 0, 0, 0, 0, 11, 0],
  [0, 8, 0, 7, 0, 4, 0, 0, 2],
  [0, 0, 7, 0, 9, 14, 0, 0, 0],
  [0, 0, 0, 9, 0, 10, 0, 0, 0],
  [0, 0, 4, 14, 10, 0, 2, 0, 0],
  [0, 0, 0, 0, 0, 2, 0, 1, 6],
  [8, 11, 0, 0, 0, 0, 1, 0, 7],
  [0, 0, 2, 0, 0, 0, 6, 7, 0]
];

g.dijkstra(0);
