// Part of Cosmos by OpenGenus Foundation 
#include <iostream>
#include <cmath>
using namespace std;

// Function to check squares
bool isSquare ( int n ){

	//remove digits after decimal
	int truncRoot = static_cast<int>(sqrt(n));
	
	return (n >= 0) && (( truncRoot * truncRoot ) == n );
}


int main()
{
	int t;
	cout<<"Enter the no. of test cases"<<endl;
	cin>>t;
	while(t--)
	{
		int n;
		cout<<"Enter the number: "<<endl;
		cin>>n;

		cout << ( isSquare (n) ? "YES" : "NO" ) << endl;

	}
}
