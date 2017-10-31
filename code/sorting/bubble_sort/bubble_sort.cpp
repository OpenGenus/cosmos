/* Part of Cosmos by OpenGenus Foundation */
//Sorting array element (The bubble sort)

#include<iostream>

using namespace std;

void bsort(int *ptr,int s)
{
int i,j;
int temp;
for(i=1;i<s;i++)
 {
  for(j=0;j<s-i;j++)
   {
    if(*(ptr+j)>*(ptr+j+1))
     {
      temp=*(ptr+j);
      *(ptr+j)=*(ptr+j+1);
      *(ptr+j+1)=temp;
     }
   }

}
}
int main()
{
    const int N=5;
    int arr[N]={10,8,15,7,11};

    bsort(arr,N);       //sort the array

    for(int j=0; j<N ;++j)
        cout<<arr[j]<<" ";
    cout<<endl;

    return 0;
}



/*
Bubble sort algorithm (steps):
algorithm compares the first two elements, and swaps the minimum number to be in beginning.
    10 8 15 7 11
    ---------------
    first iteration
    10 8 15 7 11
    8 10 15 7 11
    7 10 15 8 11
    ---------------
    second iteration
    7 10 15 8 11
    7 8  15 10 11
    ---------------
    third iteration
    7 8  15 10 11
    7 8  10 15 11
    ---------------
    fourth iteration
    7 8  10 15 11
    7 8  10 11 15
    ---------------

for(int i=0; i<N-1 ;++i)
    {
        for(int j=i+1; j<N ;++j)
            order(ptr+i,ptr+j);

    }
*/



