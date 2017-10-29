#include<stdio.h>
#include<conio.h>
void main(){
  int i,fact=1,number;
  clrscr();
  printf("Enter a number: ");
  scanf("%d",&number);

  for(i=1;i<=number;i++){
      fact=fact*i;
  }
  printf("Factorial of %d is: %d",number,fact);
  getch();
}