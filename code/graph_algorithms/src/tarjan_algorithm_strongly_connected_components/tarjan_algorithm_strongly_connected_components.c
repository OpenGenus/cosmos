/*
 * Part of Cosmos by OpenGenus Foundation.
 * Author : ABDOUS Kamel
 * Tarjan algorithm.
 *
 * You will need the data-structure located in
 * https://github.com/OpenGenus/cosmos/tree/master/code/graph_algorithms/src/adjacency_lists_graph_representation/adjacency_lists_in_C
 * to use this algorithm.
 */

#include "lgraph_struct.h"
#include "lgraph_stack.h"
#include <stdio.h>

/* Deep course colors */
typedef enum
{
  DC_WHITE = 0, /* The exploration of the node didn't start yet */
  DC_GREY, /* The node is in exploration */
  DC_BLACK /* The exploration of the node has ended */

} DC_Color;

/* The Tarjan algorithm needs those variables to mark nodes during deep course */
static LG_Stack lg_stackTarjan;
static Node_ID *nodesNums, *nodesAccessNums, currentNum;

/*
 * Tarjan algorithm deep course subroutine.
 * Deep course over node_ID & finds all the strongly connected components that can
 * be found.
 *
 * @graph The directed graph.
 * @node_ID ID of the origin node.
 * @dc_colors Cur graph coloration.
 * @connectedComps Strongly connected components array.
 * @curComp Current strongly connected component ID.
 */
static void
tarjanAlgoDC(L_Graph* graph, Node_ID node_ID, DC_Color* dc_colors, size_t* sConnectedComps, size_t* curComp)
{
  dc_colors[node_ID] = DC_GREY;
  LG_StackPush(&lg_stackTarjan, node_ID);

  nodesNums[node_ID] = currentNum;
  nodesAccessNums[node_ID] = currentNum;
  ++currentNum;

  OneEdge* edge = gNode_EdgesHead(gLG_Node(graph, node_ID));

  while (edge != NULL) {
    switch (dc_colors[gEdge_DestNode(edge)]) {
    // A new node that hasn't yet a SCC
    case DC_WHITE:
      tarjanAlgoDC(graph, gEdge_DestNode(edge), dc_colors, sConnectedComps, curComp);

      if (nodesAccessNums[gEdge_DestNode(edge)] < nodesAccessNums[node_ID])
        nodesAccessNums[node_ID] = nodesAccessNums[gEdge_DestNode(edge)];
      break;

    // That node has already a SCC, we will see if we can merge.
    case DC_GREY:
      if (nodesAccessNums[gEdge_DestNode(edge)] < nodesAccessNums[node_ID])
        nodesAccessNums[node_ID] = nodesAccessNums[gEdge_DestNode(edge)];
      break;

    default:
      break;
    }

    edge = gEdgesList_Next(edge);
  }

  // Here, node_ID is the root of the strongly connected component
  if (nodesNums[node_ID] == nodesAccessNums[node_ID]) {
    Node_ID popNode;

    do {
      popNode = LG_StackPop(&lg_stackTarjan);
      sConnectedComps[popNode] = *curComp;

    } while(popNode != node_ID);

    ++(*curComp);
  }

  dc_colors[node_ID] = DC_BLACK;
}

/*
 * For each node of the graph, stores in sConnectedComps the ID of its strongly connected
 * component.
 * This algorithm is the Tarjan Algorithm & executes in theta(S + A);
 *
 * @graph The directed graph.
 * @sConnectedComps An array of at least |S| elements.
 * @return Number of strongly connected components.
 */
int
tarjanAlgoConnectivity(L_Graph* graph, size_t* sConnectedComps)
{
  DC_Color* dc_colors = calloc(gLG_NbNodes(graph), sizeof(*dc_colors));

  Node_ID i;
  size_t curComp = 0;

  createLG_Stack(gLG_NbNodes(graph), &lg_stackTarjan);
  nodesNums = malloc(sizeof(*nodesNums) * gLG_NbNodes(graph));
  nodesAccessNums = malloc(sizeof(*nodesAccessNums) * gLG_NbNodes(graph));
  currentNum = 0;

  for (i = 0; i < gLG_NbNodes(graph); ++i) {
    if (dc_colors[i] == DC_WHITE)
      tarjanAlgoDC(graph, i, dc_colors, sConnectedComps, &curComp);
  }

  free(nodesAccessNums);
  free(nodesNums);
  freeLG_Stack(&lg_stackTarjan);
  free(dc_colors);

  return (curComp);
}

#define NB_NODES 5

int
main()
{
  L_Graph g;
  createLGraph(NB_NODES, &g);

  LGraph_addDEdge(&g, 1, 3);
  LGraph_addDEdge(&g, 2, 1);
  LGraph_addDEdge(&g, 3, 4);
  LGraph_addDEdge(&g, 4, 0);
  LGraph_addDEdge(&g, 0, 3);
  LGraph_addDEdge(&g, 1, 0);

  size_t s[NB_NODES];

  printf("%d\n\n", tarjanAlgoConnectivity(&g, s));

  Node_ID i;
  for (i = 0; i < NB_NODES; ++i)
    printf("%d\n", s[i]);

  freeLGraph(&g);

  return (0);
}
