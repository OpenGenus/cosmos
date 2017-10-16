#include<bits/stdc++.h>
using namespace std;

int main()
{
 int a[10],maxso=INT_MIN,maxend=0,i,n;
 
 cin>>n;
 for(i=0;i<n;i++)
 cin>>a[i];
 
 for(i=0;i<n;i++)
 {
   maxend+=a[i];
   
     
   if(maxso < maxend )
   maxso=maxend;
   
   if(maxend<0)
   maxend=0;
   
 }
 
 cout<<endl<<maxso;
 
 return 0;
 
}
   
