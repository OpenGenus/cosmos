#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct node {
			int value;
			struct node *left, *right;
	}node;

node* create_node(int );
void create_tree(int );
void cleanup_tree(node* );
int maximum(int , int );
int height_tree(node* );
int diameter_tree(node* );

node* root = NULL;
node* create_node(int val)
{
	node* tmp = (node *) malloc(sizeof(node));
	tmp->value = val;
	tmp->left = tmp->right = NULL;
	return tmp;
}

void create_tree(int val)
{
	node* tmp = root;
	if (!root)
	  root = create_node(val);
	else
        {
           while (1)
	   {
	     if (val > tmp->value)
             {
                if (!tmp->right)
                {
		  tmp->right = create_node(val);
                  break;
                }
                else
                  tmp = tmp->right;
             }
	     else
             {
                if (!tmp->left)
                {
		  tmp->left= create_node(val);
                  break;
                }
                else
                  tmp = tmp->left;
             }	
	   }
	}
	
}

 int maximum(int left_ht, int right_ht)
 {
   return (left_ht > right_ht ? left_ht : right_ht);
 }

int height_tree(node* tmp)
{
    int left_ht, right_ht;
    if (!tmp)
      return 0;
    left_ht = height_tree(tmp->left);
    right_ht = height_tree(tmp->right);
    return 1+maximum(left_ht, right_ht);
}

//Prints the longest path between the leaf nodes
int diameter_tree(node* tmp)
{
   int leaf_depth, left_subtree_height, right_subtree_height, max_depth_between_left_and_right_subtree;
   if (!tmp)
     return 0;
   leaf_depth = height_tree(tmp->left) + height_tree(tmp->right);
   left_subtree_height = diameter_tree(tmp->left);
   right_subtree_height = diameter_tree(tmp->right);
   max_depth_between_left_and_right_subtree =  maximum(left_subtree_height, right_subtree_height);
   return maximum(leaf_depth, max_depth_between_left_and_right_subtree);
}

void cleanup_tree(node* tmp)
{
    if (tmp)
    {
	cleanup_tree(tmp->left);
	cleanup_tree(tmp->right);
        if (tmp->left)
        {
          free(tmp->left);
 	  tmp->left = NULL;
        }
        if (tmp->right)
        {
          free(tmp->right);
 	  tmp->right= NULL;
        }
    }
    if (tmp == root)
    {
      free(root);
      root = NULL;
    }
}


int main()
{
        int val, num, ctr,longest_path_between_leaf_nodes;
        node tmp;
	printf("Enter number of nodes\n");
        scanf("%d",&num);
        for (ctr = 0; ctr < num; ctr++)
        {
	  printf("Enter values\n");
	  scanf("%d",&val);
	  create_tree(val);
        }
        longest_path_between_leaf_nodes  = diameter_tree(root);
        printf("diameter_tree = %d\n",longest_path_between_leaf_nodes);
        cleanup_tree(root);
        return 0; 
}
