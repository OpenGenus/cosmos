#include<iostream>
#include<queue>
using namespace std;

struct node
{
	int data;
	node* left;
	node* right;	
};

node* insertNode(int data)
{
	node* temp=new node;
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

void leftView(node* root)
{
	if(root==NULL)
	return;
	queue<node*> q;
	q.push(root);
	while(1)
	{
		int nodeCount=q.size();
		if(nodeCount==0)
		break;
		bool first_element=true;
		while(nodeCount--)
		{
			node* root=q.front();
			q.pop();
			if(first_element)
			{
				printf("%d ",root->data);
				first_element=false;
			}
			if(root->left!=NULL)
			q.push(root->left);
			if(root->right!=NULL)
			q.push(root->right);
		}
	}
}

int main()
{
	node* root=insertNode(1);
	root->left=insertNode(2);
	root->right=insertNode(3);
	root->right->left=insertNode(8);
	root->right->right=insertNode(9);
	root->right->right->left=insertNode(10);
	root->left->left=insertNode(4);
	root->left->right=insertNode(5);
	root->left->left->left=insertNode(6);
	root->left->right->right=insertNode(7);
	leftView(root);
	return 0;	
}
