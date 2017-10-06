#include <stdio.h>
#include <stdlib.h>
// Part of Cosmos by OpenGenus Foundation
typedef struct node {
			int value;
			struct node *left, *right;
		    }node;

static node* root = NULL;
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

int min(int left_ht, int right_ht)
{
  return (left_ht < right_ht ? left_ht : right_ht);
}

int min_depth_tree(node* tmp)
{
        if (!tmp)
          return 0;
        if (!tmp->left && !tmp->right)
          return 1;
        if (!tmp->left) 
          return min_depth_tree(tmp->right)+1;
        if (!tmp->right) 
          return min_depth_tree(tmp->left)+1;

        return min(min_depth_tree(tmp->left),min_depth_tree(tmp->right))+1;
}

int main()
{
  int ctr, num_nodes, value,min_depth;
  printf("Enter number of nodes\n");
  scanf("%d",&num_nodes);
  for (ctr = 0; ctr < num_nodes; ctr++)
  {
     printf("Enter values\n");
     scanf("%d",&value);
     create_tree(value);
  }
  min_depth = min_depth_tree(root);
  printf("minimum depth = %d\n",min_depth);
}



