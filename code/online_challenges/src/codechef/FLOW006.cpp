#include <iostream>

using namespace std;

int main()
 {
	
	int t,n;
	
	//Input number of testcases-->t
	cin>>t;
	
	while(t>0)
	{
		cin>>n;
		//Initialise sum with 
		int sum=0;
		
		while(n!=0)
		{
			sum = sum + n % 10;
			n = n/10;
		}
		
		cout<<sum<<'\n';
		t--;
		
	}
	return 0;
}
