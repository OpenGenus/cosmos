#include<stdio.h>
#include<malloc.h>
//make node of tree
struct node {
	int data;
	struct node* right;
	struct node* left;
};
//it creates the binary tree
struct node* binary_tree(int d,struct node *root) {
	if(root==NULL) {
		struct node *nn = (struct node*)malloc(sizeof(struct node));
		nn->left = NULL;
		nn->right = NULL;
		nn->data = d;
		return nn;
	}
	if(d>root->data)
		root->right = binary_tree(d,root->right);
	else if(d<root->data)
		root->left = binary_tree(d,root->left);
	return root;
}

void printLeft(struct node *root) {
    if(root) {
        printLeft(root->left);
        printf("%d ",root->data);
    }
}
void topView(struct node *root) {        //To print the top view of a tree
	printLeft(root->left);        //calls the printLeft function to print left node of a tree
    while(root!=NULL) {
        printf("%d ",root->data);    // prints the data
        root = root->right;
    }
}

int main() {
	struct node *root = NULL;
	int n,num;
	printf("Enter the number of node:");
	scanf("%d",&n);
	int i=0;
	for(i=0;i<n;i++) {
		scanf("%d",&num);
		root = binary_tree(num,root);
	}
	printf("Output:\n");
	topView(root);
}
