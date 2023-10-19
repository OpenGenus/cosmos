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
    //Post order Traversing (left right root)
    void Postorder(node*curr){
        if(curr==nullptr){
            return;
        }
        Postorder(curr->left);
        Postorder(curr->right);
        cout<<curr->data<<" ";
    }
    //using 2 stack
    void TwoStackPostorder(node*curr){
        if(curr==nullptr){
            return;
        }
        stack<node*>s;
        stack<node*>s1;
        s.push(curr);
        while(!s.empty()){
            s1.push(s.top());
            s.pop();
            node*current=s1.top();
            if(current->left){
                s.push(current->left);
            }
            if(current->right){
                s.push(current->right);
            }
        }
        while(!s1.empty()){
            node*temp=s1.top();
            cout<<temp->data<<" ";
            s1.pop();
        }
    }
    //1 stack only
    void OneStackPostorder(node*curr){
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
                node *temp=s.top()->right;
                if(temp==nullptr){
                    temp=s.top();
                    s.pop();
                    cout<<temp->data<<" ";
                    while(!s.empty()&&temp==s.top()->right){
                        temp=s.top();
                        s.pop();
                        cout<<temp->data<<" ";
                    }
                }
                else{
                    curr=temp;
                }
            }
        }
    }
};
int main(){
    BinaryTree b;
    int arr[6]={1,2,3,4,5,6};
    b.treestructure(arr);
    b.Postorder(b.root);
}

