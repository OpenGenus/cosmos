// Reverse a Linked List using 2 pointers using XOR
// https://iq.opengenus.org/p/8046f2c5-2cc6-4df0-b343-dd4f4a69d567/

#include <cstdlib>
#include <iostream>
typedef uintptr_t ut;

// structure of the linked list
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
  struct node *prev = NULL;
  while (current != NULL) {
    current = (struct node *)((ut)prev ^ (ut)current ^ (ut)(current->nptr) ^
                              (ut)(current->nptr = prev) ^
                              (ut)(prev = current)); // link reversal
  }

  hptr = prev; // updating the head pointer
}

// printing the contents of the linked list
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
