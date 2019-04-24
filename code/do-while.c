

// do-while loop
//C program to print sum of first 5 natural numbers using do..while loop

#include <stdio.h>
int main ()
{
 int sum = 0, i = 1;  //initialization of counter variable i
 do{
   sum = sum+i;
   i++;  //increment of counter variable
  }while(i <= 5);  //coondition of do while

 printf("sum of first 5 natural numbers = %d",sum);
 return 0;
}  //end of program

output:
sum of first 5 natural numbers = 15

