// Part of Cosmos by OpenGenus Foundation

//Program to Calculate Perfect Numbers under n

#include<iostream>
#include<cmath>
using namespace std;
int main()
    {
     int n,k;
     cout<<"\nEnter the value of n:";
     cin>>n;
     cout<<"\nPerfect numbers under "<<n<<" are:\n";
     int i=1,s1=0,sum=0;

     for(k=1;k<=n;k++)
        {
           
           while(i<k)
            {
             if(k%i==0)
             s1=s1+i;
             i++;
            }

          i=1;

          if(k==s1)
          {
              cout<<k<<endl;
             
          }

          s1=0;
          
       }
       
    }
