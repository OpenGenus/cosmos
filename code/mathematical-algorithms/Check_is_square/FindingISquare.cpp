#include <iostream>
#include <cmath>
using namespace std;

// Function to check squares
int isSquare ( int n ){
	
	if ( n < 0 )
		return 0;

	//remove digits after decimal
	int root = (int)round(sqrt(n)); 
	
	return ( root * root ) == n ;
}


int main()
{
	int t;
	cout<<"Enter no. of test cases"<<endl;
	cin>>t;
	while(t--)
	{
		int n;
		cout<<"Enter the number"<<endl;
		cin>>n;

		cout << ( isSquare (n) ? "YES" : "NO" ) << endl;

	}
}
