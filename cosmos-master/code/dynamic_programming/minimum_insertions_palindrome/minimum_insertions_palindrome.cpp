#include<bits/stdc++.h>
using namespace std;

int min(int a,int b)
{
 if(a<b)
 return a;
 
 else 
 return b;
 
}
 
/*int noofins(char str[],int l,int r)
{
  if(l==r)
  return 0;
  
  if(l==r-1)
  return !(str[l]==str[r]);
  
  if(str[l]==str[r])
  return noofins(str,l+1,r-1);
  
  else
  return min((noofins(str,l+1,r)) , (noofins(str,l,r-1)) ) + 1;
  
}*/ 
int noofins(char str[],int n)
{
 int table[n][n]={0},i,l,h;
 
 for(i=1;i<n;i++)
 {
  for(l=0,h=i; h<n; ++l,++h)
  {
   if(str[l]==str[h])
   table[l][h]=table[l+1][h-1];
   
   else
   table[l][h]= min(table[l+1][h], table[l][h-1]) + 1;
  }
 }
 
 return table[0][n-1];
}   

int main()
{
 char str[30];
 cin>>str;
 int n=strlen(str);
 
 cout<<noofins(str,n);
 
 return 0;
 
} 
