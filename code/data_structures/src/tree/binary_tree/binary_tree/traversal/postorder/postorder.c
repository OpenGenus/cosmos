#include <stdio.h>
#include <stdlib.h>
/* Part of Cosmos by OpenGenus Foundation */
struct node
{
	int data;
	struct node *left;
	struct node *right;
};

struct node *newnode(int data)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

/*Function for POSTORDER Transversal*/
void
postorder(struct node *root)
{
	if (root == NULL)
		return;
	
	postorder(root->left);
	postorder(root->right);
	printf("%d ", root->data);
}

int 
main()
{
	struct node *root;
	root = newnode(1);
	root->left = newnode(2);
	root->right = newnode(3);
	root->left->left = newnode(4);
	root->left->right = newnode(5);
	root->right->left = newnode(6);
    root->right->right = newnode(7);

	printf("Post order traversal of tree is: ");
	postorder(root);

	return 0;
}
