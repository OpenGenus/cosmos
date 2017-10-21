#include<iostream>
#include<queue>
#include<map>
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

void bottomView(node* root)
{
	if(root==NULL)
	return;
	map<int,int> m;
	queue<pair<node*,int> > q;
	q.push(make_pair(root,0));
	while(!q.empty())
	{
		pair<node*,int> temp=q.front();
		q.pop();
		node* root=temp.first;
		int val=temp.second;
		m[val]=root->data;
		if(root->left!=NULL)
		q.push(make_pair(root->left,val-1));
		if(root->right!=NULL)
		q.push(make_pair(root->right,val+1));	
	}
	map<int,int> :: iterator it;
	for(it=m.begin();it!=m.end();it++)
	printf("%d ",m[it->first]);
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
	bottomView(root);
	return 0;	
}
