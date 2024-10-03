#include<bits/stdc++.h>
using namespace std;

int arr[100]={1,2,3,4,5};

struct node
{
	int value;
	node *left,*right;
};

node *version[100];

void build(node *root,int start,int end)
{
	if(start==end)
	{
		root->value=arr[start];
		return ;
	}
	int mid=(start+end)/2;
	root->left=new node;
	root->right=new node;
	root->left->left=NULL,root->left->right=NULL,root->right->left=NULL,root->right->right=NULL;
	build(root->left,start,mid);
	build(root->right,mid+1,end);
	root->value=root->left->value+root->right->value;
}

void upgrade(node *prev,node *cur,int start,int end,int pos,int value)
{
	if(start>pos || end<pos)
		return ;
	if(start==end)
	{
		cur->value=value;
		return ;
	}
	int mid=(start+end)/2;
	if(pos<=mid)
	{
		cur->right=prev->right;
		cur->left=new node;
		cur->left->left=NULL,cur->right->right=NULL;
		upgrade(prev->left,cur->left,start,mid,pos,value);
	}
	else
	{
		cur->left=prev->left;
		cur->right=new node;
		cur->right->right=NULL,cur->right->left=NULL;
		upgrade(prev->right,cur->right,mid+1,end,pos,value);
	}
	cur->value=cur->left->value+cur->right->value;
}

int query(node *root,int start,int end,int low,int high)
{
	if(start>high || end<low )
		return 0;
	if(start>=low && end<=high)
		return root->value;
	int mid=(start+end)/2;
	
	return query(root->left,start,mid,low,high)+query(root->right,mid+1,end,low,high);
}
void display_tree(node *root)
{
	queue<node *> q;
	q.push(root);
	
	while(!q.empty())
	{
		node *temp=q.front();
		q.pop();
		cout<<temp->value<<" ";
		if(temp->left!=NULL)
			q.push(temp->left);
		if(temp->right!=NULL)
			q.push(temp->right);
	}
	cout<<endl;

}

int main()
{
	node *root=new node;
	root->left=NULL;
	root->right=NULL;
	build(root,0,4);
	display_tree(root);	
	version[0]=root;
	version[1]=new node;
	version[1]->left=NULL;
	version[1]->right=NULL;
	upgrade(version[0],version[1],0,4,4,1);
	display_tree(version[1]);
	display_tree(version[0]);	

	cout << query(version[1], 0, 4, 0, 4) << endl;
	cout << query(version[0], 0, 4, 0, 3) << endl;
}