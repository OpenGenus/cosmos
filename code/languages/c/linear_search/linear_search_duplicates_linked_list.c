#include <stdio.h>
#include <stdlib.h>
/*
Input : integer linked list , key to be searched
Ouput : Position(s) of the key in the linked list if found, else print nothing
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
int ind;
int *linearSearch(int key, int result[]) {
  struct node *temp = hptr;
  int i = 1;
  ind = 0;
  while (temp != NULL) {
    if (temp->data == key) {
      result[ind++] = i;
    } else {
      result[ind] = -1;
      ind++;
    }
    i++;
    temp = temp->nptr;
  }
  return result;
}

int main() {
  int result[10];
  insert(1, 11);
  insert(2, 6);
  insert(3, 12);
  insert(4, 14);
  insert(5, 6);
  insert(6, 10);
  insert(7, 6);
  print();
  printf("Position(s) of the key is : \n");
  linearSearch(6, result);
  for (int i = 0; i < ind; i++) {
    if (result[i] != -1)
      printf("%d \n", result[i]);
  }
  return 0;
}

/*Output
Linked List contains : 
11
6
12
14
6
10
6
Position(s) of the key is : 
2 
5 
7 

*/
