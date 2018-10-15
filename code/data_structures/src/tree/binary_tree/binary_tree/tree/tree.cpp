#include <iostream>
using namespace std;

struct node
{
    int key;
    struct node *left, *right;
};

struct node *newNode(int item)
{
    struct node *temp = new node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

//Inorder traversal
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

//Preorder traversal
void preorder(struct node *root)
{
    if (root == NULL)
        return;
    cout << root->key << " ";
    preorder(root->left);
    preorder(root->right);
}

//Postorder traversal
void postorder(struct node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->key << " ";
}

//Insert key
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

// Driver Code
int main()
{
    /* Let us create following BST
     *       50
     *     /    \
     *    30     70
     *   /  \   /  \
     * 20   40 60   80 */
    struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    cout << "Inorder traversal: ";
    inorder(root);

    cout << "\nPreorder traversal: ";
    preorder(root);

    cout << "\nPostorder traversal: ";
    postorder(root);
    cout << endl;
    return 0;
}
