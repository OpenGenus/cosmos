/*
 * Part of Cosmos by OpenGenus Foundation.
 * Author : ABDOUS Kamel
 * How to use matrix-representation graphs.
 */

#include "mgraph_struct.h"
#include <stdio.h>

#define NB_NODES 5

int
main()
{
  M_Graph g;
  createMGraph(NB_NODES, &g);

  int i, j;
  for (i = 0; i < NB_NODES; ++i) {
    for (j = 0; j < NB_NODES; ++j) {
      printf("%d ", MG_get(&g, i, j));
    }

    printf("\n");
  }

  MG_set(&g, 0, 0, 1);
  MG_set(&g, 1, 2, 1);
  MG_set(&g, 2, 3, 1);

  printf("\n");

  for (i = 0; i < NB_NODES; ++i) {
    for (j = 0; j < NB_NODES; ++j) {
      printf("%d ", MG_get(&g, i, j));
    }

    printf("\n");
  }

  freeMGraph(&g);
  return (0);
}
