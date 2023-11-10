#include <stdio.h>
#include <stdlib.h>
/*
Input : integer array indexed from 0, key to be searched
Ouput : Position(s) of the key in the array if found, else prints nothing
*/
int *linearSearch(int a[], int result[], int n, int key) {
  int pos = -1, ind = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] == key) {
      result[ind++] = i; // store the index of key, if found
    } else
      result[ind++] = -1; // store -1 if key not found
  }
  return result;
}

int main() {
  int a[] = {8, 12, 3, 4, 4, 7, 2, 3, 13, 17, 3};
  int n = sizeof(a) / sizeof(a[0]);
  int result[n];
  linearSearch(a, result, n, 3);
  int size = sizeof(result) / sizeof(result[0]);
  printf("Key found at position(s) : \n");
  for (int i = 0; i < size; i++) {
    if (result[i] != -1)
      printf("%d \n", result[i]);
  }

  return 0;
}

/*
Output :
Key found at position(s) : 
2 
7 
10 

*/
