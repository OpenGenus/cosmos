/*This code will determine height of any binary search tree*/
#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
  struct Node *left;        /* left child */
  int data;            /* data to be stored */
  struct Node *right;        /* right child */
} Node;
 
Node *insert (Node * node, int a);
int treeHeight (Node * node);
int main ()
{
 
  Node *root = NULL;        /* root of binary tree */
  root = insert (root, 8);
  insert (root, 3);
  insert (root, 1);
  insert (root, 6);
  insert (root, 14);
  insert (root, 4);
  insert (root, 7);
  insert (root, 13);
 
/* calculate height*/
  printf ("The height of tree is %d\n", treeHeight (root));
  return 0;
}
 
Node * insert (Node * node, int a)
{
/* create first node */
  if (node == NULL)
    {
      Node *tmp = (Node *) malloc (sizeof (Node));
      tmp->left = NULL;
      tmp->right = NULL;
      tmp->data = a;        // initialize with zero
      return tmp;
    }
 
  if (a < node->data)        /* go to left */
    node->left = insert (node->left, a);
  else                // go to right
    node->right = insert (node->right, a);
  return node;
}
 
int treeHeight (Node * node)
{
  /* empty tree is defined as height of -1 */
  if (node == NULL)
    return -1;
  int leftHeight = 0;
  int rightHeight = 0;
  if (node != NULL)
    {
      leftHeight = treeHeight (node->left);
      rightHeight = treeHeight (node->right);
      if (leftHeight > rightHeight)
    return (leftHeight + 1);
      else
    return (rightHeight + 1);
    }
}
