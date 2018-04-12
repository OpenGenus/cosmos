#include <iostream>
#define ll long long
#define MOD 1000000007
using namespace std;
// Part of Cosmos by OpenGenus Foundation
// structure representing a treap node
struct node
{
    ll key;
    ll priority;
    node* left;
    node* right;
    node* parent;

    node(ll data)
    {
        key = data;
        priority = (1LL * rand()) % MOD;
        left = right = parent = NULL;
    }
};

// function to left-rotate the subtree rooted at x
void left_rotate(node* &root, node* x)
{
    node* y = x->right;
    x->right = y->left;

    if (y->left != NULL)
        y->left->parent = x;
    y->parent = x->parent;
    if (x->parent == NULL)
        root = y;
    else if (x->key > x->parent->key)
        x->parent->right = y;
    else
        x->parent->left = y;

    y->left = x;
    x->parent = y;
}

// function to right-rotate the subtree rooted at x
void right_rotate(node* &root, node* x)
{
    node* y = x->left;
    x->left = y->right;

    if (y->right != NULL)
        y->right->parent = x;
    y->parent = x->parent;
    if (x->parent == NULL)
        root = y;
    else if (x->key > x->parent->key)
        x->parent->right = y;
    else
        x->parent->left = y;

    y->right = x;
    x->parent = y;
}

// function to restore min-heap property by rotations
void treap_insert_fixup(node* &root, node* z)
{
    while (z->parent != NULL && z->parent->priority > z->priority)
    {
        // if z is a right child
        if (z->key > z->parent->key)
            left_rotate(root, z->parent);
        // if z is a left child
        else
            right_rotate(root, z->parent);
    }
}

// function to insert a node into the treap
// performs simple BST insert and calls treap_insert_fixup
void insert(node* &root, ll data)
{
    node *x = root, *y = NULL;
    while (x != NULL)
    {
        y = x;
        if (data < x->key)
            x = x->left;
        else
            x = x->right;
    }

    node* z = new node(data);
    z->parent = y;
    if (y == NULL)
        root = z;
    else if (z->key > y->key)
        y->right = z;
    else
        y->left = z;

    treap_insert_fixup(root, z);
}

void preorder(node* root)
{
    if (root)
    {
        cout << root->key << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// free the allocated memory
void delete_treap(node* root)
{
    if (root)
    {
        delete_treap(root->left);
        delete_treap(root->right);
        delete root;
    }
}

int main()
{
    node* root = NULL;
    int choice;
    ll key;
    while (true)
    {
        cout << "1. Insert 2. Preorder 3. Quit\n";
        cin >> choice;
        if (choice == 1)
        {
            cout << "Enter key : ";
            cin >> key;
            insert(root, key);
        }
        else if (choice == 2)
        {
            preorder(root);
            cout << endl;
        }
        else
            break;
    }
    delete_treap(root);
    return 0;
}
