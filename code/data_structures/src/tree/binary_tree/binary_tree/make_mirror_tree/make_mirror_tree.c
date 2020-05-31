// C program to convert a binary tree 
// to its mirror 
#include<stdio.h> 
#include<stdlib.h> 
  
/* A binary tree node has data, pointer  
   to left child and a pointer to right child */
struct Node  
{ 
    int data; 
    struct Node* left; 
    struct Node* right; 
}; 
  
/* Helper function that allocates a new node with the 
   given data and NULL left and right pointers. */
struct Node* newNode(int data) 
  
{ 
  struct Node* node = (struct Node*) 
                       malloc(sizeof(struct Node)); 
  node->data = data; 
  node->left = NULL; 
  node->right = NULL; 
    
  return(node); 
} 
  
  void mirror(struct Node* node)  
{ 
  if (node==NULL)  
    return;   
  else 
  { 
    struct Node* temp; 
      
    /* do the subtrees */
    mirror(node->left); 
    mirror(node->right); 
  
    /* swap the pointers in this node */
    temp        = node->left; 
    node->left  = node->right; 
    node->right = temp; 
  } 
}  
  
/* Helper function to print Inorder traversal.*/
void inOrder(struct Node* node)  
{ 
  if (node == NULL)  
    return; 
    
  inOrder(node->left); 
  printf("%d ", node->data); 
  inOrder(node->right); 
}   
  
  
/* Driver program to test mirror() */
int main() 
{ 
  struct Node *root = newNode(1); 
  root->left        = newNode(2); 
  root->right       = newNode(3); 
  root->left->left  = newNode(4); 
  root->left->right = newNode(5);  
    
  /* Print inorder traversal of the input tree */
  printf("Inorder traversal of the constructed"
           " tree is \n"); 
  inOrder(root); 
    
  /* Convert tree to its mirror */
  mirror(root);  
    
  /* Print inorder traversal of the mirror tree */
  printf("\nInorder traversal of the mirror tree"
         " is \n");   
  inOrder(root); 
    
  return 0;   
} 
