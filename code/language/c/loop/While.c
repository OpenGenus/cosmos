/*A while loop in C programming repeatedly executes a target statement as long as a given condition is true.*/
/*It is an entry controlled loop i.e. a test condition is checked and only if it evaluates to true, is the body of the loop executed.*/ 

#include <stdio.h>

int
main()
{
  int n = 1, times = 5; /*local variable initialization*/
  while (n <= times) /*while loops execution*/
  {
    printf("C while loops: %d\n", n);
    ++n;
  }

  return (0);
}
/*output:*/
/*C while loops:1*/
/*C while loops:2*/
/*C while loops:3*/
/*C while loops:4*/
/*C while loops:5*/
