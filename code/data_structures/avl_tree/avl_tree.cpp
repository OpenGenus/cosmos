// Part of Cosmos by OpenGenus Foundation

// structure representing an AVL node
#include <algorithm>
#include <ostream>
struct AVLNode {
    int data;
    AVLNode *left;
    AVLNode *right;
    int height;
};

// helper function to return height of a node
int getHeight(AVLNode *node) {
    if (node)
        return node->height;

    return -1;
}

// function to find the minimum element in the tree (lefftmost node)
AVLNode *findMin(AVLNode *root) {
    if (root != nullptr)
        while (root->left != nullptr)
            root = root->left;

    return root;
}

// function to find the maximum element in the tree (rightmost node)
AVLNode *findMax(AVLNode *root) {
    if (root != nullptr)
        while (root->right != nullptr)
            root = root->right;

    return root;
}

// LL rotation rooted at X
AVLNode *rotateLL(AVLNode * &X) {
    AVLNode *W = X->left;
    X->left = W->right;
    W->right = X;
    X->height = std::max(getHeight(X->left), getHeight(X->right)) + 1;
    W->height = std::max(getHeight(W->left), getHeight(X)) + 1;

    return W;   // new root
}

// RR rotation rooted at X
AVLNode *rotateRR(AVLNode * &X) {
    AVLNode *W = X->right;
    X->right = W->left;
    W->left = X;
    X->height = std::max(getHeight(X->left), getHeight(X->right)) + 1;
    W->height = std::max(getHeight(X), getHeight(W->right));

    return W;   // new root
}

// LR rotation rooted at X
AVLNode *rotateLR(AVLNode * &X) {
    X->left = rotateRR(X->left);

    return rotateLL(X);
}

// RL rotation rooted at X
AVLNode *rotateRL(AVLNode * &X) {
    X->right = rotateLL(X->right);

    return rotateRR(X);
}

// function to insert a node into the AVL tree
AVLNode *insertIntoAVL(AVLNode * &root, int data) {
    if (root == nullptr) {
        AVLNode *newNode = new AVLNode;
        newNode->data = data;
        newNode->height = 0;
        newNode->left = newNode->right = nullptr;
        root = newNode;
    } else if (data < root->data) {
        root->left = insertIntoAVL(root->left, data);
        if (getHeight(root->left) - getHeight(root->right) == 2) {
            if (data < root->left->data) {
                root = rotateLL(root);
            } else {
                root = rotateLR(root);
            }
        }
    } else if (data > root->data) {
        root->right = insertIntoAVL(root->right, data);
        if (getHeight(root->right) - getHeight(root->left) == 2) {
            if (data > root->right->data) {
                root = rotateRR(root);
            } else {
                root = rotateRL(root);
            }
        }
    }
    root->height = std::max(getHeight(root->left), getHeight(root->right)) + 1;

    return root;
}

// function to delete a node from the AVL tree
AVLNode *deleteFromAVL(AVLNode * &root, int data) {
    if (root == nullptr) {
        return nullptr;
    } else if (data < root->data) {
        root->left = deleteFromAVL(root->left, data);
        if (getHeight(root->right) - getHeight(root->left) == 2) {
            if (getHeight(root->right->right) > getHeight(root->right->left)) {
                root = rotateRR(root);
            } else {
                root = rotateRL(root);
            }
        }
    } else if (data > root->data) {
        root->right = deleteFromAVL(root->right, data);
        if (getHeight(root->left) - getHeight(root->right) == 2) {
            if (getHeight(root->left->left) > getHeight(root->left->right)) {
                root = rotateLL(root);
            } else {
                root = rotateLR(root);
            }
        }
    } else {
        AVLNode *temp = nullptr;
        if (root->left && root->right) {
            temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteFromAVL(root->right, root->data);
            if (getHeight(root->left) - getHeight(root->right) == 2) {
                if (getHeight(root->left->left) > getHeight(root->left->right)) {
                    root = rotateLL(root);
                } else {
                    root = rotateLR(root);
                }
            }
        } else if (root->left) {
            temp = root;
            root = root->left;
            delete temp;
        } else if (root->right) {
            temp = root;
            root = root->right;
            delete temp;
        } else {
            delete root;

            return nullptr;
        }
    }

    return root;
}

// preorder traversal of the AVL tree
void preOrder(AVLNode *root, std::ostream &out) {
    if (root != nullptr) {
        out << (root)->data << " ";
        preOrder((root)->left, out);
        preOrder((root)->right, out);
    }
}

// inorder traversal of the AVL tree
void inOrder(AVLNode *root, std::ostream &out) {
    if (root != nullptr) {
        inOrder((root)->left, out);
        out << (root)->data << " ";
        inOrder((root)->right, out);
    }
}

// postorder traversal of the AVL tree
void postOrder(AVLNode *root, std::ostream &out) {
    if (root != nullptr) {
        postOrder((root)->left, out);
        postOrder((root)->right, out);
        out << (root)->data << " ";
    }
}

// function to free allocated memory
void deleteTree(AVLNode *root) {
    if (root != nullptr) {
        deleteTree((root)->left);
        deleteTree((root)->right);
        delete root;
    }
}

#include <iostream>
using namespace std;
int main() {
    int ch, data;
    AVLNode *root = nullptr;
    while (1) {
        cout << "1. Insert 2. Delete 3. Preorder 4. Inorder 5. Postorder 6. Exit\n";
        cin >> ch;
        switch (ch) {
        case 1: cout << "Enter data\n";
            cin >> data;
            root = insertIntoAVL(root, data);
            break;
        case 2: cout << "Enter data\n";
            cin >> data;
            root = deleteFromAVL(root, data);
            break;
        case 3: preOrder(root, cout);
            cout << endl;
            break;
        case 4: inOrder(root, cout);
            cout << endl;
            break;
        case 5: postOrder(root, cout);
            cout << endl;
            break;
        }
        if (ch == 6)
            break;
    }
    deleteTree(root);

    return 0;
}
