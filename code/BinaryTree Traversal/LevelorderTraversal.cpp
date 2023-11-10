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
    //Traversing through levels starting from level 1 to all the way level h.
    void Levelorder(node*curr){
        if(curr==nullptr){
            return;
        }
        queue<node*>q;
        q.push(curr);
        while(!q.empty()){
            node*current=q.front();
            cout<<current->data<<" ";
            q.pop();
            if(current->left){
                q.push(current->left);
            }
            if(current->right){
                q.push(current->right);
            }
        }
    }
};
int main(){
    BinaryTree b;
    int arr[6]={1,2,3,4,5,6};
    b.treestructure(arr);
    b.Levelorder(b.root);
}

