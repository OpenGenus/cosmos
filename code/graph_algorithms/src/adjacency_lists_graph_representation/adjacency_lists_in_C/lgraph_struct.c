/*
 * Part of Cosmos by OpenGenus Foundation.
 * Author : ABDOUS Kamel
 */

#include "lgraph_struct.h"

/* ---------------------------GETTERS-----------------------------------------*/
inline size_t gLG_NbNodes(L_Graph* graph) { return (graph->n); }
inline LG_Node* gLG_NodesArray(L_Graph* graph) { return (graph->nodes); }
inline LG_Node* gLG_Node(L_Graph* graph, Node_ID ID) { return (&graph->nodes[ID]); }

inline Node_ID gNode_ID(LG_Node* node) { return (node->ID); }
inline N_Edges* gNode_EdgesList(LG_Node* node) { return (&node->edges); }
inline int gNode_degree(LG_Node* node) { return (node->edges.degree); }
inline OneEdge* gNode_EdgesHead(LG_Node* node) { return (node->edges.l_edgesHead); }

inline int gEdge_DestNode(OneEdge* edge) { return (edge->nodeID); }
inline OneEdge* gEdgesList_Next(OneEdge* edge) { return (edge->next); }

inline void Node_incDegree(LG_Node* node) { node->edges.degree++; }

/* ----------------------------SETTERS----------------------------------------*/
inline void sLG_NbNodes(L_Graph* graph, size_t n) { graph->n = n; }
inline void sLG_NodesArray(L_Graph* graph, LG_Node* nodes) { graph->nodes = nodes; }

inline void sNode_ID(LG_Node* node, Node_ID ID) { node->ID = ID; }
inline void sNode_degree(LG_Node* node, int degree) { node->edges.degree = degree; }
inline void sNode_EdgesHead(LG_Node* node, OneEdge* head) { node->edges.l_edgesHead = head; }

inline void sEdge_DestNode(OneEdge* edge, int nodeID) { edge->nodeID = nodeID; }
inline void sEdgesList_Next(OneEdge* edge, OneEdge* next) { edge->next = next; }

/* -------------------------ALLOCATION FUNCTIONS------------------------------*/

/*
 * Creates a new graph with adjacency-list representation.
 *
 * @n Number of nodes.
 * @graph The struct that will hold the graph.
 *
 * @return 0 on success.
 *         -1 when malloc error.
 */
int
createLGraph(size_t n, L_Graph* graph)
{
  LG_Node* nodes = malloc(sizeof(*graph->nodes) * n);
  if (nodes == NULL)
    return (-1);

  sLG_NbNodes(graph, n);
  sLG_NodesArray(graph, nodes);

  Node_ID i;
  for (i = 0; i < n; ++i) {
    sNode_ID(&nodes[i], i);
    initEdgesList(&nodes[i], -1);
  }

  return (0);
}

/*
 * Frees the given graph.
 *
 * @graph The graph to free.
 */
void
freeLGraph(L_Graph* graph)
{
  Node_ID i;

  LG_Node* nodes = gLG_NodesArray(graph);

  for (i = 0; i < gLG_NbNodes(graph); ++i)
    freeEdgesList(&nodes[i]);

  free(nodes);
  sLG_NbNodes(graph, 0);
}

/*
 * Allocate a new edge.
 *
 * @node_ID The dest node.
 * @return A pointer to the new edge on success.
 *         NULL on failure.
 */
OneEdge*
createEdge(Node_ID node_ID)
{
  OneEdge* ret = malloc(sizeof(*ret));

  if (ret == NULL)
    return NULL;

  sEdge_DestNode(ret, node_ID);
  sEdgesList_Next(ret, NULL);

  return (ret);
}

/*
 * Inits edges list of a node.
 *
 * @edgesList A pointer to the node.
 * @head_ID The ID of the node that's going to be the head of the list.
 *          Give a negative value to avoid head.
 * @return 0 on success, -1 on failure.
 */
int
initEdgesList(LG_Node* node, int head_ID)
{
  if (head_ID < 0) {
    sNode_degree(node, 0);
    sNode_EdgesHead(node, NULL);
  }

  else {
    sNode_degree(node, 1);

    OneEdge* head = createEdge(head_ID);
    if(head == NULL)
      return (-1);

    sNode_EdgesHead(node, head);
  }

  return (0);
}

/*
 * Frees the edges list of the given node.
 *
 * @node A pointer to the node.
 */
void
freeEdgesList(LG_Node* node)
{
  OneEdge *p = gNode_EdgesHead(node),
          *next;

  while (p != NULL) {
    next = gEdgesList_Next(p);

    free(p);
    p = next;
  }
}

/* --------------------------ADDING EDGES-------------------------------------*/

/*
 * Add a new directed edge to the graph, connecting src to dest.
 *
 * @graph The graph.
 * @src_ID ID of the source node.
 * @dest_ID ID of the dest node.
 *
 * @return 0 on success, -1 on failure.
 */
int
LGraph_addDEdge(L_Graph* graph, Node_ID src_ID, Node_ID dest_ID)
{
  if (src_ID >= gLG_NbNodes(graph) || dest_ID >= gLG_NbNodes(graph))
    return (-1);

  return Node_addDEdge(gLG_Node(graph, src_ID), dest_ID);
}

/*
 * Connect srcNode to dest_ID by a directed edge.
 *
 * @srcNode The source node.
 * @dest_ID ID of the dest node.
 *
 * @return 0 on success, -1 on failure.
 */
int
Node_addDEdge(LG_Node* srcNode, Node_ID dest_ID)
{
  OneEdge* head = gNode_EdgesHead(srcNode);

  if (head == NULL)
    return (initEdgesList(srcNode, dest_ID));

  OneEdge* newHead = createEdge(dest_ID);
  if (newHead == NULL)
    return (-1);

  sEdgesList_Next(newHead, head);
  sNode_EdgesHead(srcNode, newHead);
  Node_incDegree(srcNode);
  
  return (0);
}

/*
 * Add a new undirected edge to the graph, connecting id1 & id2.
 *
 * @graph The graph.
 * @id1 ID of a node.
 * @id2 ID of a node.
 *
 * @return 0 on success, -1 on failure.
 */
int
LGraph_addUEdge(L_Graph* graph, Node_ID id1, Node_ID id2)
{
  if (LGraph_addDEdge(graph, id1, id2) == -1)
    return (-1);

  /* Loop */
  if (id1 == id2)
    return (0);

  if (LGraph_addDEdge(graph, id2, id1) == -1)
    return (-1);

  return (0);
}

/*
 * Add an undirected edge between node1 & node2.
 *
 * @node1 a node.
 * @node2 a node.
 * @return 0 on success, -1 on failure.
 */
int
Node_addUEdge(LG_Node* node1, LG_Node* node2)
{
  if (Node_addDEdge(node1, gNode_ID(node2)) == -1)
    return (-1);

  /* Loop */
  if (node1 == node2)
    return (0);

  if (Node_addDEdge(node2, gNode_ID(node1)) == -1)
    return (-1);

  return (0);
}
