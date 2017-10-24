#include<stdio.h>

int main()
{
 int a[20],n,j,i,temp;
 
 scanf("%d",&n);
 for(j=0;j<n;j++)
 scanf("%d",&a[j]);

for(i=1;i<n;i++)
{
  temp=a[i];
    j=i;
   while( j>0 && temp < a[j-1])
   {
       a[j]= a[j-1];
       j--;


   }
  a[j] = temp;

}

printf("\n");
for(i=0;i<n;i++){
printf("%d",a[i]);
}
return 0;
}
