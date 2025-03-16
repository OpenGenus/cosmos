#include<stdio.h>
#include<stdlib.h>

struct node
{
 int data;
 struct node *r, *l;
}*root=NULL;
struct node *insert()
{
        struct node *p;
        int x;
        printf("Enter the data(-1 to stop):"); 	//If there are no child to the node you entered before press -1
        scanf("%d",&x);
        p=(struct node*) malloc(sizeof(struct node));
        if(x==-1)
        {
     p=NULL;
                return p;
        }

        p->data=x;
        printf("\nEnter the left child\n");
        p->l=insert();

        printf("\nEnter the right child\n");
        p->r=insert();
       
return p;

}


display(struct node *p)
{
 if(p!=NULL)
   {
        display(p->l);
        printf("%d\t",p->data);
        display(p->r);
   }
}
main()
{
       root=insert();
        printf("Inorder Tree\n");
        display(root);
printf("\n");
}

/*
 * Input 
 *  3 4 5 -1 -1 -1 2 -1 8 6 -1 -1 -1
 *  Tree
 *  		3
 *  	      /	  \
 *  	     4	   2
 *  	    / 	    \
 *  	   5	     8
 *  	   	    /
 *  	   	   6
 *
 *
 * Output
 * Inorder tree
 * 5  4  3  2  6  8
 *
 */

                                        

