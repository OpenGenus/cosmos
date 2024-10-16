/*
 * Part of Cosmos by OpenGenus Foundation.
 * Author : ABDOUS Kamel
 */

#include <stdio.h>
#include "lgraph_struct.h"

int 
main()
{
  L_Graph g;
  createLGraph(5, &g);

  LGraph_addDEdge(&g, 1, 3);
  LGraph_addUEdge(&g, 2, 1);
  LGraph_addUEdge(&g, 3, 3);
  LGraph_addDEdge(&g, 1, 0);

  Node_ID i;
  LG_Node* n;
  OneEdge* p;

  for (i = 0; i < gLG_NbNodes(&g); ++i) {
    n = gLG_Node(&g, i);
    p = gNode_EdgesHead(n);

    printf("%d\n", gNode_ID(n));

    // Looping over the adjacency-list
    while (p != NULL) {
      printf("%d\n", gEdge_DestNode(p));
      p = gEdgesList_Next(p);
    }

    printf("\n");
  }

  freeLGraph(&g);
  return (0);
}
