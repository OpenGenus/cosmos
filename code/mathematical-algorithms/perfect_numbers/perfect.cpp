#include<bits/stdc++.h>

using namespace std;

int main()
{
 int num,i,sum=0;
 
 cin>>num;
 
 for(int i=1;i<=num/2;i++)
 {
   if(num%i==0)
   sum+=i;
 }
 
 if(sum==num)
 cout<<"\nNumber is perfect number";
 
 else
 cout<<"\nNumber is not perfect";
 
 cout<<"\n";
 
 return 0;
}
 
 
   
