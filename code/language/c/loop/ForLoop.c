/*For-loop
C program to print sum of even numbers between 0 and 20 using For loop
For Loop is a entry controlled loops.
Basic structure of for loop:
for (initialization expression; test expression; update expression)
{
     // body of the loop
     // statements we want to execute
}*/
#include <stdio.h>

int
main()
{
  int sum = 0, i;
  for(i = 0; i<=20; i = i+2)
  {
      sum = sum + i;
  }

  printf("Sum of even numbers between 0 and 20 is = %d", sum);
  return (0);
}

/*Output:
Sum of even numbers between 0 and 20 is = 110*/
