
#include <stdio.h>
void main()
{
   int a = 58; 
   int b = 13;
   int c;           
   c = a & b;  
   printf("Value of c is %d\n", c );
   c = a | b;      
   printf("Value of c is %d\n", c );
   c = a ^ b;     
   printf("Value of c is %d\n", c );
   c = ~a;          
   printf("Value of c is %d\n", c );
   c = a << 2;    
   printf("Value of c is %d\n", c );
   c = a >> 2;    
   printf("Value of c is %d\n", c );
}
