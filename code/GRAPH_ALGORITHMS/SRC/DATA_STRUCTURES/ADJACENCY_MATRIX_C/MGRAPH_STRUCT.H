/*
 * Part of Cosmos by OpenGenus Foundation.
 * Author : ABDOUS Kamel
 * Here we have the definition of a graph using adjacency-matrix representation.
 * NB : MG stands for "matrix graph".
 */

#ifndef MGRAPH_STRUCT_H
#define MGRAPH_STRUCT_H

#include <stdlib.h>

/* Change this to change weighting type, if there is one */
typedef int EdgeType;

/* Don't change this, use Node_ID instead of int to refer to nodes */
typedef int Node_ID;

/*
 * A Graph struct using adjacency-matrix representation.
 * Let G = (S, A).
 */
typedef struct
{
  int n; /* |S| */
  EdgeType** matrix; /* This will be allocated dynamicaly */

} M_Graph;

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
createMGraph(size_t n, M_Graph* graph);

/*
 * Frees the given graph.
 *
 * @graph The graph to free.
 */
void
freeMGraph(M_Graph* graph);

/*
 * Sets M[i][j] to val.
 */
void
MG_set(M_Graph* graph, Node_ID i, Node_ID j, EdgeType val);

/*
 * Returns M[i][j];
 */
EdgeType
MG_get(M_Graph* graph, Node_ID i, Node_ID j);

/*
 * Returns graph->n;
 */
size_t
MG_size(M_Graph* graph);

#endif // MGRAPH_STRUCT
