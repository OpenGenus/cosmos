//First n Catalan numbers using Dynamic Programming!!!

#include <iostream>
using namespace std;
// Part of Cosmos by OpenGenus Foundation

#define ll long long int 

int main()
{
	int n;
	cin>>n;
	ll catalan_array[10000];
	int c0=1;
	cout<<c0<<endl;
	catalan_array[0]=c0;
	cout<<catalan_array[0]<<endl;
	for(int i=1;i<n-1;i++)
	{
	    catalan_array[i]=((2*(2*(i)+1))*(catalan_array[i-1]))/(i+2);
	    cout<<catalan_array[i]<<endl;
	}
	
}
