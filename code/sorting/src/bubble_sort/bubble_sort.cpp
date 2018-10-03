#include<iostream>
 
using namespace std;
 
int main()
{
    int a[50],n,i,j,temp;
    cout<<"Enter the size of array: ";
    cin>>n;
    cout<<"Enter the array elements: "; 
    
    for(i=0;i<n;++i)
        cin>>a[i];
        
    for(i=1;i<n;++i)
    {
        for(j=0;j<(n-i);++j)
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
    }
    
    cout<<"Array after bubble sort:";
    for(i=0;i<n;++i)
        cout<<" "<<a[i];
        
    return 0;
}
