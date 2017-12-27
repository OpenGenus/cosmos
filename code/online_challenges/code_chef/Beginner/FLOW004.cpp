// part of cosmos from opengenus foundation

// problem code link https://www.codechef.com/problems/FLOW004


#include <iostream>
using namespace std;

int getSum(int number)
{
   int lastDigit = number % 10;
   
   while(number >= 10)
       number /= 10;

   int firstDigit = number;

   return firstDigit + lastDigit; 
}

int main()
{
    int t;
    cin>>t;
    int arr[t], i=0;
    while(t--)
    {
        int a;
	cin>>a;
	arr[i++] = getSum(a);
    }

    for(i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
        cout<<arr[i]<<endl;
    return 0;
}
