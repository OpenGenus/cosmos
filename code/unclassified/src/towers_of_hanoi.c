#include<stdio.h>
#include<conio.h>

int main(){
 int n;
 char source,intermediate,destination; //three towers 
 printf("enter number of disks");
 scanf("%d",&n);
 source='s';
 intermediate='i';
 destination='d';
 toh(n,source,destination,intermediate);
 return(0);
}

int toh(int n,char s,char d,char i){
 if(n==1)
 {
  printf("move %d disk from %c to %c \n",n,s,d);
 }
 else
 {
  toh(n-1,s,i,d);
  printf("move %d disk from %c to %c \n",n,s,d);
  toh(n-1,i,d,s);
 }
 return(0);
}
