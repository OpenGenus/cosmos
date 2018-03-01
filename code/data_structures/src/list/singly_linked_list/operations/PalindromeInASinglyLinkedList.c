#include<stdio.h>
#include<stdlib.h>
int count = 0,  flag = 1, *f = &flag;

  struct node
    {
        int  info;
        struct node  *link;
    }*start = NULL, *ptr1 ;

    void create()
    {    int proceed = 1;
        struct  node*temp, *ptr;

        while(proceed == 1)
    {    temp = (struct node *)malloc(sizeof(struct node));
        count++;
        temp->link = NULL;
        puts("Enter info") ;
        scanf("%d", &temp->info);
       if(start == NULL)
        {
        start = temp;
        ptr1 = start;
        ptr = temp;
        }
        else
        {
        ptr->link = temp;
        ptr = temp;
        }
        puts("Want to continue, Press 1");
        scanf("%d", &proceed);
        }
    }

    void check(struct node *ptr)
    {
        if(ptr == NULL)
            return;
        else
            check(ptr->link);

    if(ptr->info != ptr1->info)
        *f = 0 ;
        ptr1 = ptr1->link;
    }

void main()
{   struct node *ptr = start;
    int i = 0;
    create();
    check(start);
    if(flag == 1)
        puts("PALINDROME");
    else
        puts("NOT A PALINDROME");
}
