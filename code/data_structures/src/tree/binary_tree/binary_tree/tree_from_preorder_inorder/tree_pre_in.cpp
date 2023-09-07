#include <bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node *left,*right;
};

struct node* helper(int preStart,int inStart,int inEnd,vector<int> preorder,vector<int> inorder){
    if (preStart>preorder.size() || inStart>inEnd) return NULL;
    struct node* root=(struct node *)malloc(sizeof(struct node));
    root->val=preorder[preStart];
    int inIndex;
    for (int i=inStart;i<=inEnd;i++){
        if (inorder[i]==preorder[preStart]){
            inIndex=i;break;
        }
    }
    root->left=helper(preStart+1,inStart,inIndex-1,preorder,inorder);
    root->right=helper(preStart+inIndex-inStart+1,inIndex+1,inEnd,preorder,inorder);
    return root;
}

void postorder(struct node* root){
    if (root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->val<<" ";
}

int main(){
    vector<int> preorder={3,9,20,15,7};
    vector<int> inorder={9,3,15,20,7};
    int n=preorder.size();
    struct node* root;
    root=helper(0,0,n-1,preorder,inorder);
    postorder(root);
}