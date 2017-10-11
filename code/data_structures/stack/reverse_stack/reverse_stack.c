// heders file
#include <stdio.h>
// MAX SIZE
#define MAX_SIZE 5

int stack[MAX_SIZE];  // stack with size = MAX_SIZE
int top = 0;  // top is initialised to 0 - first value of 

void push(int val) {
  if(top!=MAX_SIZE)
    {
      stack[top++] = val;
      printf("%d pushed\n", val);
    }
}

void print()
int main() {

  return 0;
}
