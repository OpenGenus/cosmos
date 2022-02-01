var graph = [];
for (i = 0; i < 10; ++i) {
  graph.push([]);
  for (j = 0; j < 10; ++j)
    graph[i].push(i == j ? 0 : 9999999);
}
 
for (i = 1; i < 10; ++i) {
  graph[0][i] = graph[i][0] = parseInt(Math.random() * 9 + 1);
}
 
for (k = 0; k < 10; ++k) {
  for (i = 0; i < 10; ++i) {
    for (j = 0; j < 10; ++j) {
      if (graph[i][j] > graph[i][k] + graph[k][j])
        graph[i][j] = graph[i][k] + graph[k][j]
    }
  }
}
 
console.log(graph);