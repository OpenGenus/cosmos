#include<iostream>
using namespace std;


int main(){

    int N,x;

    cin>>N;
    int arr[N];
    for(int i=0;i<N;i++)
    {
        cin>>arr[i];
    }
    
    //Taking the number to be searched.
    cin>>x;
    
    //Getting first and last index of the array.
    int lo = 0, hi = (N - 1);
    int flag=0;
    
    //If the element is present in the sorted array, it must be in the range defined by 'hi' and 'lo'.
    while (lo <= hi && x >= arr[lo] && x <= arr[hi])
    {
        // The idea of formula is to return higher value of pos
        // when element to be searched is closer to arr[hi], and
        // smaller value when closer to arr[lo]
        int pos = lo + (((double)(hi-lo) /
              (arr[hi]-arr[lo]))*(x - arr[lo]));

        if (arr[pos] == x)
          {
          cout<<pos;
          //Number found at pos
          flag=1;
          }

        if (arr[pos] < x)
            lo = pos + 1;


        else
            hi = pos - 1;
    }
    if(flag == 0)
        cout<<-1;
}
