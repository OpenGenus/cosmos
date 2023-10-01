#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> fact(1000);		//To store each digit of factorial
  
	int n;
	cin>>n;

	int carry = 0;
	int counter = 1;

	fact[0] = 1;

	for(int i=1; i<=n; i++)
	{
		for(int j=0; j<counter; j++)
		{
			int prod = fact[j]*i + carry;
			fact[j] = prod % 10;
			carry = prod/10;
		}

		while(carry > 0)
		{
			fact[counter] = carry % 10;
			carry /= 10;
			counter++;
		}
	}
	for(int i=counter-1; i>=0; i--)
	{
		cout<<fact[i];
	}
	return 0;
}
