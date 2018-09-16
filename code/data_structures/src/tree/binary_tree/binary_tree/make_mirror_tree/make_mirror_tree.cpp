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

// Inorder traversal of a tree
void inorderTraversal(node *ptr)
{
    if (ptr == NULL)
        return;
    else
    {
        inorderTraversal(ptr->left);
        cout << ptr->value << "\t";
        inorderTraversal(ptr->right);
    }
}

// create mirror tree
node* mirror(node* root)
{
    node* m_root = NULL;
    if (!root)
        return NULL;
    m_root = getNewNode(root->value);
    m_root->left = mirror(root->right);
    m_root->right = mirror(root->left);
    return m_root;
}

// main
int main()
{
    node *root = createTree();
    cout << "\n Inorder traversal before conversion ";
    inorderTraversal(root);
    node *m_root = mirror(root);
    cout << "\n Inorder traversal after conversion ";
    inorderTraversal(m_root);
    cout << endl;
    return 0;
}
