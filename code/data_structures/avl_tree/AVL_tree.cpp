#include <iostream>
using namespace std;
// Part of Cosmos by OpenGenus Foundation
// structure representing an AVL node
struct AVLNode  {
    int data;
    AVLNode* left;
    AVLNode* right;
    int height;
};

// helper function to return height of a node
int getHeight(AVLNode* node)    {
    if(node)    {
        return node->height;
    }
    return -1;
}

// function to find the minimum element in the tree (lefftmost node)
AVLNode* findMin(AVLNode* root) {
    if(root == NULL)
        return NULL;
    while(root->left != NULL)
        root = root->left;
    return root;

}

// LL rotation rooted at X
AVLNode* LL_rotation(AVLNode* &X)    {
    AVLNode* W = X->left;
    X->left = W->right;
    W->right = X;
    X->height = max(getHeight(X->left), getHeight(X->right)) + 1;
    W->height = max(getHeight(W->left), getHeight(X)) + 1;
    return W;   //new root
}

// RR rotation rooted at X
AVLNode* RR_rotation(AVLNode* &X)    {
    AVLNode* W = X->right;
    X->right = W->left;
    W->left = X;
    X->height = max(getHeight(X->left), getHeight(X->right)) + 1;
    W->height = max(getHeight(X), getHeight(W->right));
    return W;   //new root
}

// LR rotation rooted at X
AVLNode* LR_rotation(AVLNode* &X)   {
    X->left = RR_rotation(X->left);
    return LL_rotation(X);
}

// RL rotation rooted at X
AVLNode* RL_rotation(AVLNode* &X)   {
    X->right = LL_rotation(X->right);
    return RR_rotation(X);
}

// function to insert a node into the AVL tree
AVLNode* insertIntoAVL(AVLNode* &root, int data)  {
    if(root == NULL)    {
        AVLNode* newNode = new AVLNode;
        newNode->data = data;
        newNode->height = 0;
        newNode->left = newNode->right = NULL;
        root = newNode;
    }
    else if(data < root->data)  {
        root->left = insertIntoAVL(root->left, data);
        if(getHeight(root->left) - getHeight(root->right) == 2) {
            if(data < root->left->data)
                root = LL_rotation(root);
            else
                root = LR_rotation(root);
        }
    }
    else if(data > root->data)  {
        root->right = insertIntoAVL(root->right, data);
        if(getHeight(root->right) - getHeight(root->left) == 2) {
            if(data > root->right->data)
                root = RR_rotation(root);
            else
                root = RL_rotation(root);
        }
    }
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    return root;
}

// function to delete a node from the AVL tree
AVLNode* deleteFromAVL(AVLNode* &root, int data)    {
    if(root == NULL)
        return NULL;
    else if(data < root->data)  {
        root->left = deleteFromAVL(root->left, data);
        if(getHeight(root->right) - getHeight(root->left) == 2) {
            if(getHeight(root->right->right) > getHeight(root->right->left))
                root = RR_rotation(root);
            else
                root = RL_rotation(root);
        }
    }
    else if(data > root->data)  {
        root->right = deleteFromAVL(root->right, data);
        if(getHeight(root->left) - getHeight(root->right) == 2) {
            if(getHeight(root->left->left) > getHeight(root->left->right))
                root = LL_rotation(root);
            else
                root = LR_rotation(root);
        }
    }
    else    {
        AVLNode* temp = NULL;
        if(root->left && root->right)   {
            temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteFromAVL(root->right, root->data);
            if(getHeight(root->left) - getHeight(root->right) == 2) {
                if(getHeight(root->left->left) > getHeight(root->left->right))
                    root = LL_rotation(root);
                else
                    root = LR_rotation(root);
            }
        }    
        else if(root->left) {
            temp = root;
            root = root->left;
            delete temp;
        }
        else if(root->right)    {
            temp = root;
            root = root->right;
            delete temp;
        }
        else    {
            delete root;
            return NULL;
        }
    }
    return root;
}

// preorder traversal of the AVL tree
void preOrder(AVLNode *root)   {
    if(root != NULL)    {
        cout<<(root)->data<<" ";
        preOrder((root)->left);
        preOrder((root)->right);
    }
}

// inorder traversal of the AVL tree
void inOrder(AVLNode *root)    {
    if(root != NULL)    {
        inOrder((root)->left);
        cout<<(root)->data<<" ";
        inOrder((root)->right);
    }
}

// postorder traversal of the AVL tree
void postOrder(AVLNode *root)  {
    if(root != NULL)    {
        postOrder((root)->left);
        postOrder((root)->right);
        cout<<(root)->data<<" ";
    }
}

// function to free allocated memory
void deleteTree(AVLNode *root) {
    if(root == NULL)
        return;
    deleteTree((root)->left);
    deleteTree((root)->right);
    delete root;
}

int main()  {
    int ch,data;
    AVLNode *root = NULL;
    while(1)    {
        cout<<"1. Insert 2. Delete 3. Preorder 4. Inorder 5. Postorder 6. Exit\n";
        cin>>ch;
        switch(ch)  {
            case 1: cout<<"Enter data\n";
                    cin>>data;
                    root = insertIntoAVL(root,data);
                    break;
            case 2: cout<<"Enter data\n";
                    cin>>data;
                    root = deleteFromAVL(root,data);
                    break;
            case 3: preOrder(root);
                    cout<<endl;
                    break;
            case 4: inOrder(root);
                    cout<<endl;
                    break;
            case 5: postOrder(root);
                    cout<<endl;
                    break;
        }
        if(ch == 6)
            break;
    }
    deleteTree(root);
    return 0;
}
