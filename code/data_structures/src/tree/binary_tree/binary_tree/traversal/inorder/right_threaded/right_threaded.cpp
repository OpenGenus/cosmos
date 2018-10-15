/* Part of Cosmos by OpenGenus Foundation */
/*
 * Right-Threaded Binary Tree implementation in C++
 */
//Author: Arpan Konar
#include <iostream>
using namespace std;
typedef long long ll;
#define REP(i, n) for (long long i = 0; i < (n); i++)
#define FOR(i, a, b) for (long long i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
//Structure of a node
struct node
{
    int data;
    node * left;
    node * right;
    bool isThreaded;
};
//Function to create a new node with value d
node * newnode(int d)
{
    node *temp = new node();
    temp->data = d;
    temp->left = NULL;
    temp->right = NULL;
    temp->isThreaded = false;

    return temp;        // the node will not be deleted
}
//Function to find the leftmost node of a subtree
node * leftmost(node * root)
{
    node * temp = root;
    while (temp != NULL && temp->left != NULL)
        temp = temp->left;
    return temp;
}
//Function to find a node with value b
node * findNode(int b, node * root)
{
    if (root->data == b)
        return root;
    root = leftmost(root);
    while (1)
    {
        if (root->data == b)
            return root;
        while (root->isThreaded)
        {
            root = root->right;
            if (root->data == b)
                return root;
        }
        if (root->right != NULL)
            root = leftmost(root->right);
        else
            break;
    }
    return NULL;
}
//Function to set the new node at left of node x
node * setLeftNode(node * x, int a)
{
    if (x->left != NULL)
    {
        cout << a << " is ignored" << endl;
        return x;
    }
    node * temp = newnode(a);
    temp->right = x;
    x->left = temp;
    temp->isThreaded = true;
    return x;
}
//Function to set the new node at right of node x
node * setRightNode(node * x, int a)
{
    if (x->right != NULL && !x->isThreaded)
    {
        cout << a << " is ignored" << endl;
        return x;
    }
    node * temp = newnode(a);
    if (x->isThreaded)
    {
        node *q = x->right;
        x->isThreaded = false;
        x->right = temp;
        temp->right = q;
        temp->isThreaded = true;
    }
    else
        x->right = temp;
    return x;
}
//Function to take input and create threaded tree
/*Input is of the form number L/R number
 * where a is entered at the left or right position of b
 * if b is found
 * Input ends when a is -1
 */
node * createTree()
{
    node * root = NULL;
    while (1)
    {
        int a, b;
        char c;
        cin >> a;
        if (a == -1)
            break;
        cin >> c >> b;
        if (root == NULL)
            root = newnode(a);
        else
        {
            node * x = findNode(b, root);
            if (x == NULL)
                cout << "Node not found" << endl;
            else
            {

                if (c == 'L')
                    x = setLeftNode(x, a);
                else if (c == 'R')
                    x = setRightNode(x, a);
            }
        }
    }
    return root;
}
//Function for inorder traversal of threaded binary tree
void inOrder(node * root)
{
    root = leftmost(root);
    while (1)
    {
        cout << root->data << " ";
        while (root->isThreaded)
        {
            root = root->right;
            cout << root->data << " ";
        }
        if (root->right != NULL)
            root = leftmost(root->right);
        else
            break;
    }
}
//Driver function to implement the above functions
int main()
{
    node * root = createTree();
    cout << "Inorder:";
    inOrder(root);
    cout << endl;
    return 0;
}
