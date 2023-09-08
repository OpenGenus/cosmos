//Author: Praveen Gupta
// Part of Cosmos by OpenGenus Foundation
#include<stdio.h>
#include<stdlib.h>

//Defining Node
typedef struct node{
	int data;
	struct node *left;
	struct node *right;

}node;

//Creates a new Node
node *newNode(int data){
	node *temp=(node *)malloc(sizeof(node));
	temp->data=data;
	temp->left=temp->right=NULL;

	return temp;
}

//Adds the new node to the appropriate position
node *create(node *head,int data){

	if (head==NULL){
		head = newNode(data);
	}
	else if(data<=head->data){
		head->left = create(head->left,data);
	}
	else{
		head->right = create(head->right,data);
	}
	return head;
}

//Prints tree
void print(node *head){
	if(head==NULL)
	{
		return;
	}
	printf("%d(",head->data );
	print(head->left);
	printf(" , ");
	print(head->right);
	printf(")");
}

//Searches for an element in the tree
int search(node *head, int data){
	if(head==NULL)
		return 0;
	if(head->data==data)
		return 1;
	if(data<head->data)
		return search(head->left, data);
	else
		return search(head->right, data);
}

//Deletes a subtree with root as the parameter
node *deleteTree(node *head){
	if(head==NULL)
		return NULL;

	deleteTree(head->left);
	deleteTree(head->right);
	free(head);
	return NULL;
}

//Deletes the node and its children's
node *delete(node *head, int data){
	if(head==NULL){
		printf("Nor found\n");		
	}

	if(head->data==data){
		head = deleteTree(head);
	}
	
	else if(data<head->data)
		head->left = delete(head->left, data);
	
	else
		head->right = delete(head->right, data);

	return head;
}
//Finds the height of the tree
int height(node *head) 
{
   if (head==NULL) 
       return 0;
   else
   {
       /* compute the depth of each subtree */
       int left_height = height(head->left);
       int right_height = height(head->right);
 
       /* use the larger one */
       if (left_height > right_height) 
           return(left_height+1);
       else return(right_height+1);
   }
} 
int main(){
node *head=NULL;

	printf("Binary Search Tree\n");
	int c,data;

	again:
	printf("\n1. Insert Node         2. Delete Node		  3.Search		4.Find height\n");
	scanf("%d",&c);

	switch(c){
		case 1:	printf("Enter data\n");
				scanf("%d",&data);
				head=create(head,data);
				break;

		case 2:	printf("Enter data to delete\n");
				scanf("%d",&data);
				head = delete(head,data);
				break;		

		case 3: printf("Enter data to search\n");
				scanf("%d",&data);
				search(head,data) ? printf("Found in tree\n"):printf("Not Found in tree\n");
		case 4: printf("The height of BST is: %d ",height(head));
	}
	print(head);
	goto again;
return 0;
}
