#include <iostream>
#include <stack>

class Node
{
public:
    int info;
    Node* left_child;
    Node* right_child;
    Node (int info) : info{info}, left_child{nullptr}, right_child{nullptr}
    {
    }
};

class BinaryTree
{
public:
    Node* root;
    BinaryTree() : root{nullptr}
    {
    }
    void zigzag_traversal();
};

void BinaryTree :: zigzag_traversal()
{
    std::stack<Node*> st1, st2;
    st2.push (root);
    while (!st1.empty() || !st2.empty())
    {
        while (!st1.empty())
        {
            Node* curr = st1.top();
            st1.pop();
            if (curr->right_child)
                st2.push (curr->right_child);
            if (curr->left_child)
                st2.push (curr->left_child);
            std::cout << curr->info << " ";
        }
        while (!st2.empty())
        {
            Node* curr = st2.top();
            st2.pop();
            if (curr->left_child)
                st1.push (curr->left_child);
            if (curr->right_child)
                st1.push (curr->right_child);
            std::cout << curr->info << " ";
        }
    }
}

int main()
{
    BinaryTree binary_tree;
    binary_tree.root = new Node (1);
    binary_tree.root->left_child = new Node (2);
    binary_tree.root->right_child = new Node (3);
    binary_tree.root->left_child->left_child = new Node (4);
    binary_tree.root->left_child->right_child = new Node (5);
    binary_tree.root->right_child->left_child = new Node (6);
    binary_tree.root->right_child->right_child = new Node (7);
    binary_tree.zigzag_traversal();
    return 0;
}
