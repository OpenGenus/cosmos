#include <stdio.h>  
   
//Represent a node of the singly linked list  
struct node{  
    int data;  
    struct node *next;  
};      
   
//Represent the head and tail of the singly linked list  
struct node *head, *tail = NULL;  
   
//addNode() will add a new node to the list  
void addNode(int data) {  
    //Create a new node  
    struct node *newNode = (struct node*)malloc(sizeof(struct node));  
    newNode->data = data;  
    newNode->next = NULL;  
      
    //Checks if the list is empty  
    if(head == NULL) {  
        //If list is empty, both head and tail will point to new node  
        head = newNode;  
        tail = newNode;  
    }  
    else {  
        //newNode will be added after tail such that tail's next will point to newNode  
        tail->next = newNode;  
        //newNode will become new tail of the list  
        tail = newNode;  
    }  
}  
   
//reverse() will the reverse the order of the list  
void reverse(struct node *current) {  
    //Checks if list is empty  
    if(head == NULL) {  
        printf("List is empty\n");  
        return;  
    }  
    else{  
        //Checks if the next node is null, if yes then prints it.  
        if(current->next == NULL) {  
            printf("%d ", current->data);  
            return;  
        }  
        //Recursively calls the reverse function  
        reverse(current->next);  
        printf("%d ", current->data);  
    }  
}  
      
//display() will display all the nodes present in the list  
void display() {  
    //Node current will point to head  
    struct node *current = head;  
      
    if(head == NULL) {  
        printf("List is empty\n");  
        return;  
    }  
    while(current != NULL) {  
        //Prints each node by incrementing pointer  
        printf("%d ", current->data);  
        current = current->next;  
    }  
    printf("\n");  
}  
      
int main()  
{  
    //Add nodes to the list  
    addNode(1);  
    addNode(2);  
    addNode(3);  
    addNode(4);  
      
    printf("Original List: \n");  
    display();  
      
    printf("Reversed List: \n");  
    //Print reversed list  
    reverse(head);  
   
    return 0;  
}  
