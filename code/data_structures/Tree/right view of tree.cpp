#include<iostream>
using namespace std;
 
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
 
struct node* create()
{
    struct node *p;
    int x;
    printf("Enter data(-1 for no data):");
    cin>>x;
    
    if(x==-1)
        return NULL;
    
    p=new node();
    p->data=x;
    
    printf("Enter left child of %d:\n",x);
    p->left=create();
 
    printf("Enter right child of %d:\n",x);
    p->right=create();
    
    return p;
}

void rView(struct node *root,int level,int *mlevel) {
	if(root==NULL) {
		return;
	}
	if(*mlevel < level) {
		cout<<root->data;
		*mlevel = level;
	}
	rView(root->right,level+1,mlevel);
	rView(root->left,level+1,mlevel);
} 
void rightView(struct node *r) {
	int mlevel = 0;
	rView(r,1,&mlevel);
}
 
int main()
{    
    struct node *root = NULL;
    root=create();
    printf("\nThe right view of tree is:\n");
    rightView(root);
    return 0;
}
