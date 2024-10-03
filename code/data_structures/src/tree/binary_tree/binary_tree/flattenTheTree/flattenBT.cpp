
#include<bits/stdc++.h>
using namespace std;

struct bst{

	int data;
	struct bst* left;
	struct bst* right;
};

typedef struct bst node;

void insert(node** root_ref,int x)
{

	if(*root_ref==NULL){
		node* temp=(node*)malloc(sizeof(node));
		temp->data=x;
		temp->left=NULL;
		temp->right=NULL;
		*root_ref=temp;
		 return;
		}
	

	else if(x<(*root_ref)->data)
		insert(&((*root_ref)->left),x);

	else
		insert(&((*root_ref)->right),x);

}

void flatten(node* root){
	if(root==NULL || (root->left==NULL && root->right==NULL))
		return;

	if(root->left!=NULL){
		flatten(root->left);

		node* temp=root->right;
		root->right=root->left;
		root->left=NULL;

		node* t1=root->right;
		while(t1->right!=NULL)
			t1=t1->right;

		t1->right=temp;
	}

	flatten(root->right);
}

void print(node* root){
	while(root!=NULL){
		cout << root->data << endl;
		root=root->right;
	}
}



int main()
{	
	int n,num,i;
	scanf("%d",&n);
	node* root=NULL;

	for(i=0;i<n;i++)
	{
		scanf("%d",&num);
		insert(&root,num);
	}

	flatten(root);

	print(root);


}
