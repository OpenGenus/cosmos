#include<stdio.h>
#include<stdlib.h> 
 
// Part of Cosmos by OpenGenus Foundation
int search(int arr[], int x, int n)
{
    for (int i = 0; i < n; i++)
      if (arr[i] == x)
         return i;
    return -1;
}
 
// Prints postorder traversal from given inorder and preorder traversals
void printPostOrder(int in[], int pre[], int n)
{
   // The first element in pre[] is always root, search it
   // in in[] to find left and right subtrees
   int root = search(in, pre[0], n);
 
   // If left subtree is not empty, print left subtree
   if (root != 0)
      printPostOrder(in, pre+1, root);
 
   // If right subtree is not empty, print right subtree
   if (root != n-1)
      printPostOrder(in+root+1, pre+root+1, n-root-1);
 
   
   printf("%d ",pre[0]);
}
 

int main()
{
   int n;
   printf("Enter the no. of element in the tree");
   printf("\n");
   scanf("%d",&n);
   int in[10000];
   int pre[10000];
   printf("Enter elements of inorder traversal seprated by single space");
   printf("\n");
   for(int x=0;x< n;x++){
   scanf("%d",&in[x]);
   }
   printf("Enter elements of preorder traversal by single space");
   printf("\n");
   for(int x=0;x< n;x++){
   scanf("%d",&pre[x]);
   }
   printf("Postorder traversal ");
   printf("\n");
   printPostOrder(in, pre, n);
   printf("\n");
   return 0;
}
