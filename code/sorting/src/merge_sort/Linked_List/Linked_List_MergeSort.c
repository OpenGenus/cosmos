/*This code is for sorting the linked list using Divide and conquer technique*/

#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

/*Merging the contents of the two linked list*/
struct Node *merge(struct Node *l1, struct Node *l2)
{
    if(!l1)
        return l2;
    
    if(!l2)
        return l1;

    struct Node *head=NULL;
    
    if(l1->data<l2->data)
    {
        head=l1;
        l1=l1->next;
    }
    else
    {
        head=l2;
        l2=l2->next;
    }
    
    struct Node *ptr=head;
    
    while(l1 && l2)
    {
        if(l1->data<l2->data)
        {
            ptr->next=l1;
            l1=l1->next;
        }
        else
        {
            ptr->next=l2;
            l2=l2->next;
        }
        ptr=ptr->next;
    }
    
    if(l1)
        ptr->next=l1;
    else
        ptr->next=l2;
    
    return head;
}

/*Dividing the linked list*/
struct Node* mergeSort(struct Node* head) {
    
    if(head==NULL || head->next==NULL)
        return head;
        
    /*Dividing the linked list into two equal parts as done in merge sort*/
    struct Node *ptr1=head;
    struct Node *ptr2=head->next;
    
    while(ptr2 && ptr2->next)
    {
        ptr1=ptr1->next;
        if(ptr2->next)
            ptr2=ptr2->next->next;
    }
    
    ptr2 = ptr1->next;
    ptr1->next = NULL;
    
    return merge(mergeSort(head),mergeSort(ptr2));
}


void printList(struct Node* head) {

    while (head != NULL) {
        printf("%d-->", head->data);
        head = head->next;
    }

    printf("NULL");
}

/*
Sample Input
1 - Test cases
5 - Total number of elements to be inserted in linked list
23 2 34 5 1 - Adding the contents of the linked list

Sample Output
1 2 5 23 34
*/


int main() 
{
    int test,n,ele;
    scanf("%d", &test);

    /* Inserting elements into linked list*/
    while (test--) 
    {
        struct Node* head = NULL;
        struct Node *temp = NULL;
        scanf("%d", &n);

        while(n--)
        {
            scanf("%d", &ele);

            struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
            ptr->data = ele;
            ptr->next = NULL;

            if(head==NULL)
                head = ptr;
            else
                temp->next = ptr;

            temp = ptr;
        }

        head = mergeSort(head);
        printList(head);
    }
    return 0;
}
