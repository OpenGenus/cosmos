#include <stdio.h>
#include <stdlib.h>

typedef struct node {
			int value;
                        int left_flag;
			struct node *left, *right;
		    }node;

static node* root = NULL;
node* create_node(int val)
{
        node* tmp = (node *) malloc(sizeof(node));
        tmp->value = val;
        tmp->left_flag = 0;
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
                  tmp->left->left_flag=1;
                  break;
                }
                else
                  tmp = tmp->left;
             }
           }
        }

}

int sum_left_leaves(node* tmp)
{
  static int sum = 0;
  if(tmp) 
  {
     if (!tmp->left && !tmp->right && tmp->left_flag)
       sum+=tmp->value;
     sum_left_leaves(tmp->left);
     sum_left_leaves(tmp->right);
  }
  return sum;
}

int main()
{
  int ctr, sum, num_nodes, value,min_depth;
  printf("Enter number of nodes\n");
  scanf("%d",&num_nodes);
  for (ctr = 0; ctr < num_nodes; ctr++)
  {
     printf("Enter values\n");
     scanf("%d",&value);
     create_tree(value);
  }
  sum = sum_left_leaves(root);
  printf("sum = %d\n",sum);
}



