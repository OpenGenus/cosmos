
#include <iostream>
using namespace std;
int recbub(int arr[],int n)
{   
   int i,temp;
   if(n==1)
   {
   return n;
   }
    else
    {
    for(i=0;i<n-1;i++)
    {
        if(arr[i]>arr[i+1])
                      {
                          temp=arr[i];
                          arr[i]=arr[i+1];
                          arr[i+1]=temp;
                      }}
        recbub(arr, n-1);
    }
                      }
     int main()
                      {
           int ar[100],size,j,b;
                          cout<<"Enter size of array:\n";
                          cin>>size;
                          cout<<"Enter the elements of array:\n";
                          for(j=0;j<size;j++)
                          {
                              cin>>ar[j];
                          }
                          b=recbub(ar,size);
                          cout<<"Sorted elements of array are:\n";
                          for(j=0;j<size;j++)
                          {
                              cout<<ar[j]<<" ";
                          }
                          return 0;
                      }
        
