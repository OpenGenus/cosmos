#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct node
{
    int key;
    struct node *left, *right;
};

struct node *newNode(int value)
{
    struct node *temp = new node;
    temp->key = value;
    temp->left = temp->right = NULL;
    return temp;
}

struct node* insert(struct node* node, int key)
{
    if (node == NULL)
        return newNode(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    return node;
}

//Inorder traversal
void inorder(struct node *root)
{
    if (root)
    {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

//Preorder traversal
void preorder(struct node *root)
{
    if (root)
    {
    cout << root->key << " ";
    preorder(root->left);
    preorder(root->right);
    }
}


struct node* leftRotate(struct node * root)
{
    struct node *right, *right_left;
    if ( (root == NULL) || (root->right ==NULL) )
        return root;
    right = root->right;
    right_left = right->left;
    right->left = root;
    root->right = right_left;
    return right;
}

struct node* rightRotate(struct node * root){
    struct node *left, *left_right;
    if ( (root == NULL) || (root->left == NULL) )
        return root;
    left = root->left;
    left_right = left->right;
    left->right = root;
    root->left = left_right;
    return left;
}

/*
Make a vine structure rooted at a dummy root and 
branching only towards right
*/

struct node* createBackbone(struct node* root)
{
    struct node *parent, *r;
    r = newNode(-1);
    parent = r;
    r->right = root;
    // making tree skewed towards right;
    while (parent->right)
    {
        if (parent->right->left == NULL)
            parent = parent->right;
        else
            parent->right = rightRotate(parent->right);        
    }
    return r;
};


/*
Compress the tree using series of left rotations on
alternate nodes provided by the count.
*/
struct node* compress(struct node* root, int cnt)
{
    struct node *temp;
    temp = root;
    while (cnt && temp)
    {
        temp->right = leftRotate(temp->right);
        temp = temp->right;
        cnt -= 1;
    }
    return root;
}

// To calculate height of the tree
int height(struct node* root)
{
    int left, right;
    if (root == NULL)
        return -1;
    left = height(root->left);
    right = height(root->right);
    left = left >= right ? left : right;
    return 1 + left;
}

struct node* balanceTree(struct node* root)
{
   root = createBackbone(root);
 
   /*
    Now a dummy root is added so we get original
    root from root->right;
   */
   cout << "Backbone Tree structure" << endl;
   cout << "Inorder traversal: ";
   inorder(root->right);
   cout << "\nPreorder traversal: ";
   preorder(root->right);
   cout << endl;

   // h = total number of nodes
   int h = height(root);
   int left_count, temp, l = 0;
   temp = h + 1;

   // l = log(n+1) (base 2)
   while (temp > 1)
   {
       temp /= 2;
       l += 1;     
   }
   
   /*
    make n-m rotations starting from the top of backbone
    where m = 2^( floor(lg(n+1)))-1 
   */
   left_count = h + 1 - (1 << l);
   if (left_count == 0)
   {
       left_count = (1 << (l - 1));
   }

   root =  compress(root, left_count);
   h -= left_count ;

   while (h > 1)
   {
        h /= 2;
        root = compress(root, h);
   }

   return root;
};

int main()
{
    /* Let us create following BST
     *       50
     *         \
     *         70
     *        /
     *       60    */

    struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 70);
    insert(root, 60);
    // insert(root, 80);
    
    root = balanceTree(root);
    root = root->right;

    /* Back-bone structure of above BST
     *       50
     *         \
     *          60 
     *            \ 
     *             70 */


    /* Balanced BST
     *       60
     *      /  \
     *    50    70 */

    cout <<  endl;
    
    cout << "Balanced Tree Structure " << endl;
    cout << "Inorder traversal: ";
    inorder(root);

    cout << "\nPreorder traversal: ";
    preorder(root);
   
    return 0;
}