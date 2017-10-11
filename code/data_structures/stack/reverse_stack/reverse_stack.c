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

// poping value from stack
void pop()
{
  top--;
}

// printing value of stack
void print()
{
  int i;
  for (i = top - 1; i >= 0; i--) {
    printf("%d ", stack[i]);
  }
  printf("\n");
}

// reversing stack
void reverse() {
  int i = top - 1;
  int j = 0;
  while(i > j)
  {
    int temp = stack[i];
    stack[i] = stack[j];
    stack[j] = temp;
    i--;
    j++;
  }
}

// main function
int main() {

  /*
      Adding value in stack
  */
  printf("\n\npushing values in the stack\n");
  push(1);
  push(2);
  push(3);

  /*
      printing value in stack
  */
  printf("\n\nprinting values in the stack\n");
  print();

  /*
      reversing value in stack and storing in same stack variable
  */
  printf("\n\nreversing values in the stack\n");
  reverse();

  /*
      printing reversed value in stack
  */
  printf("\n\nprinting reversed values in the stack\n");
  print();

  return 0;
}
