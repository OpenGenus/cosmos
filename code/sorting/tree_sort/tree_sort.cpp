//Tree Sort implemented using C++
#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	struct Node *left,*right;
};
//Function to create new Node
struct Node *newnode(int key)
{
	struct Node *temp=new Node;
	temp->data=key;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

Node* insert(Node *node,int key)
{
	if(node==NULL) return newnode(key);//If tree is empty return new node
	if(key < node->data)
	  node->left=insert(node->left,key);
	else
	  node->right=insert(node->right,key);
	return node;
}
void store(Node *root,int a[],int &i)
{
	if(root!=NULL)
	{
		store(root->left,a,i);
		a[i++]=root->data;
		store(root->right,a,i);
	}
}
void TreeSort(int a[], int n)
{
    struct Node *root = NULL;
 
    //Construct binary search tree
    root = insert(root, a[0]);
    for (int i=1; i<n; i++)
        insert(root, a[i]);
 
    //Sorting the array using inorder traversal on BST
    int i = 0;
    store(root, a , i);
}

int main()
{
    
    int a[] = {1,6,8,3,10,2,12};
    int n = sizeof(a)/sizeof(a[0]);
 
    TreeSort(a,n);
    
    cout<<"The sorted array is :\n";
    //Printing the sorted array
    for(int i=0;i<n;i++)
    {
    	cout<<a[i]<<" ";
    }
 
    return 0;
}

/* output:
The sorted array is :
1 2 3 6 8 10 12
*/
