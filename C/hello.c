#include<stdio.h>
#include<string.h>
int main()
{ char str[50];int i=0,j,len;
  char temp;
  printf("Enter String");
  gets(str);
  len=strlen(str);
  for(i=0,j=len-1;i<j;i++,j--)
  { temp=str[i];
    str[i]=str[j];
    str[j]=temp;
  	
  }
  puts(str);
  return 0;
}
