#include <iostream>
using namespace std;

// Part of Cosmos by OpenGenus Foundation

#include <iostream>
using namespace std;

// max function
int max(int a, int b)
{
    return (a > b) ? a : b;
}

struct node
{
    int data;
    node* left;
    node* right;
};

// create a new node
struct node* getNode(int data)
{
    node* newNode = new node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Inorder Traversal
void inorder(struct node* root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

//Insert new node into Binary Tree
struct node* Insert(struct node* root, int data)
{
    if (root == NULL)
        return getNode(data);

    if (data < root->data)
        root->left = Insert(root->left, data);
    else if (data > root->data)
        root->right = Insert(root->right, data);

    return root;
}

// compute height of the tree
int getHeight(node* root)
{
    if (root == NULL)
        return 0;

    // find the height of each subtree
    int lh = getHeight(root->left);
    int rh = getHeight(root->right);

    return 1 + max(lh, rh);
}

int main()
{
    node* root = NULL;
    int a[30];
    int n;
    cout << "\nEnter no. of nodes: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        root = Insert(root, a[i]);
    }

    cout << "\n\nInorder: ";
    inorder(root);
    cout << "\n\nHeight of the tree is " << getHeight(root);


    return 0;
}
