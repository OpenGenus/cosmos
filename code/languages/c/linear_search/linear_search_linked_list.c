    #include <stdio.h>
    #include <stdlib.h>
    /*
    Input : integer linked list , key to be searched
    Ouput : Position of the key in the linked list if found, else -1
    */
    struct node {
    int data;
    struct node *nptr; // next pointer
    };

    struct node *hptr = NULL; // head pointer

    void insert(int pos, int x) {
    struct node *temp = malloc(sizeof(struct node));
    if (temp == NULL)
        printf("Insertion not possible\n");
    temp->data = x; // storing the value in data field
    if (pos == 1) {
        temp->nptr = hptr;
        hptr = temp;
    } else {
        int i = 1;
        struct node *thptr = hptr; // temporary pointer
        while (i < pos - 1) {
        thptr = thptr->nptr; // traversing to the position of insertion
        i++;
        }
        temp->nptr = thptr->nptr;
        thptr->nptr = temp;
    }
    }

    void print() {
    struct node *temp = hptr;
    printf("Linked List contains : \n");
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->nptr;
    }
    }

    int linearSearch(int key) {
    struct node *temp = hptr;
    int i = 1;
    while (temp != NULL) {
        if (temp->data == key)
        return i;
        i++;
        temp = temp->nptr;
    }
    return -1;
    }

    int main() {
    insert(1, 11);
    insert(2, 13);
    insert(3, 12);
    insert(4, 14);
    insert(5, 6);
    insert(6, 10);
    print();
    printf("Position of the key is : %d\n", linearSearch(6));
    return 0;
    }

    /*Output
    Linked List contains :
    11
    13
    12
    14
    6
    10
    Position of the key is : 5
    */
