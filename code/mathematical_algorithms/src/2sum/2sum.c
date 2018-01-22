/*
 * Given an array and a sum, returns two numbers from the array that add-up to sum.
 * Part of Cosmos by OpenGenus Foundation.
 * Author : ABDOUS Kamel
 */

#include <stdio.h>
#include <stdlib.h>

int 
max(int a, int b)
{
	if (a <= b)
		return (b);

	else 
		return (a);
}

/* -------------------------------------- AVL TREE --------------------------------------------------- */
/* This code was taken from cosmos/code/data_structures/avl_tree/AVL_tree.cpp and adapted to work in C */
typedef struct AVLNode  
{
   	int data;
    struct AVLNode* left;
    struct AVLNode* right;
    int height;

} AVLNode;

// helper function to return height of a node
int getHeight(AVLNode* node)    
{
    if(node){
        return node->height;
    }
    
    return -1;
}

// LL rotation rooted at X
AVLNode* LL_rotation(AVLNode* X)    
{
    AVLNode* W = X->left;
    X->left = W->right;
    W->right = X;
    X->height = max(getHeight(X->left), getHeight(X->right)) + 1;
    W->height = max(getHeight(W->left), getHeight(X)) + 1;
    return W;   //new root
}

// RR rotation rooted at X
AVLNode* RR_rotation(AVLNode* X)    
{
    AVLNode* W = X->right;
    X->right = W->left;
    W->left = X;
    X->height = max(getHeight(X->left), getHeight(X->right)) + 1;
    W->height = max(getHeight(X), getHeight(W->right));
    return W;   //new root
}

// LR rotation rooted at X
AVLNode* LR_rotation(AVLNode* X)  
{
    X->left = RR_rotation(X->left);
    return LL_rotation(X);
}

// RL rotation rooted at X
AVLNode* RL_rotation(AVLNode* X)   
{
    X->right = LL_rotation(X->right);
    return RR_rotation(X);
}

int AVLFind(AVLNode* root, int data)
{
	while(root != NULL)
	{
		if(root->data == data)
			return 1;

		else if(root->data < data)
			root = root->right;

		else 
			root = root->left;
	}

	return 0;
}

// function to insert a node into the AVL tree
AVLNode* insertIntoAVL(AVLNode* root, int data)  
{
    if(root == NULL) {
        AVLNode* newNode = (AVLNode*)(malloc(sizeof(*newNode)));
        newNode->data = data;
        newNode->height = 0;
        newNode->left = newNode->right = NULL;
        root = newNode;
    }
    else if(data < root->data) {
        root->left = insertIntoAVL(root->left, data);
        if(getHeight(root->left) - getHeight(root->right) == 2) 
        {
            if(data < root->left->data)
                root = LL_rotation(root);
            else
                root = LR_rotation(root);
        }
    }
    else if(data > root->data) {
        root->right = insertIntoAVL(root->right, data);

        if(getHeight(root->right) - getHeight(root->left) == 2) 
        {
            if(data > root->right->data)
                root = RR_rotation(root);
            else
                root = RL_rotation(root);
        }
    }
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    return root;
}

// function to free allocated memory
void deleteTree(AVLNode *root) 
{
    if(root == NULL)
        return;

    deleteTree(root->left);
    deleteTree(root->right);
    
    free(root);
}

/* ----------------------------------------END OF AVL TREE ------------------------------------------------ */

int 
twoSum(int array[], int size, int sum, int* a, int* b)
{
	int i;

    AVLNode* map = (AVLNode*)(malloc(sizeof(*map)));
    map->data = array[0];
    map->height = 0;
    map->left = map->right = NULL;

	for (i = 1; i < size; ++i) {
		if (AVLFind(map, sum - array[i])) {
			*a = array[i];
			*b = sum - array[i];

			deleteTree(map);
			return (0);
		}

		else
			map = insertIntoAVL(map, array[i]);
	}

	deleteTree(map);
	return (-1);
}

int 
main()
{
    int a[] = {1, 2, 3, 3, 5, 6};
    int b, c;

    twoSum(a, 6, 9, &b, &c);
    printf("%d %d\n",  b, c);
	
	return (0);
}
