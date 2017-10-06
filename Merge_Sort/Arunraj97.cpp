#include<bits/stdc++.h>
using namespace std;

void merge(int a[], int l, int m, int r)
{
    int i, j, k;
    int llen=m-l+1;
    int rlen=r-m;
 
    int L[llen], R[rlen];
 
    for (i = 0; i < llen; i++)
        L[i] = a[l + i];
    for (j = 0; j < rlen; j++)
        R[j] = a[m + 1+ j];
 
    i = 0; 
    j = 0; 
    k = l; 
    while (i < llen && j < rlen)
    {
        if (L[i] <= R[j])
        a[k++] = L[i++];
        
        else
        a[k++] = R[j++];
    }
 
   while (i < llen)
   	a[k++] = L[i++];
        
     
    while (j < rlen)
        a[k++] = R[j++];
        
}    

void msort(int a[],int l,int r)
{
  if( l<r)
  {
   int m=(r+l)/2;
   msort(a,l,m);
   msort(a,m+1,r);
   
   merge(a,l,m,r);
  }
 }
 
 int main()
 {
  int n,*a;
  
  cout<<"\nEnter size of array:";
  cin>>n;
  
  a=new int [n];
  
  cout<<"\nEnter "<<n<<" elements : ";
  
  for(int i=0;i<n;i++)
  cin>>a[i];
  
  cout<<"\nInitial Array is : ";
  for(int i=0;i<n;i++)
  cout<<a[i]<<" ";
  
  msort(a,0,n-1);
  
  cout<<"\nSorted Array is : ";
  for(int i=0;i<n;i++)
  cout<<a[i]<<" ";
  
  cout<<"\n";
  return 0;
}
    
      
