//Learn O(n)


// The following is O(n^2)
#include<bits/stdc++.h>
#define ll long long
using namespace std;

typedef struct tree node;

struct tree
{
	ll data;
	node * right;
	node * left;
};

node * insert(ll a)
{
	tree * temp = new tree;
	temp->data=a;
	temp->left=temp->right=NULL;
	return temp;
}

//Height including the root
ll height(node * root)
{
	if(root==NULL)
	{
		return 0;
	}
	else return 1 + max(height(root->left),height(root->right));
}

// Diameter ( checking for all nodes)
ll diameter(node * root)
{
	if(root==NULL)
	{
		return 0;
	}
	else return max(1 + height(root->right) + height(root->left),diameter(root->right)+diameter(root->left));
}
	

int main()
{
	//The tree;
	node * root=insert(1);
	//cout<<height(root);
	root->left=insert(3);
	root->left->left=insert(4);
	root->left->right=insert(5);
	root->left->left->right=insert(6);
	root->left->right->right=insert(7);
	
	
	/*tree * root=new tree;
	root=NULL;
	*/
	cout<<diameter(root);	
        return 0;
}

