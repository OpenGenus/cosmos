#include <iostream>
using namespace std;

int findTrailingZeroes(int n);

int main()
{
	int n;
	cout<<"Enter the value of n:"<<endl;
	cin>>n;
	cout<<"You entered "<<n<<endl;
	cout<<"The number of trailing zeroes = "<<findTrailingZeroes(n)<<endl;
	return 0;
}

int findTrailingZeroes(int n)
{
	int count=0;
	for(int i=5;n/i >= 1; i*=5){
		count+=n/i;
	}
	return count;
}