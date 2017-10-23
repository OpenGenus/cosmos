#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

int del(struct node** head,int* element);
int add(struct node** head,int element);

//main program
int main()
{
    //input no of nodes: Num
    int Num;
    printf("Enter number of nodes\n");
    scanf("%d",&Num);

    //create adjacency matrix
    int adj[Num][Num];

    //input adjacency matrix
    printf("Enter adjacency matrix\n");
    for(int i=0;i<Num;i++)
    {
        for(int j=0;j<Num;j++)
        {
            scanf("%d",&adj[i][j]);
        }
    }

    //BFS traversing

    //create a queue
    struct node *Queue=NULL;

    //create status array and set it to ready state
    enum{ready,waiting,processed};
    int status[Num];
    for(int i=0;i<Num;i++)
    {
        status[i]=ready;
    }
    //add first node to queue
    add(&Queue,0);
    status[0]=waiting;
    int node=NULL;
    printf("BFS traversing\n");
    while(Queue!=NULL)
    {
        //get a node from queue, display it and change status to processed
        del(&Queue,&node);
        printf("%d ",node);
        status[node]=processed;

        //add it's neighbours with status ready to queue
        for(int i=0;i<Num;i++)
        {
            if(adj[node][i]==1 && status[i]==ready)
            {
                add(&Queue,i);
                status[i]=waiting;
            }
        }
    }
    printf("\n");

}

//queue functions
int del(struct node** head,int* element)
{
    if(*head==NULL)
        return 1;
    *element=(*head)->data;
    struct node* temp;
    temp=*head;
    *head=(*head)->next;
    free(temp);
    return 0;
}

int add(struct node** head,int element)
{
    if((*head)==NULL)
    {
        *head=(struct node*)malloc(sizeof(struct node));
        (*head)->next=NULL;
        (*head)->data=element;
        return 0;
    }
    struct node* temp=*head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=(struct node*)malloc(sizeof(struct node));
    if(temp->next==NULL)
        return 1;
    temp=temp->next;
    temp->data=element;
    temp->next=NULL;
    return 0;
}
