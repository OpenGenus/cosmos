/* Part of Cosmos by OpenGenus Foundation */

// What this algorithm basically does is assumes all nodes are at an infinite distance from the source.
// Then it starts taking the edges in consideration and keeps track of distances of nodes from the source 
// updating the same if it finds a lower cost path along the way.

djikstraAlgorithm(startNode) {
   let distances = {};

   // Stores the reference to previous nodes
   let prev = {};
   let pq = new PriorityQueue(this.nodes.length * this.nodes.length);

   // Set distances to all nodes to be infinite except startNode
   distances[startNode] = 0;
   pq.enqueue(startNode, 0);
   this.nodes.forEach(node => {
      if (node !== startNode) distances[node] = Infinity;
      prev[node] = null;
   });

   while (!pq.isEmpty()) {
      let minNode = pq.dequeue();
      let currNode = minNode.data;
      let weight = minNode.priority;
      this.edges[currNode].forEach(neighbor => {
         let alt = distances[currNode] + neighbor.weight;
         if (alt < distances[neighbor.node]) {
            distances[neighbor.node] = alt;
            prev[neighbor.node] = currNode;
            pq.enqueue(neighbor.node, distances[neighbor.node]);
         }
      });
   }
   return distances;
}



// Example

// let g = new Graph();
// g.addNode("A");
// g.addNode("B");
// g.addNode("C");
// g.addNode("D");
// g.addNode("E");
// g.addNode("F");
// g.addNode("G");

// g.addDirectedEdge("A", "C", 100);
// g.addDirectedEdge("A", "B", 3);
// g.addDirectedEdge("A", "D", 4);
// g.addDirectedEdge("D", "C", 3);
// g.addDirectedEdge("D", "E", 8);
// g.addDirectedEdge("E", "F", 10);
// g.addDirectedEdge("B", "G", 9);
// g.addDirectedEdge("E", "G", 50);

// console.log(g.djikstraAlgorithm("A"));


/* 
    OUTPUT:
    { A: 0, B: 3, C: 7, D: 4, E: 12, F: 22, G: 12 }
*/
