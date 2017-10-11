#include <stdio.h>
#include <stdlib.h>

typedef struct a {
    int val;
    struct a *next;
} node;

void insert(node **list, int val){
    node *first = NULL, *temp = NULL;
    node *aux;

    aux = (node *)malloc(sizeof(node));

    aux->val = val;
    aux->next = aux;

    if ((*list)!=NULL){
        aux->next = (*list);

        temp = (*list);

        while (temp->next != (*list)) temp = temp->next;

        temp->next = aux;

        printf ("\nElement %d inserted\n\n",temp->next->val);
    } else {
        (*list) = aux;
        printf ("\nElement %d inserted\n\n",(*list)->val);
    }
}

void show(node *list){
    node *temp = NULL;

    printf ("\n");

    if (list!= NULL){
        temp = list;
        do {
            printf ("%d\t",temp->val);
            temp = temp->next;
        } while (temp!=list);
        printf ("-> %d",temp->val);
        printf ("\n\n");
    } else printf ("The list is empty\n\n");
}

void freeAll (node **list){
    node *first = (*list);
    node *temp;
    if ((*list)!=NULL){
        do{
            temp = (*list);
            (*list) = (*list)->next;
            free(temp);
        } while ((*list)!=first);
    }
}

int menu(){
    int op;

    printf ("1- Insert\n2- Show List\n0- Exit\nSelect the operation: ");
    scanf ("%d",&op);
    return op;
}

int main(){
    node *list = NULL;
    int op,val;

    do {
        op = menu();

        switch (op){
            case 1:
                printf ("Write the element to be inserted: ");
                scanf ("%d",&val);

                insert (&list,val);
            break;
            case 2:
                show(list);
            break;
            case 0:
                freeAll(&list);
                printf ("\nGood Bye!\n");
            break;
        }
    } while (op);

    return (0);
}
