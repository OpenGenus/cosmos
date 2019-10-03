/*
 * Data Structures : Finding Diameter of a binary tree
 *
 * Description : Diameter of tree is defined as the longest path or route between any two nodes in a tree.
 *            This path may or may not be through the root. The below algorithm computes the height of
 *            the tree and uses it recursivley in the calculation of diameter of the specified tree.
 *
 * A massive collaborative effort by OpenGenus Foundation
 */

#include <iostream>
using namespace std;

// get the max of two no.s
int max(int a, int b)
{
    return (a > b) ? a : b;
}

typedef struct node
{
    int value;
    struct node *left, *right;
} node;

// create a new node
node *getNewNode(int value)
{
    node *new_node = new node;
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// compute height of the tree
int getHeight(node *root)
{
    if (root == NULL)
        return 0;

    // find the height of each subtree
    int lh = getHeight(root->left);
    int rh = getHeight(root->right);

    return 1 + max(lh, rh);
}

// compute tree diameter recursively
int getDiameter(node *root)
{
    if (root == NULL)
        return 0;

    // get height of each subtree
    int lh = getHeight(root->left);
    int rh = getHeight(root->right);

    // compute diameters of each subtree
    int ld = getDiameter(root->left);
    int rd = getDiameter(root->right);

    return max(lh + rh + 1, max(ld, rd));
}

// create the tree
node *createTree()
{
    node *root = getNewNode(31);
    root->left = getNewNode(16);
    root->right = getNewNode(52);
    root->left->left = getNewNode(7);
    root->left->right = getNewNode(24);
    root->left->right->left = getNewNode(19);
    root->left->right->right = getNewNode(29);
    return root;
}

// main
int main()
{
    node *root = createTree();
    cout << "\nDiameter of the tree is " << getDiameter(root);
    cout << endl;
    return 0;
}
