Reversing a doubly linked list is an important operation. In this, we simply swap the previous and next pointers of all the nodes and also swap the head and tail pointers.

#include <iostream>
using namespace std;
//node declaration for doubly linked list
struct Node {
   int data;
   struct Node *prev, *next;
};
  
Node* newNode(int val)
{
   Node* temp = new Node;
   temp->data = val;
   temp->prev = temp->next = nullptr;
   return temp;
}
void displayList(Node* head)
{
   while (head->next != nullptr) {
      cout << head->data << " <==> ";
      head = head->next;
      }
   cout << head->data << endl;
}
  
// Insert a new node at the head of the list
void insert(Node** head, int node_data)
{
   Node* temp = newNode(node_data);
   temp->next = *head;
   (*head)->prev = temp;
   (*head) = temp;
}
  
// reverse the doubly linked list
void reverseList(Node** head)
{
   Node* left = *head, * right = *head;
  
   // traverse entire list and set right next to right
   while (right->next != nullptr)
   right = right->next;
  
   //swap left and right data by moving them towards each other till they meet or cross
   while (left != right && left->prev != right) {
  
      // Swap left and right pointer data
      swap(left->data, right->data);
  
      // Advance left pointer
      left = left->next;
  
      // Advance right pointer
      right = right->prev;
   }
}
int main()
{
   Node* headNode = newNode(5);
   insert(&headNode, 4);
   insert(&headNode, 3);
   insert(&headNode, 2);
   insert(&headNode, 1);
   cout << "Original doubly linked list: " << endl;
   displayList(headNode);
   cout << "Reverse doubly linked list: " << endl;
   reverseList(&headNode);
   displayList(headNode);
  
   return 0;
}

Original doubly linked list:

1 <==> 2 <==> 3 <==> 4 <==> 5

Reverse doubly linked list:

5 <==> 4 <==> 3 <==> 2 <==> 1

Here we swap the left and right pointers and move them towards each other till they meet or cross each other. Then the first and last nodes are swapped.