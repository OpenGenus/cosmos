#include<iostream>
#include<queue>
#include<stack>
using namespace std;
struct node{
    int data;
    node*left;
    node*right;
};
class BinaryTree{
public:
    node*root;
    int ch;
    BinaryTree(){
        root=nullptr;
        ch=0;
    }

    //Binary Tree Creation Accordingly.
    void treestructure(int arr[]){
        root=new node{arr[0],nullptr,nullptr};
        root->left=new node{arr[1],nullptr,nullptr};
        root->right=new node{arr[2],nullptr,nullptr};
        root->left->left=new node{arr[3],nullptr,nullptr};
        root->left->right=new node{arr[4],nullptr,nullptr};
        root->right->left=new node{arr[5],nullptr,nullptr};
    }
    //Inorder Traversing(left root right)
    void Inorder(node*curr){
        if(curr==nullptr){
            return;
        }
        Inorder(curr->left);
        cout<<curr->data<<" ";
        Inorder(curr->right);
    }

    //Inorder but without Recursion using stack.
    void IterativeInorder(node*curr){
        if(curr==nullptr){
            return;
        }
        stack<node*>s;
        while(!s.empty()||curr!=nullptr){
            if(curr!=nullptr){
                s.push(curr);
                curr=curr->left;
            }
            else{
                curr=s.top();
                s.pop();
                cout<<curr->data<<" ";
                curr=curr->right;
            }
        }
    }
};
int main(){
    BinaryTree b;
    int arr[6]={1,2,3,4,5,6};
    b.treestructure(arr);
    b.IterativeInorder(b.root);
}

