#include <iostream>
#include <cmath>
using namespace std;

// Function to check squares
bool isSquare ( int n ){
	
	if ( n < 0 )
		return false;

	//remove digits after decimal
	int root = (int)round(sqrt(n)); 
	
	bool is_square = false;
	for(int i=root-2; i<root+2; i++)
	{
		if((i*i) == n)
		{
			is_square = true;
			break;
		}
	}
	return is_square;
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
