#include<iostream>
using namespace std;
//Binary tree structure
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
//for inserting a new node
node *newNode(int data){
     node *temp=new node;
    temp->data=data;
    temp->right=NULL;
    temp->left=NULL;
    return (temp);
}
//helper function
//Function to return sum of subtrees and count subtrees with sum=x
int countSubtreesWithSumX(node* root, int x ,int& count)
{ if(root==NULL)
   return 0;
  int ls= countSubtreesWithSumX(root->left,x,count);
  int rs= countSubtreesWithSumX(root->right,x,count);
  int sum=ls+rs+root->data;
  if(sum==x)
  count++;
  return sum;
}
//main function
//Function to return the count of subtrees whose sum=x
int countSubtreescheckroot(node* root, int x)
{
  if(root==NULL)
   return 0;
  int count=0;
 //return sum of left and right subtrees respectively
int ls= countSubtreesWithSumX(root->left,x,count);
int rs= countSubtreesWithSumX(root->right,x,count);
//checks if the root value added to sums of left and right subtrees equals x
if(x==ls+rs+root->data)
count++;
//returns the count of subtrees with their sum=x
return count;
}
int main() {
// input of sum to check for
   int x;
   cout<<"Enter the sum to check for"<<endl;
   cin>>x;
//sample input of the binary tree
	struct node* root=newNode(7);
	root->left=newNode(3);
	root->right=newNode(2);
	root->left->right=newNode(6);
	root->left->left=newNode(2);
    root->right->right=newNode(11);
	cout<<"Number of subtrees with specific sum :"<<" "<<countSubtreescheckroot(root, x)<<endl;

	return 0;
}

