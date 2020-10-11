// Reverse a linked list using 3 pointers
// https://iq.opengenus.org/reverse-linked-list-using-2-pointers-xor/
#include <cstdlib>
#include <iostream>

struct node {
  int data;
  struct node *nptr; // next pointer
};
struct node *hptr = NULL; // head pointer

void insertNode(int pos, int x) {
  struct node *temp = new node;
  if (temp == NULL)
    std::cout << "Insert not possible\n";
  temp->data = x;
  if (pos == 1) {
    temp->nptr = hptr;
    hptr = temp;
  } else {
    int i = 1;
    struct node *thptr = hptr;
    while (i < pos - 1) {
      thptr = thptr->nptr;
      i++;
    }
    temp->nptr = thptr->nptr;
    thptr->nptr = temp;
  }
}

// function to reverse the linked list
void reverseList() {
  struct node *current = hptr;
  struct node *next;
  struct node *prev = NULL;
  // link reversal
  while (current != NULL) {
    next = current->nptr;
    current->nptr = prev;
    prev = current;
    current = next;
  }
  // updating the head pointer after link reversal
  hptr = prev;
}

// function to print the contents of the linked list
void print() {
  struct node *temp = hptr;
  while (temp != NULL) {
    std::cout << temp->data << "\n";
    temp = temp->nptr;
  }
}

int main() {
  insertNode(1, 10);
  insertNode(2, 20);
  insertNode(3, 30);
  insertNode(4, 40);
  insertNode(5, 50);
  reverseList();
  print();
  return 0;
}
