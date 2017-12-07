/*
 * Part of Cosmos by OpenGenus Foundation.
 * Author : ABDOUS Kamel
 * Here we have the definition of a graph using adjacency-list representation.
 * NB : LG stands for "list graph".
 */

#ifndef GRAPH_STRUCT_H
#define GRAPH_STRUCT_H

#include <stdlib.h>

typedef size_t Node_ID;

/*
 * One directed edge.
 */
typedef struct OneEdge
{
  Node_ID nodeID; // ID of enter node.
  struct OneEdge* next;

} OneEdge;

/*
 * Directed edges of a node.
 */
typedef struct
{
  int degree; // Number of edges.
  OneEdge* l_edgesHead;

} N_Edges;

/*
 * Node of a graph with adjacency-list representation.
 */
typedef struct
{
  Node_ID ID; // ID of the node.
  N_Edges edges;

} LG_Node;

/*
 * A Graph struct using adjacency-list representation.
 * Let G = (S, A).
 */
typedef struct
{
  size_t n; // |S|
  LG_Node* nodes; // This will be allocated dynamicaly

} L_Graph;

/* ---------------------------GETTERS-----------------------------------------*/
size_t gLG_NbNodes(L_Graph* graph);
LG_Node* gLG_NodesArray(L_Graph* graph);
LG_Node* gLG_Node(L_Graph* graph, size_t ID);

Node_ID gNode_ID(LG_Node* node);
N_Edges* gNode_EdgesList(LG_Node* node);
int gNode_degree(LG_Node* node);
OneEdge* gNode_EdgesHead(LG_Node* node);

int gEdge_DestNode(OneEdge* edge);
OneEdge* gEdgesList_Next(OneEdge* edge);

void Node_incDegree(LG_Node* node);

/* ----------------------------SETTERS----------------------------------------*/
void sLG_NbNodes(L_Graph* graph, size_t n);
void sLG_NodesArray(L_Graph* graph, LG_Node* nodes);

void sNode_ID(LG_Node* node, Node_ID ID);
void sNode_degree(LG_Node* node, int degree);
void sNode_EdgesHead(LG_Node* node, OneEdge* head);

void sEdge_DestNode(OneEdge* edge, int nodeID);
void sEdgesList_Next(OneEdge* edge, OneEdge* next);

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
createLGraph(size_t n, L_Graph* graph);

/*
 * Frees the given graph.
 *
 * @graph The graph to free.
 */
void
freeLGraph(L_Graph* graph);

/*
 * Allocate a new edge.
 *
 * @node_ID The dest node.
 * @return A pointer to the new edge on success.
 *         NULL on failure.
 */
OneEdge*
createEdge(Node_ID node_ID);

/*
 * Inits edges list of a node.
 *
 * @edgesList A pointer to the node.
 * @head_ID The ID of the node that's going to be the head of the list.
 *          Give a negative value to avoid head.
 * @return 0 on success, -1 on failure.
 */
int
initEdgesList(LG_Node* node, int head_ID);

/*
 * Frees the edges list of the given node.
 *
 * @node A pointer to the node.
 */
void
freeEdgesList(LG_Node* node);

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
LGraph_addDEdge(L_Graph* graph, Node_ID src_ID, Node_ID dest_ID);

/*
 * Connect srcNode to dest_ID by a directed edge.
 *
 * @srcNode The source node.
 * @dest_ID ID of the dest node.
 *
 * @return 0 on success, -1 on failure.
 */
int
Node_addDEdge(LG_Node* srcNode, Node_ID dest_ID);

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
LGraph_addUEdge(L_Graph* graph, Node_ID id1, Node_ID id2);

/*
 * Add an undirected edge between node1 & node2.
 *
 * @node1 a node.
 * @node2 a node.
 * @return 0 on success, -1 on failure.
 */
int
Node_addUEdge(LG_Node* node1, LG_Node* node2);

#endif // GRAPH_STRUCT
