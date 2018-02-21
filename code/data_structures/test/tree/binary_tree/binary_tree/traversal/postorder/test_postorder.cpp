#include <iostream>
#include <cassert>
#include "../../src/tree/binary_tree/binary_tree/traversal/postorder/postorder.cpp"

int main()
{
    node *root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    root->right->left = newnode(6);
    root->right->right = newnode(7);

    std::cout << "Post order traversal of tree is ";
    assert(post_order(root));

    return 0;
}