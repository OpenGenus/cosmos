#include<stdio.h>
#include<limits.h>
int max(int a,int b)
{
  if(a>b)
  return a;
  else
  return b;
}
  
int eggdrop(int n,int k)
{
 int i,j,x;
 int table[n+1][k+1];
 
 for(i=1;i<=n;i++)
 {
  table[i][1]=1;
  table[i][0]=0;
 }
 
 for(j=1;j<=k;j++)
 table[1][j]=j;
 
  
 for(i=2;i<=n;i++)
 {
  for(j=2;j<=k;j++)
  {
   table[i][j]=INT_MAX;
   for(x=1; x<=j;x++)
   {
     int res=1+max(table[i-1][x-1],table[i][j-x]);
     
     if(res < table[i][j])
     table[i][j]=res;
   }
  }
 }
 
 return table[n][k];
 
}

     
      
int main()
{
 int n,k;
 scanf("%d%d",&n,&k);
 
 printf("\n%d\n",eggdrop(n,k));
 
 return 0;
} 
 
