#include <bits/stdc++.h>
 using namespace std;
 
 int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
         int n,q=2,j=2;
         cin>>n;
         int b[n]={0};
         b[0]=1;
         b[1]=1;
         b[2]=2;
         int i=2,s=n-3;
         //or(int i=3;i<n-3;i++)
         while(s--)
         {
             i++;
             if(i%2==0)
                b[i]=b[i-1]+b[i-2];
             else if(i%2!=0)
                  {
                      if(q>0)
                        b[i]=j;
                      else
                        b[i]=j+1;
                    q--;
                  }
         }
         for(int i=0;i<n;i++) cout<<b[i]<<" ";
     }
 }
