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
void postorder_iterative(node *root) {
    if (root = NULL)
        return;
    std::stack<node *> s1, s2;
    s1.push(root);
    while (s1.empty() == false) {
        node *temp = s1.top();
        s1.pop();
        s2.push(temp);
        if (temp->left) {
            s1.push(temp->left);
        }
        if (temp->right != NULL) {
            s1.push(temp->right);
        }
    }
    while (s2.empty() == false) {
        node *temp = s2.top();
        std::cout << temp->data << " ";
        s2.pop();
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
    postorder_iterative(root);
}
