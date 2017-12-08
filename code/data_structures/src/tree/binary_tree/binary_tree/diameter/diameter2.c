#include <stdio.h>
#include <stdlib.h>

#define MAX(x, y) (((x) > (y)) ? (x) : (y))

typedef struct node{
    int data;   
    struct node *left;
   struct node *right;
}node;

node* newnode(int d){
    node* temp = (node*)malloc(sizeof(node));
    temp->data = d;
    temp->left = NULL;
    temp->right = NULL;
}

node *buildTree(){
    int d;
    printf("\nEnter data:");
    scanf("%d", &d);

    if(d==-1){
        return NULL;
    }

    ///rec case
    node *n =newnode(d);
    n->left = buildTree();
    n->right = buildTree();
    return n;
}

int height(node *root){
    if(root==NULL){
        return 0;
    }

    return (MAX./(height(root->left),height(root->right))+1);
}

int diameter(node*root){
    if(root==NULL){
        return 0;
    }

    int cp1 = height(root->left) + height(root->right);
    int cp2 = diameter(root->left);
    int cp3 = diameter(root->right);

    return MAX(cp1,MAX(cp2,cp3));
}

int main(){

    node *root = NULL;
    root = buildTree();
    printf("\nDiameter of Binary Tree: ");
    printf("%d", diameter(root));
    

    return 0;
}
