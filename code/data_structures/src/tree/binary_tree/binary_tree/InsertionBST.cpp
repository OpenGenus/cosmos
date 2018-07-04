/* Part of Cosmos by OpenGenus Foundation 
This code is the C++ implementation of Insertion in a Binary Search Tree(BST). */

#include <bits/stdc++.h>

/* Node Structure */
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  	
    /* Method for printing preorder traversal of the tree */
  	void preOrder(Node *root) {
		
      	if( root == NULL )
          	return;
      
      	std::cout << root->data << " ";
      	
      	preOrder(root->left);
      	preOrder(root->right);
    }
    
    /* Method for insertion into Tree */
    Node * insert(Node * root, int data) {
        if(root==NULL)
        {
           Node* n = new Node(data);
                root=n; 
        }
        
        if(data>root->data)
        {
            if(root->right==NULL)
            {
                Node* n = new Node(data);
                root->right=n;
            }
            else
                root->right=insert(root->right,data);
        }
        
        else if(data<root->data)
        {
            if(root->left==NULL)
            {
                Node* n = new Node(data);
                root->left=n;
            }
            else
                root->left=insert(root->left,data);
        }
        return root;
    }
};

/* Driver Method */
int main() {

    Solution myTree;
    Node* root = NULL;    
    int t;                      // t denotes the number of elements in the tree.
    int data;
    std::cin >> t;
    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
    myTree.preOrder(root);
    return 0;
}
