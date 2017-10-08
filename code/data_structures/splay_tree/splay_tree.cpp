// Part of Cosmos by OpenGenus Foundation
//  Contributed by Riya Pannu on 08/10/17.

#include <iostream>
using namespace std;

struct node{    //Tree node
    int key;
    node *left;
    node *right;
};

//Allocating a new node with the given key and left and right pointers
node* GetNewNode(int key){
    node* NewNode=new node();
    NewNode->key=key;
    NewNode->left=NULL;
    NewNode->right=NULL;
    return NewNode;
}

// Function to right rotate subtree rooted with y
node *rightRotate(node *x)
{
    node *y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}

// Function to left rotate subtree rooted with x
node *leftRotate(node *x)
{
    node *y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

//If key is found, that node is splayed and it becomes the new root
//else the last node accessed prior to reaching NULL becomes the root.
// This function returns the new node.

node *splay(struct node *root, int key)
{
    // Base cases: root is NULL or key is present at root
    if (root == NULL || root->key == key)
        return root;
    
    // Key lies in left subtree
    if (root->key > key)
    {
        
        if (root->left == NULL) return root;
        
        // Zig-Zig
        if (root->left->key > key)
        {
            // Recursively bring the key as root of left-left
            root->left->left = splay(root->left->left, key);
            
            // Do first rotation for root, second rotation is done after else
            root = rightRotate(root);
        }
        else if (root->left->key < key) // Zig-Zag
        {
            // Recursively bring the key as root of left-right
            root->left->right = splay(root->left->right, key);
            
            // Do first rotation for root->left
            if (root->left->right != NULL)
                root->left = leftRotate(root->left);
        }
        
        // Do second rotation for root
        return (root->left == NULL)? root: rightRotate(root);
    }
    else // Key lies in right subtree
    {
    
        if (root->right == NULL) return root;
        
        // Zag-Zig
        if (root->right->key > key)
        {
            // Bring the key as root of right-left
            root->right->left = splay(root->right->left, key);
            
            // Do first rotation for root->right
            if (root->right->left != NULL)
                root->right = rightRotate(root->right);
        }
        else if (root->right->key < key)// Zag-Zag
        {
            // Bring the key as root of right-right and do first rotation
            root->right->right = splay(root->right->right, key);
            root = leftRotate(root);
        }
        
        // Do second rotation for root
        return (root->right == NULL)? root: leftRotate(root);
    }
}

struct node *search(struct node *root, int key)
{
    return splay(root, key);
}

// Print preorder traversal of the tree.
void preOrder(node *root)
{
    if (root != NULL)
    {
        cout<<root->key<<endl;
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Function to insert a new key k in splay tree with given root
node *insert(struct node *root, int k)
{
    // Simple Case: If tree is empty
    if (root == NULL) return GetNewNode(k);
    
    // Bring the closest leaf node to root
    root = splay(root, k);
    
    // If key is already present, then return
    if (root->key == k) return root;
    
    // Otherwise allocate memory for new node
    node *newnode  = GetNewNode(k);
    
    // If root's key is greater, make root as right child
    // of newnode and copy the left child of root to newnode
    if (root->key > k)
    {
        newnode->right = root;
        newnode->left = root->left;
        root->left = NULL;
    }
    
    // If root's key is smaller, make root as left child
    // of newnode and copy the right child of root to newnode
    else
    {
        newnode->left = root;
        newnode->right = root->right;
        root->right = NULL;
    }
    
    return newnode; // newnode becomes new root
}

// Delete function for Splay tree.
// Returns the new root of Splay Tree after removing the key
node* delete_key(node *root, int key)
{
    node *temp;
    if (!root)
        return NULL;
    
    // Splay the given key
    root = splay(root, key);
    
    // If key is not present, then return root
    if (key != root->key)
        return root;
    
    // If key is present
    // If left child of root does not exist
    // make root->right as root
    if (!root->left)
    {
        temp = root;
        root = root->right;
    }
    
    // Else if left child exits
    else
    {
        temp = root;
        
        root = splay(root->left, key);
        
        // Make right child of previous root as new root's right child
        root->right = temp->right;
    }
    
    // Free the the node containing the key
    free(temp);
    
    // Return root of the new Splay Tree
    return root;
    
}

int main()
{
    node *root = GetNewNode(200);
    root->left = GetNewNode(150);
    root->right = GetNewNode(300);
    root->left->left = GetNewNode(140);
    root->left->left->left = GetNewNode(130);
    root->left->left->left->left = GetNewNode(120);
    root = search(root, 120);
    cout<<"Preorder traversal of the modified Splay tree is \n";
    preOrder(root);
    root = insert(root, 125);
    cout<<"Preorder traversal of the modified Splay tree is \n";
    preOrder(root);
    int key = 140;
    root = delete_key(root, key);
    cout<<"Preorder traversal of the modified Splay tree is \n";
    preOrder(root);
    return 0;
}



