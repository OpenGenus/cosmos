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
void mirror_image(node* );

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

void mirror_image(node* tmp)
{
   node* tmp1 = NULL;
   if (tmp)
   {
     tmp1 = tmp->left;
     tmp->left = tmp->right;
     tmp->right = tmp1;
     mirror_image(tmp->left);
     mirror_image(tmp->right);
   }
}

void print_mirror_image(node* tmp)
{
   if (tmp)
   {
     printf("%d\n",tmp->value);
     print_mirror_image(tmp->left);
     print_mirror_image(tmp->right);
   }
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
        int val, num, ctr;
        node tmp;
	printf("Enter number of nodes\n");
        scanf("%d",&num);
        for (ctr = 0; ctr < num; ctr++)
        {
	  printf("Enter values\n");
	  scanf("%d",&val);
	  create_tree(val);
        }
     	mirror_image(root);
        print_mirror_image(root);
        cleanup_tree(root);
        return 0; 
}
