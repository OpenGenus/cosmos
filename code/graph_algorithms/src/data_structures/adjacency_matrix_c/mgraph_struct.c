/*
 * Part of Cosmos by OpenGenus Foundation.
 * Author : ABDOUS Kamel
 * Here we have the definition of a graph using adjacency-matrix representation.
 * NB : MG stands for "matrix graph".
 */

#include "mgraph_struct.h"

/*
 * Creates a new graph with matrix-list representation.
 *
 * @n Number of nodes.
 * @graph The struct that will hold the graph.
 *
 * @return 0 on success.
 *         -1 when malloc error.
 */
int
createMGraph(size_t n, M_Graph* graph)
{
  graph->n = n;
  graph->matrix = malloc(n * sizeof(*graph->matrix));

  if (graph->matrix == NULL)
    return (-1);

  int i;
  for (i = 0; i < n; ++i) {
    graph->matrix[i] = calloc(n, sizeof(**graph->matrix));

    if (graph->matrix[i] == NULL) {
      graph->n = i; /* This indicates to the free routine the number of rows to free */
      freeMGraph(graph);
      
      return (-1);
    }
  }

  return (0);
}

/*
 * Frees the given graph.
 *
 * @graph The graph to free.
 */
void
freeMGraph(M_Graph* graph)
{
  int i;
  for (i = 0; i < graph->n; ++i)
    free(graph->matrix[i]);

  free(graph->matrix);
  graph->n = 0;
}

/*
 * Sets M[i][j] to val.
 */
inline void
MG_set(M_Graph* graph, Node_ID i, Node_ID j, EdgeType val)
{
  graph->matrix[i][j] = val;
}

/*
 * Returns M[i][j];
 */
inline EdgeType
MG_get(M_Graph* graph, Node_ID i, Node_ID j)
{
  return (graph->matrix[i][j]);
}

/*
 * Returns graph->n;
 */
inline size_t
MG_size(M_Graph* graph)
{
  return (graph->n);
}
