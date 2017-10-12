// heders file
#include <stdio.h>
// MAX SIZE

#define MAX_SIZE 5

int Stack[MAX_SIZE];  // Stack with size = MAX_SIZE
int top = 0;  // top is initialised to 0 - first value of

// pushing value in Stack
void push(int val) {
  if(top!=MAX_SIZE)
    {
      Stack[top++] = val;
      printf("%d pushed\n", val);
    }
}

// poping value from Stack
void pop()
{
  top--;
}

// printing value of Stack
void print()
{
  int i;
  for (i = top - 1; i >= 0; i--) {
    printf("%d ", Stack[i]);
  }
  printf("\n");
}

// reversing Stack
void reverse() {
  int i = top - 1;
  int j = 0;
  while(i > j)
  {
    int temp = Stack[i];
    Stack[i] = Stack[j];
    Stack[j] = temp;
    i--;
    j++;
  }
}

// main function
int main() {

  /*
      Adding value in Stack
  */
  printf("\n\npushing values in the Stack\n");
  push(1);
  push(2);
  push(3);
  push(4);

  /*
      printing value in Stack
  */
  printf("\n\nprinting values in the Stack\n");
  print();

  /*
      reversing value in Stack and storing in same Stack variaus
  */
  printf("\n\nreversing values in the Stack\n");
  reverse();

  /*
      printing reversed value in Stack
  */
  printf("\n\nprinting reversed values in the Stack\n");
  print();

  return 0;
}
