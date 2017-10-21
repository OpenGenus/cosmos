/* Part of Cosmos by OpenGenus Foundation */
//Sorting array element (The bubble sort)

#include<iostream>

using namespace std;

void bsort(int *,int);               //prototype
void orderPointer(int *,int *);      //prototype

//call by pointer
void orderPointer(int * a,int * b)
{
    if(*a>*b)
    {
        int temp=*a;
        *a=*b;
        *b=temp;
    }

}

void bsort(int* ptr,int s)
{
    for(int i=0; i<s-1 ;++i)
    {
        for(int j=i+1; j<s ;++j)
            orderPointer(ptr+i,ptr+j);


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



