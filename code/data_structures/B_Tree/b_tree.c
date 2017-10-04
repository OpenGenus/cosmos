/*
 * C Program to Construct a B Tree
 */
 
/***************************
 * binarytree.h
 ***************************/
 
typedef char DATA;
 
struct node
{
	DATA d;
	struct node *left;
	struct node *right;
};
 
typedef struct node NODE;
typedef NODE *BTREE;
 
BTREE newnode(void);
BTREE init_node(DATA d, BTREE p1, BTREE p2);
BTREE create_tree(DATA a[], int i, int size);
void preorder (BTREE root);
void inorder (BTREE root);
void postorder (BTREE root);
 
/**********************
 * binarytree.c:
 ***********************/
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "binarytree.h"
 
BTREE new_node()
{
    return ((BTREE)malloc(sizeof(NODE)));
}
 
BTREE init_node(DATA d1, BTREE p1, BTREE p2)
{
    BTREE t;
 
    t = new_node();
    t->d = d1;
    t->left = p1;
    t->right = p2;
    return t;
}
 
/* create a linked binary tree from an array */
BTREE create_tree(DATA a[], int i, int size)
{
    if (i >= size)
        return NULL;
    else
        return(init_node(a[i],
    create_tree(a, 2*i+1, size),
    create_tree(a, 2*i+2, size)));
}
 
/* preorder traversal */
void preorder (BTREE root)
{
    if (root != NULL) {
        printf("%c ", root->d);
        preorder(root -> left);
        preorder(root -> right);
    }
}
 
/* Inorder traversal */
void inorder (BTREE root)
{
    if (root != NULL) {
        inorder(root -> left);
        printf("%c ", root->d);
        inorder(root -> right);
    }
}
 
/* postorder binary tree traversal */
 
void postorder (BTREE root)
{
    if (root != NULL) {
        postorder(root -> left);
        postorder(root -> right);
        printf("%c ", root->d);
    }
}
 
/***************************
 * pgm.c
 ***************************/
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
 
#include "binarytree.c"
#define ARRAY_SIZE 10
int main(void)
{
    char a[ARRAY_SIZE] = {'g','d','i','b','f','h','j','a','c','e'};
    BTREE root;
 
    root = create_tree(a, 0, ARRAY_SIZE) ;
    assert(root != NULL);
    printf("PREORDER\n");
    preorder(root);
    printf("\n");
    printf("INORDER\n");
    inorder(root);
    printf("\n");
 
    printf("POSTORDER\n");
    postorder(root);
    printf("\n");
}

