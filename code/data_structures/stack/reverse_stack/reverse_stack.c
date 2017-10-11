// heders file
#include <stdio.h>
// MAX SIZE
#define MAX_SIZE 5

int stack[MAX_SIZE];  // stack with size = MAX_SIZE
int top = 0;  // top is initialised to 0 - first value of

// pushing value in stack
void push(int val) {
  if(top!=MAX_SIZE)
    {
      stack[top++] = val;
      printf("%d pushed\n", val);
    }
}

// printing value of stack
void print()
{

}

// reversing stack
int* reverse(int arr[]) {

}

// main function
int main() {

  return 0;
}
