/*Given an array arr[] of n integers, construct a Product Array prod[] (of same size) 
such that prod[i] is equal to the product of all the elements of arr[] except arr[i]. 
Solve it without division operator in O(n) time.*/

#include<cstdlib>
#include<iostream>
using namespace std;
//O(n^2) approach -> naive approach
/*


void product_array(int a[], int n)
{
    int arr[n];
    for(int i=0;i<n;i++)
        arr[i]=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i!=j)
            {
                arr[i]*=a[j];
            }
        }
    }
    cout<<"The req array is : \n";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}

int main()
{
    int a[]={1, 2, 3, 4, 5};
    int n=sizeof(a)/sizeof(a[0]);
    product_array(a,n);
    return 0;
}
*/

//O(n) -> naive approach

/*Approach: Create two extra space, i.e. two extra arrays to store the product of all the array elements from start, 
up to that index and another array to store the product of all the array elements from the end of the array to that index.
To get the product excluding that index, multiply the prefix product up to index i-1 with the suffix product up to index i+1.
*/
void product_array(int a[],int n)
{
    /* Allocate memory for temporary arrays left[] and right[] */
    int* left=new int[sizeof(int)*n];
    int* right=new int[sizeof(int)*n];
    int* product=new int[sizeof(int)*n];
    left[0]=1;
    right[n-1]=1;

    for(int i=1;i<n;i++)
        left[i]=a[i-1]*left[i-1];
        
    for(int i=n-2;i>=0;i--)
        right[i]=a[i+1]*right[i+1];
    /* Construct the product array using  
        left[] and right[] */
    for(int i=0;i<n;i++)
        product[i]=left[i]*right[i];

    cout<<"Product array is : \n";
    for(int i=0;i<n;i++)
        cout<<product[i]<<" ";
}

int main()
{
    int a[]={10, 3, 5, 6, 2};
    int n=sizeof(a)/sizeof(a[0]);
    product_array(a,n);
    return 0;
}