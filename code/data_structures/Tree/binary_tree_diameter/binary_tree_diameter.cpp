#include<iostream>
using namespace std;

class node{
public:
    int data;
    node *left;
    node *right;

    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

node *buildTree(){
    int d;
    cout<<"\nEnter data:";
    cin>>d;

    if(d==-1){
        return NULL;
    }

    ///rec case
    node *n =new node(d);
    n->left = buildTree();
    n->right = buildTree();
    return n;
}

int height(node *root){
    if(root==NULL){
        return 0;
    }

    return (max(height(root->left),height(root->right))+1);
}

int diameter(node*root){
    if(root==NULL){
        return 0;
    }

    int cp1 = height(root->left) + height(root->right);
    int cp2 = diameter(root->left);
    int cp3 = diameter(root->right);

    return max(cp1,max(cp2,cp3));
}

int main(){

    node *root = NULL;
    root = buildTree();
    cout<<"\nDiameter of Binary Tree: ";
    cout<<diameter(root);

    return 0;
}
