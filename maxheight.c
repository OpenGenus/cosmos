#include<stdio.h>
#include<stdlib.h>
 struct node 
{
    int data;
    struct node* left;
    struct node* right;
};
 
/* Compute the "maxDepth" of a tree -- the number of 
    nodes along the longest path from the root node 
    down to the farthest leaf node.*/
int maxDepth(struct node* node) 
{
   if (node==NULL) 
       return 0;
   else
   {
       /* compute the depth of each subtree */
       int lDepth = maxDepth(node->left);
       int rDepth = maxDepth(node->right);
 
       /* use the larger one */
       if (lDepth > rDepth) 
           return(lDepth+1);
       else return(rDepth+1);
   }
} 
 
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct node* newNode(int data) 
{
    struct node* node = (struct node*)
                                malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
   
    return(node);
}
   
int main()
{
    struct node *root = newNode(1);
 
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5); 
   
    printf("Hight of tree is %d", maxDepth(root));
   
    getchar();
    return 0;
}
