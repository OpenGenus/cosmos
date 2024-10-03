#include<stdio.h>
void main()
{
 int a[3]={-1,-1,-1},n=0,ab[5],i=0,hit=0,j=0;
 printf("\n enter refernce string");
  for(i=0;i<12;i++)
   scanf("%d",&ab[i]);
 printf("\n default -");
 
  for(i=0;i<3;i++)
   {
    a[i]=ab[i];
    n++;
   }
i=3;
 printf("%d %d %d\n ",a[0],a[1],a[2]);
  while(i<12)
   {
    while(j<3&&i<12)
     {printf("%d %d %d\n ",a[0],a[1],a[2]);
      if(ab[i]!=a[j]&&ab[i]!a[j])
       {
       
        a[j]=ab[i];
        j++;
        i++;
       }
      else
       {
        i++;
        hit++;
       }
     }
       
        n++;
        j=j%3;
       
 
   }
 
  printf("no of hits=%d no of faults=%d",hit,n);
 
}
