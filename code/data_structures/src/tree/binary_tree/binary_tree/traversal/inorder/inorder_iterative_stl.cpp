#include <iostream>
#include <stack>

class node {
  public:
    int data;
    node *left;
    node *right;
    node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void insert(node *&root, int key) {
    node *temp = new node(key);
    if (root == NULL) {
        root = temp;
        return;
    }
    node *x = root, *y = NULL;
    while (x != NULL) {
        y = x;
        if (key < x->data) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    if (y == NULL) {
        y = temp;
    } else if (key < y->data) {
        y->left = temp;
    } else {
        y->right = temp;
    }
    return;
}
void inorder_iterative(node *root) {
    if (root == NULL)
        return;
    std::stack<node *> s;
    s.push(root);
    node *temp = root->left;
    while (temp != NULL) {
        s.push(temp);
        temp = temp->left;
    }
    while (s.empty() == false) {
        temp = s.top();
        if (temp->right == NULL) {
            std::cout << temp->data << " ";
            s.pop();
        } else {
            std::cout << temp->data << " ";
            s.pop();
            s.push(temp->right);
            temp = temp->right;
            if (temp->left != NULL and temp->right != NULL) {
                temp = temp->left;
                while (temp != NULL) {
                    s.push(temp);
                    temp = temp->left;
                }
            }
        }
    }
    return;
}

int main() {
    node *root = NULL;
    insert(root, 10);
    insert(root, 20);
    insert(root, 30);
    insert(root, 15);
    insert(root, 50);
    insert(root, 25);
    insert(root, 7);
    insert(root, 8);
    insert(root, 12);
    inorder_iterative(root);
}
