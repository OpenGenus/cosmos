#include <iostream>
using namespace std;
//binary tree structure
struct node{
    int data;
    struct node* left,*right;

};
bool findUniValueST(node *root , int &count)
{
    if(root==NULL)
        return true;
    bool right=findUniValueST(root->right,count);
    bool left=findUniValueST(root->left,count);
    //if left or right subtree is not univalued then that subtree is not univalued
    if(right==false||left==false)
        return false;
    //if right node exists and the value is not equal to root's value,again not univalued
    if(root->right && root->right->data!=root->data)
        return false;
    //same for left node also.
    if(root->left && root->left->data!=root->data)
        return false;
    /*if above possible conditions not satisified then its a univalued subtree.
    Like this we increment as and when there is a univalued subtree*/
    count++;
    /*and return true*/
    return true;


}
//to return count of the univalued subtrees.
int countUniValueST(node *root ){
    int count=0;
    findUniValueST(root,count);
    return count;
}
//for inserting a new node
node *newNode(int data){
    node *temp=new node;
    temp->data=data;
    temp->right=NULL;
    temp->left=NULL;
    return (temp);
}
int main() {
//sample input of the binary tree
    struct node* root=newNode(1);
    root->left=newNode(3);
    root->right=newNode(3);
    root->left->right=newNode(3);
    root->left->left=newNode(3);
    cout<<"Number of univalued subtrees:"<<" "<<countUniValueST(root)<<endl;

    return 0;
}
