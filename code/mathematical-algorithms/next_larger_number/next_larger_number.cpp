#include<bits/stdc++.h>
using namespace std;
// Part of Cosmos by OpenGenus Foundation
void nextgr(char num[],int n)
{
 int i,j;
 
 for(i=n-1;i>=0;i--)
 {
   if(num[i-1]< num[i])
   break;
 }
 
 if(i==0)
 {
  cout<<"No such greater number exists";
  return ;
 }
 
 int x=num[i-1], small=i;
 
 for(j=i+1;j<n;j++)
 {
   if(num[j] > x && num[j] < num[small] )
   small=j;
 }
 
 swap(num[i-1],num[small]);
 
 sort(num+i, num+n);
 
 cout<<num;
}   

int main()
{
 char num[20];
 
 cin>>num;
 int n=strlen(num);
 nextgr(num,n);
 
 cout<<endl;
 return 0;
}
       
