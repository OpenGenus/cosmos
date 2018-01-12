/*
 * Part of Cosmos by OpenGenus Foundation.
 * Author : ABDOUS Kamel
 * Topological sort based on depth-first search.
 *
 * You will need the data-structure located in 
 * https://github.com/OpenGenus/cosmos/tree/master/code/graph_algorithms/src/adjacency_lists_graph_representation/adjacency_lists_in_C
 * to use this algorithm.
 */

#include <stdio.h>
#include "lgraph_struct.h"

/* Deep course colors */
typedef enum
{
  DC_WHITE, /* The exploration of the node didn't start yet */
  DC_GREY, /* The node is in exploration */
  DC_BLACK /* The exploration of the node has ended */

} DC_Color;

/*
 * Deep course subroutine of topological sort.
 * Sorts nodes that are accessible via node_ID.
 *
 * @graph The graph.
 * @node_ID Node to loop over.
 * @dc_colors Cur coloration of the graph.
 * @sortedNodes The array that stores sorted nodes.
 * @sortedCurPos Pointer to the current position in sortedNodes.
 * @return -1 if can't get a topological sort, 0 otherwise.
 */
static int
topoSortDC(L_Graph* graph, Node_ID node_ID, DC_Color* dc_colors, Node_ID* sortedNodes, int* sortedCurPos)
{
  dc_colors[node_ID] = DC_GREY;

  OneEdge* edge = gNode_EdgesHead(gLG_Node(graph, node_ID));

  while (edge != NULL) {
    switch (dc_colors[gEdge_DestNode(edge)]) {
    case DC_WHITE:
      if(topoSortDC(graph, gEdge_DestNode(edge), dc_colors, sortedNodes, sortedCurPos) == -1)
        return (-1); /* Rear arc */
      break;

    /* Rear arc found, the graph has a directed cycle, can't get a topologial sort */
    case DC_GREY:
      return (-1);
      break;

    default:
      break;
    }

    edge = gEdgesList_Next(edge);
  }

  dc_colors[node_ID] = DC_BLACK;
  sortedNodes[*sortedCurPos] = node_ID;
  --(*sortedCurPos);

  return (0);
}

/*
 * Let G = (S, A)
 * Executes a topological sort on G in thêta(S + A).
 * The result is stored in sortedNodes. It must be an array that has at least
 * |S| elements.
 *
 * @graph The graph. It musn't have a directed cycle.
 * @sortedNodes An array of at least |S| elements. It will store the result.
 * @return 0 on success, -1 if the graph has a directed cycle.
 */
int
topologicalSort(L_Graph* graph, Node_ID* sortedNodes)
{
  DC_Color* dc_colors = calloc(gLG_NbNodes(graph), sizeof(*dc_colors));

  Node_ID i;
  int sortedCurPos = gLG_NbNodes(graph) - 1;

  for (i = 0; i < gLG_NbNodes(graph); ++i) {
    if (dc_colors[i] == DC_WHITE && topoSortDC(graph, i, dc_colors, sortedNodes, &sortedCurPos) == -1) {
      free(dc_colors);
      return (-1);
    }
  }

  free(dc_colors);
  return (0);
}

#define S 5

int 
main()
{
  L_Graph g;
  createLGraph(S, &g);

  LGraph_addDEdge(&g, 0, 1);
  LGraph_addDEdge(&g, 1, 2);
  LGraph_addDEdge(&g, 3, 4);
  LGraph_addDEdge(&g, 4, 2);

  size_t s[S];

  printf("%d\n\n", topologicalSort(&g, s));

  int i;
  for (i = 0; i < S; ++i)
    printf("%d\n", s[i]);

  freeLGraph(&g);
  return (0);
}
