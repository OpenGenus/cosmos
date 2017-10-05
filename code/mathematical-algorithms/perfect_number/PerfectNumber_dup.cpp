#include <iostream>
using namespace std;
int main()
{
	int t;
	cout<<"Enter no. of test cases"<<endl;
	cin>>t;
	while(t--)
	{
		int num,rem,i,sum=0;
		cout<<"Enter the number to check"<<endl;
		cin>>num;
		for(i=1;i<num;i++)
		{
			rem=num%i;
			if(rem==0)
			{
				sum=sum+i;
			}
		}
		if(sum==num)
		cout<<"Yes"<<endl;
		else
		cout<<"No"<<endl;
	}
	
}
