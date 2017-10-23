
/* A binary tree node has data, pointer to left child
   and a pointer to right child  
   
struct Node {
    int data;
    Node* left, * right;
}; 

*/



/* Should return true if tree represented by root is BST. 
   For example, return  value should be 1 for following tree.
         20
     /      \ 
   10       30
  and return value should be 0 for following tree.
         10
     /      \ 
   20       30 */
 
 
   
Node *findmax(Node *root)
{
    if(!root) 
        return NULL;
    
    while(root->right) 
        root=root->right;
        
    return root;
}

Node *findmin(Node *root)
{
    if(!root) 
        return NULL;
        
    while(root->left) 
        root=root->left;
        
    return root;
}

bool isBST(Node* root) 
{
    if(!root) 
        return 1;
  
    if(root->left && findmax(root->left)->data > (root->data)) 
        return 0;
    
    if(root->right && findmin(root->right)->data < (root->data)) 
        return 0;
    
    if(!isBST(root->left) || !isBST(root->right)) 
        return 0;
    
    return 1;
}


// Another variation

// Utility function
int isBSTUtil(Node *root, int min, int max)
{
    if(!root) 
        return 1;
        
    if(root->data < min || root->data > max) 
        return 0;
    
    return (isBSTUtil(root->left, min, root->data-1) && 
            isBSTUtil(root->right, root->data+1, max));
}

bool isBST(Node* root) 
{
    return isBSTUtil(root, INT_MIN, INT_MAX);
}


// Another one

// Utility function
int isBSTUtil(Node *root, int min, int max)
{
    if(!root) 
        return 1;
    
    return (root->data > min && root->data < max && 
            isBSTUtil(root->left, min, root->data) &&
            isBSTUtil(root->right, root->data, max));
}

bool isBST(Node* root) 
{
    return isBSTUtil(root, INT_MIN, INT_MAX);
}


