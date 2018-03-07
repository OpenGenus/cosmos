
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int  info;
    struct node* link;
};
//Function for creating the linked list
struct node* 
create(struct node*  start) 
{
    int proceed = 1;
    struct node* temp, *ptr;
    while(proceed == 1)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->link = NULL;
        puts("Enter info") ;
        scanf("%d", &temp->info);
        if(start == NULL)
        {
            start = temp;
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

    return(start);
}
//Function to check if the list forms a palindrome or not
struct node* 
check(struct node *ptr_bck, struct node *ptr_fwd, int *f)
{
    if(ptr_bck == NULL)
        return(ptr_fwd);
    else
        ptr_fwd = check(ptr_bck->link, ptr_fwd, f);

    if(ptr_bck->info != ptr_fwd->info)
        *f = 0 ;
    
    return(ptr_fwd->link);
}

int 
main(void)
{   
    struct node *start = NULL;
    int flag = 1, *f = &flag;

    start = create(start);
    check(start, start, f);

    if(flag == 1)
        printf("PALINDROME");
    else
        printf("NOT A PALINDROME");
}
