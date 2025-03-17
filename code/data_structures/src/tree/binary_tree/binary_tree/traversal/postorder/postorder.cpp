#include <iostream>
#include <memory>
// Part of Cosmos by OpenGenus Foundation
struct node
{
    int data;
    node *left;
    node *right;
};

node *newnode(int data)
{
     node *temp = new node;
     temp->data = data;
     temp->left = nullptr;
     temp->right = nullptr;

     return temp;
}

int post_order(node *root)
{
    if (!root)
        return 0;

    post_order(root->left);
    post_order(root->right);
    std::cout << root->data << " ";
}
