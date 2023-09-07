/*Part of Cosmos by OpenGenus Foundation*/

#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void position()
{
    struct node *p,*q;
    int n,gap;
    printf("Enter no of horses:\n");
    scanf("%d",&n);
    printf("Enter gap:\n");
    scanf("%d",&gap);
    p=q=(struct node *)malloc(sizeof(struct node));
    p->data=1;
    for(int i=2;i<=n;i++)
    {
        p->next=malloc(sizeof(struct node));
        p=p->next;
        p->data=i;
    }
    p->next=q;

    for(int i=n;i>1;)
    {
        for(int j=0;j<gap-1;j++)
        {
            p=p->next;
        }
        p->next=p->next->next;
        i--;
    }
    printf("Safe position is: %d\n",p->data);
}

int main()
{
   position();
   return 0;
}
