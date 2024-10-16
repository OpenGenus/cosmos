#include <stdlib.h>
#include <stdio.h>

typedef struct btree {
	int data;
	struct btree *left;
	struct btree *right;
}btree;

btree *makeTree(int *in , int *post , int start , int end , int *index) {
	if (start > end) return NULL;

	btree *nn = (btree*)malloc(sizeof(btree));
	nn -> data = post[*index];
	int i;
	for (i = start;i <= end;i++) {
		if (post[*index] == in[i]) break;
	}
	(*index)--;
	nn -> right = makeTree(in, post, i+1, end, index);
	nn -> left = makeTree(in, post, start, i-1, index);
	return nn;
}

void printPostOrderTree(btree *root) {
	if(root == NULL) return;
	printPostOrderTree(root -> left);
	printPostOrderTree(root -> right);
	printf("%d ",root -> data);
}

int main()
{
	int post[] = {4,5,2,6,7,3,1};
	int in[] = {4,2,5,1,6,3,7};
	int index = 6;
	btree *root = makeTree (in, post, 0, 6, &index);

	printPostOrderTree(root);
	return 0;
}
