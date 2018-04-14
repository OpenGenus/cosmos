//Tree Sort implemented using C++
// Part of Cosmos by OpenGenus Foundation
#include <vector>
#include <iostream>

using namespace std;
struct Node
{
    int data;
    struct Node *left, *right;
};
//Function to create new Node
struct Node *newnode(int key)
{
    struct Node *temp = new Node;
    temp->data = key;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

Node* insert(Node *node, int key)
{
    if (node == NULL)
        return newnode(key);               //If tree is empty return new node
    if (key < node->data)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);
    return node;
}
void store(Node *root, int a[], int &i)
{
    if (root != NULL)
    {
        store(root->left, a, i);
        a[i++] = root->data;
        store(root->right, a, i);
    }
}
void TreeSort(vector<int>& a)
{
    struct Node *root = NULL;

    //Construct binary search tree
    root = insert(root, a[0]);
    for (size_t i = 1; i < a.size(); i++)
        insert(root, a[i]);

    //Sorting the array using inorder traversal on BST
    int i = 0;
    store(root, a.data(), i);
}

int main()
{

    vector<int> a{1, 6, 8, 3, 10, 2, 12};

    TreeSort(a);

    cout << "The sorted array is :\n";
    //Printing the sorted array
    for (size_t i = 0; i < a.size(); i++)
        cout << a[i] << " ";

    return 0;
}

/* output:
 * The sorted array is :
 * 1 2 3 6 8 10 12
 */
