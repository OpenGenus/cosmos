/*
 * Part of Cosmos by OpenGenus Foundation
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
// Single node of the graph
typedef struct node
{
	int vert;
	int weight;
    struct node *next;
} node;
// Vertex of the graph
typedef struct vertex
{
	int key;
	int pos;
} vertex;
// Establish a connection of given weight
void connect(node *AdjList, int u, int v, int w)
{
    node *new = (node *)malloc(sizeof(node));
    new->vert = v;
    new->weight = w;
    node *t = AdjList + u;
	new->next = t->next;
	t->next = new;
}
// Function used to propagate heap changes to parent nodes
void heapify2(int heap[], vertex *v, int n, int i)
{
	if(i == 0 || i >= n)
		return;
	if(v[heap[i]].key < v[heap[(i - 1) / 2]].key)
	{
		// Swap elements
		int j = heap[i];
		heap[i] = heap[(i - 1) / 2];
		heap[(i - 1) / 2] = j;
		// Correct positions
		v[heap[i]].pos = i;
		v[heap[(i - 1) / 2]].pos = (i - 1) / 2;
		// Recurse
		heapify2(heap, v, n, (i - 1) / 2);
	}
}
// Main function used when creating heap
void heapify(int heap[], vertex *v, int n, int i)
{
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	int sm = i;
	if(l < n && v[heap[sm]].key > v[heap[l]].key)
		sm = l;

	if(r < n && v[heap[sm]].key > v[heap[r]].key)
		sm = r;

	if(sm != i)
	{
		// Swap elements
		int j = heap[i];
		heap[i] = heap[sm];
		heap[sm] = j;
		// Correct positions
		v[heap[i]].pos = i;
		v[heap[sm]].pos = sm;
		// Recurse
		heapify(heap, v, n, sm);
	}
}
// Remove an element from top of heap
int Hdel(int heap[], vertex *v, int *n)
{
    int k = heap[0];
    v[heap[0]].pos = -1;
    heap[0] = heap[(*n) - 1];
    v[heap[0]].pos = 0;
    (*n)--;
    heapify(heap, v, *n, 0);
    return k;
}
// Main logic for Prim's Algorithm
void Prim(node *AdjList, int m, int n)
{
    int i, tot = 0;
    vertex *v = (vertex *)malloc(sizeof(vertex) * n);
    int *heap = (int *)malloc(sizeof(int) * n);
    // Create heap
	for(i = 0; i < n; ++i)
	{
		v[i].key = INT_MAX;
		v[i].pos = i;
		heap[i] = i;
	}
    v[0].key = 0;
	while(n > 0)
	{

		int vert = Hdel(heap, v, &n);
		tot += v[vert].key;
        node *t = AdjList[vert].next;
        while(t != NULL)
		{
            if(v[t->vert].key > t->weight)
			{
				v[t->vert].key = t->weight;
				heapify2(heap, v, n, v[t->vert].pos);
			}
			t = t->next;
		}
	}
	printf("Weight of MST = %d\n", tot);
}
// Main function
int main()
{
	// m = number of edges, n = number of vertices
	int m = 8, n = 6;
	node *AdjList;
    AdjList = (node *)malloc(sizeof(node) * n);
    /*
	* Create edge connection
    * Since graph is undirected,
    * connections are formed in both
	* directions
    */
	connect(AdjList, 0, 1, 3);
	connect(AdjList, 1, 0, 3);
	connect(AdjList, 1, 4, 5);
	connect(AdjList, 4, 1, 5);
	connect(AdjList, 2, 3, 11);
	connect(AdjList, 3, 2, 11);
	connect(AdjList, 0, 4, 4);
	connect(AdjList, 4, 0, 4);
	connect(AdjList, 1, 2, 7);
	connect(AdjList, 2, 1, 7);
	connect(AdjList, 3, 5, 2);
	connect(AdjList, 5, 3, 2);
	connect(AdjList, 1, 5, 4);
	connect(AdjList, 5, 1, 4);
	connect(AdjList, 2, 4, 5);
	connect(AdjList, 4, 2, 5);
	Prim(AdjList, m, n);
	return 0;
}
