/* Doubly Linked List implementation */
#include<stdio.h>
#include<stdlib.h>

struct Node  {
	int data;
	struct Node* next;
	struct Node* prev;
};

struct Node* head; // global variable - pointer to head node.

//Creates a new Node and returns pointer to it.
struct Node* GetNewNode(int x) {
	struct Node* newNode
		= (struct Node*)malloc(sizeof(struct Node));
	newNode->data = x;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}

//Inserts a Node at head of doubly linked list
void InsertAtHead(int x) {
	struct Node* newNode = GetNewNode(x);
	if(head == NULL) {
		head = newNode;
		return;
	}
	head->prev = newNode;
	newNode->next = head;
	head = newNode;
}

//Inserts a Node at tail of Doubly linked list
void InsertAtTail(int x) {
	struct Node* temp = head;
	struct Node* newNode = GetNewNode(x);
	if(head == NULL) {
		head = newNode;
		return;
	}
	while(temp->next != NULL) temp = temp->next; // Go To last Node
	temp->next = newNode;
	newNode->prev = temp;
}

//Prints all the elements in linked list in forward traversal order
void Print() {
	struct Node* temp = head;
	printf("Forward: ");
	while(temp != NULL) {
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

//Prints all elements in linked list in reverse traversal order.
void ReversePrint() {
	struct Node* temp = head;
	if(temp == NULL) return; // empty list, exit
	// Going to last Node
	while(temp->next != NULL) {
		temp = temp->next;
	}
	// Traversing backward using prev pointer
	printf("Reverse: ");
	while(temp != NULL) {
		printf("%d ",temp->data);
		temp = temp->prev;
	}
	printf("\n");
}

int main() {

	/*Driver code to test the implementation*/
	head = NULL; // empty list. set head as NULL.

  while (1)
  {
      int m, p;
      int systemRet = system("cls");
      if(systemRet == -1)  //To check the return value of system("cls")
      {
         printf("The system method failed\n");
      }
      printf( "1.InsertAtHead \n"
              "2.InsertAtTail \n"
              "3.Print \n"
              "4.Reverse Print \n"
              "5.Exit \n" );
      int i = scanf("%d",&m);
      if(i != 1)  //To check the return value of scanf
      {
        printf("scanf failed\n");
      }
      switch (m)
      {
      case 1:
          printf("Enter info \n");
          i = scanf("%d",&p);
          if(i != 1)  //To check the return value of scanf
          {
            printf("scanf failed\n");
          }
          InsertAtHead(p); //Insertion At Head
          break;
      case 2:
          printf("Enter info \n");
          i = scanf("%d",&p);
          if(i != 1)  //To check the return value of scanf
          {
            printf("scanf failed\n");
          }
          InsertAtTail(p); //Insertion At Tail
          break;
      case 3:
          Print(); //To Print the List
          break;
      case 4:
          ReversePrint(); // To Print the List in Reverse order
          break;
      case 5:
          exit(0); // To Exit
      default:
          printf("Invalid choice!\n");
      }
      int systemRet1 = system("pause");
      if(systemRet1 == -1)  //To check the return value of system("pause")
      {
         printf("The system method failed\n");
      }
  }

}
