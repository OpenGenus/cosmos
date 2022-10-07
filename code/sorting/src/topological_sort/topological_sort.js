topologicalSortHelper(node, explored, s) {
   explored.add(node);
   
   this.edges[node].forEach(n => {
      if (!explored.has(n)) {
         this.topologicalSortHelper(n, explored, s);
      }
   });
   
   s.push(node);
}

topologicalSort() {
   let s = new Stack(this.nodes.length);
   let explored = new Set();

   this.nodes.forEach(node => {
      if (!explored.has(node)) {
         this.topologicalSortHelper(node, explored, s);
      }
   });

   while (!s.isEmpty()) {
      console.log(s.pop());
   }
}
