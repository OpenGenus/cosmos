/*
 * Part of Cosmos by OpenGenus Foundation.
 * Author : ABDOUS Kamel
 * 
 * You will need the data-structure located in 
 * https://github.com/OpenGenus/cosmos/tree/master/code/graph_algorithms/src/adjacency_lists_graph_representation/adjacency_lists_in_C
 * to use this algorithm.
 */

#include "lgraph_struct.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

/* Deep course colors */
typedef enum
{
  DC_WHITE, /* The exploration of the node didn't start yet */
  DC_GREY, /* The node is in exploration */
  DC_BLACK /* The exploration of the node has ended */

} DC_Color;

/*
 * Deep course subroutine of cycle directed detection.
 *
 * @graph The graph on which we work.
 * @node_ID ID of the node on which we will execute the deep course.
 * @dc_colors Current coloration of the nodes.
 * @return 1 if we find a rear arc. 0 otherwise.
 */
static int
rearArcsDC(L_Graph* graph, Node_ID node_ID, DC_Color* dc_colors)
{
  dc_colors[node_ID] = DC_GREY;

  OneEdge* edge = gNode_EdgesHead(gLG_Node(graph, node_ID));

  while (edge != NULL) {
    switch (dc_colors[gEdge_DestNode(edge)]) {
    case DC_WHITE:
      if (rearArcsDC(graph, gEdge_DestNode(edge), dc_colors))
        return (1);
      break;

    /* Rear arc found ! */
    case DC_GREY:
      return (1);
      break;

    default:
      break;
    }
    
    edge = gEdgesList_Next(edge);
  }

  dc_colors[node_ID] = DC_BLACK;
  return(0);
}

/*
 * Let G = (S, A).
 * Detects in O(S + A) if the graph contains a directed cycle.
 *
 * @graph A graph represented by adjacency lists.
 * @return 1 if a there's a directed cycle. 0 otherwise.
 */
int
cycleDirectedDetection(L_Graph* graph)
{
  DC_Color* dc_colors = calloc(gLG_NbNodes(graph), sizeof(*dc_colors));

  Node_ID i;
  for (i = 0; i < gLG_NbNodes(graph); ++i) {
    /* A sufficient condition for detecting a directed cycle is that a deep course
       finds a rear arc. */
    if (dc_colors[i] == DC_WHITE && rearArcsDC(graph, i, dc_colors)) {
      free(dc_colors);
      return (1);
    }
  }

  /* The mentioned condition is also necessary */
  free(dc_colors);
  return (0);
}

int
main()
{
  L_Graph g;
  createLGraph(5, &g);

  LGraph_addDEdge(&g, 1, 3);
  LGraph_addDEdge(&g, 2, 1);
  LGraph_addDEdge(&g, 3, 4);
  LGraph_addDEdge(&g, 4, 0);
  LGraph_addDEdge(&g, 0, 3);
  LGraph_addDEdge(&g, 1, 0);

  printf("%d\n", cycleDirectedDetection(&g));

  freeLGraph(&g);
  
  return (0);
}
