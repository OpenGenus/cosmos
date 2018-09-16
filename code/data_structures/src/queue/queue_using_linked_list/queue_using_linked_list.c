#include <stdio.h>
#include <stdlib.h>

/* @author AaronDills
   An implementation of a queue data structure
   using C and Linked Lists*/

/* Structure for a Node containing an integer value and reference to another Node*/
struct Node {
  int value;
  struct Node *next;

};

/* Initalize global Nodes for the head and tail of the queue */
struct Node* head = NULL;
struct Node* tail = NULL;

/* Function declarations */
struct Node* createNode();
void enqueue();
void dequeue();
void printQueue();

int main(){
  int choice = 0;
  while(1){
    printf("1.Insert element to queue \n");
    printf("2.Delete element from queue \n");
    printf("3.Display all elements of queue \n");
    printf("4.Quit \n");
    printf("Please make a selection:");
    scanf("%d", &choice);
    switch(choice){
      case 1:
        enqueue();
        break;
      case 2:
        dequeue();
        break;
      case 3:
        printQueue();
        break;
      case 4:
        exit(0);
      default:
        printf("Please enter a valid input\n");
    }
  }

}

/* Creates a Node object with a value provided from user input */
struct Node* createNode(){
  int userValue;
  printf("Enter the value you want to add: ");
  scanf("%d", &userValue);

  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->value = userValue;
  newNode->next = NULL;

  return newNode;
}


/* Add a Node to the end of the queue */
void enqueue(){

  if(head == NULL && tail == NULL){
      head = tail = createNode();
  }else{
      tail-> next = createNode();
      tail = tail->next;
  }
}

/* Remove front Node from queue */
void dequeue(){
    struct Node* current = head;
    if(current == NULL){
      printf("The queue is empty\n");
    }
    if(current == tail){
      head = NULL;
      tail = NULL;
    }
    else{
      head = head->next;
    }
    free(current);
}

/* Iterate through queue and print Node values*/
void printQueue(){
  struct Node* temp = head;
  while(temp != NULL){
    printf("%d ", temp->value);
    temp = temp->next;
  }
  printf("\n");
}
