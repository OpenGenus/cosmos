/* do-while loop*/
/*C program to print sum of first 5 natural numbers using do..while loop*/
/*do- while loop is a loop for performing repetitive tasks. In this loop the body of the loop is executed*/
/*atleast once, and then the test condition is checked. If it evaluates to true, the loop continues to run otherwise it is exited.*/

#include <stdio.h>

int
main() 
{
  int sum = 0, i = 1; /*initialization of counter variable i*/
  do {
    sum += i;
    ++i; /*increment of counter variable*/
  } while (i <= 5); /*condition of do while*/

  printf("sum of first 5 natural numbers = %d", sum);
  return (0);
} /*end of program*/

/*output:*/
/*sum of first 5 natural numbers = 15*/
