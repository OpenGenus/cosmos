#include <stdio.h>;
 
/* Recursive function to reverse digits of num*/
int reversDigits(int num)
{
  static int rev_num = 0;
  static int base_pos = 1;
  if(num > 0)
  {
    reversDigits(num/10);
    rev_num  += (num%10)*base_pos;
    base_pos *= 10;
  }
  return rev_num;
}
 
/*Driver program to test reversDigits*/
int main()
{
    int num = 4562;
    printf("Reverse of no. is %d", reversDigits(num));
 
    getchar();
    return 0;
}