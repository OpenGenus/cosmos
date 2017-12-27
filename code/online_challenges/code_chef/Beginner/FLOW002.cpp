// part of cosmos from opengenus foundation

// problem code link https://www.codechef.com/problems/FLOW002


#include <iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    int arr[t], i=0;
    while(t--)
    {
        int a,b;
	cin>>a>>b;
	arr[i++] = a % b;
    }

    for(i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
        cout<<arr[i]<<endl;
    return 0;
}
