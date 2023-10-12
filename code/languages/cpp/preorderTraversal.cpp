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
    //Preorder Traversing(print untill left goes to null the root right)
    void Preorder(node*curr){
        if(curr==nullptr){
            return;
        }
        cout<<curr->data<<" ";
        Preorder(curr->left);
        Preorder(curr->right);
    }
    //Traversing but not through recursion but through stack
    void IterativePreorder(node*curr){
        if(curr==nullptr){
            return;
        }
        stack<node*>s;
        s.push(curr);
        while(!s.empty()){
            node*current=s.top();
            cout<<current->data<<" ";
            s.pop();
            if(current->right){
                s.push(current->right);
            }
            if(current->left){
                s.push(current->left);
            }
        }
    }
};
int main(){
    BinaryTree b;
    int arr[6]={1,2,3,4,5,6};
    b.treestructure(arr);
    b.IterativePreorder(b.root);
}

