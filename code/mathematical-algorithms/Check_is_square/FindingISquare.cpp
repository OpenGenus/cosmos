#include <iostream>
using namespace std;
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
		int i;
		for(i=1;i<=n;i++)
		{
			if(i*i==n)
			{
			
			cout<<"Yes";
			return 0;
		}
		}
	  cout<<"No";
		return 0;
		
	}
}
