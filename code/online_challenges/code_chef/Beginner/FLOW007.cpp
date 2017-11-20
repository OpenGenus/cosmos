// part of cosmos from opengenus foundation

// problem code link https://www.codechef.com/problems/FLOW006


#include <iostream>
using namespace std;

int getSum(int number)
{
    int rev = 0;

    while(number != 0)
    {
        rev = rev * 10 +  number % 10;
        number /= 10;
    }

    return rev; 
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
