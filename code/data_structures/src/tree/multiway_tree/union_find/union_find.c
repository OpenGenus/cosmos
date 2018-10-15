/* Part of Cosmos by OpenGenus Foundation */
/*
*   ░█░█░█▀█░▀█▀░█▀█░█▀█░░░░░█▀▀░▀█▀░█▀█░█▀▄
*   ░█░█░█░█░░█░░█░█░█░█░▄▄▄░█▀▀░░█░░█░█░█░█
*   ░▀▀▀░▀░▀░▀▀▀░▀▀▀░▀░▀░░░░░▀░░░▀▀▀░▀░▀░▀▀░
*
*   Union-Find implementation using a parent array to implement set structure.
*   Basic operations:
*     1.int find_optimal(int x):  Find representative index of the set that the element with index x belongs to while compressing path for optimization
*     2.find(int x):   Find representative index of the set that the element with index x belongs to
*     3.void union_sets(int x,int y,int parent[]):  Unite sets that contain elements with id's x and y into a new set that is the union of these two
*   There should not be cycles in the graph of element nodes.
*   We are only using element indexes in parent array so elements can be of any possible type
*/

#include <stdio.h>
#include <stdlib.h>

//Function to return a parent array from a set of n elements
int* init_parent(int a[],int length){
  int *b = (int *)malloc(length);
  for (int i = 0; i < length; i++) {
    b[i] = i;
  }
  return b;
}

//returns the representative (his input array index) of the set that includes x
int find(int x,int parent[]) {
    while (x != parent[x]) x = parent[x];
    return(x);
}

int find_optimal(int x,int parent[]) {
    if (x != parent[x])
      parent[x] = find_optimal(parent[x],parent);
    return(parent[x]);
}

//Combines two sets in one by updating the parent array. No special policy about who will be the new representative
void union_sets(int x, int y,int parent[]) {
  if (parent[x] == parent[y]) return;
  else if(find_optimal(y,parent)!= y){
    parent[find_optimal(x,parent)] = find_optimal(y,parent);
  }
  else{
  parent[find_optimal(y,parent)] = find_optimal(x,parent);
}
}


int main(int argc, char const *argv[]) {
  int a[] = {1,3,6,2,7,5,0,4};  //The array can store any type. We are using int array and random integers for testing
  int a_length = sizeof(a)/sizeof(a[0]);    //Num of input elements

//First, all nodes are not included in any set so their parent is their self
//  int * parent_array = init_parent(a,a_length);


/*
*   For testing, we setup our nodes to form two sets (Refering to elements with their indexes)
      1     |    5
     / \    |   /|\
    0  2    |  4 6 7
       |    |
       3    |
*/

int parent_array[] = {1,1,1,2,5,5,5,5};
  printf("%s\n","Parent array before union: " );
  for (int i = 0; i < a_length; i++) {
    printf("%d ",parent_array[i] );
  }
  printf("\n");

  union_sets(4,2,parent_array);

  printf("%s\n","Parent array after union: " );
  for (int i = 0; i < a_length; i++) {
    printf("%d ",parent_array[i] );
  }
  printf("\n");

//After the union we see that parent[5] = 1 so node 5 becomes child of node 1 and so do all of node's 5 children
  return 0;
}
