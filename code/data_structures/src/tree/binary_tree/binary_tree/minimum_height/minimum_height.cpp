#include <iostream>
using namespace std;

typedef struct tree_node
{
    int value;
    struct tree_node *left, *right;
}node;

// create a new node
node *getNewNode(int value)
{
    node *new_node = new node;
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// create the tree
node *createTree()
{
    node *root = getNewNode(31);
    root->left = getNewNode(16);
    root->right = getNewNode(45);
    root->left->left = getNewNode(7);
    root->left->right = getNewNode(24);
    root->left->right->left = getNewNode(19);
    root->left->right->right = getNewNode(29);
    return root;
}

int minDepth(node* A)
{
    if (A == NULL)
        return 0;

    int l = minDepth(A->left);
    int r = minDepth(A->right);

    if (l && r)
        return min(l, r) + 1;

    if (l)
        return l + 1;
    return r + 1;
}


// main
int main()
{
    node *root = createTree();

    cout << minDepth(root);
    cout << endl;
    return 0;
}
