#include<stdio.h>  
void main(){  
  char str[20];    
  printf("\n\n Enter string: ");  
  gets(str); 
  printf("\n\nString is: %s",str);  
  printf("\nReverse String is: %s",strrev(str));  
}    
