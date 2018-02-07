/*
 * Part of Cosmos by OpenGenus Foundation.
 * Author : ABDOUS Kamel
 *
 * Connected Components on undirected graph based of depth-first search.
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
 * getConnectedComponents deep course subroutine.
 * Finds the connected component for whom node_ID is the origin node.
 *
 * @graph The undirected graph.
 * @node_ID ID of the origin node.
 * @dc_colors Cur graph coloration.
 * @connectedComps Connected components array.
 * @curComp ID of the connected component that node_ID defines.
 */
static void
connectedComponentsDC(L_Graph* graph, Node_ID node_ID, DC_Color* dc_colors, size_t* connectedComps, size_t curComp)
{
  dc_colors[node_ID] = DC_GREY;
  connectedComps[node_ID] = curComp;

  OneEdge* edge = gNode_EdgesHead(gLG_Node(graph, node_ID));

  while (edge != NULL) {
    if (dc_colors[gEdge_DestNode(edge)] == DC_WHITE)
      connectedComponentsDC(graph, gEdge_DestNode(edge), dc_colors, connectedComps, curComp);

    edge = gEdgesList_Next(edge);
  }
}


/*
 * For each node of the graph, stores in connectedComps the ID of its connected
 * component.
 * This algorithm executes in thêta(S + A);
 *
 * @graph The undirected graph.
 * @connectedComps An array of at least |S| elements.
 * @return Number of connected components.
 */
int
getConnectedComponents(L_Graph* graph, size_t* connectedComps)
{
  DC_Color* dc_colors = calloc(gLG_NbNodes(graph), sizeof(*dc_colors));

  Node_ID i;
  size_t curComp = 0;

  for (i = 0; i < gLG_NbNodes(graph); ++i) {
    if (dc_colors[i] == DC_WHITE ) {
      connectedComponentsDC(graph, i, dc_colors, connectedComps, curComp);
      ++curComp;
    }
  }

  free(dc_colors);
  return (curComp);
}

#define S 5

int 
main()
{
  L_Graph g;
  createLGraph(S, &g);

  LGraph_addUEdge(&g, 0, 1);
  LGraph_addUEdge(&g, 1, 2);
  LGraph_addUEdge(&g, 0, 2);
  LGraph_addUEdge(&g, 3, 4);

  size_t s[S];

  printf("%d\n\n", getConnectedComponents(&g, s));

  Node_ID i;
  for (i = 0; i < S; ++i)
    printf("%d\n", s[i]);

  freeLGraph(&g);
  return (0);
}
