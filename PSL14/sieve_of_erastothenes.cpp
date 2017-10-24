#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int j,n=10000,i,t,x,count=0;
	cout<<"Enter number of test cases : ";
	cin>>t;
	long long int a[n+1];
	for(i=1;i<=n;i++)
		a[i]=1;
	for(i=2;i<=n;i++)
	{
		if(a[i]==1)
		{
			for(j=2*i;j<=n;j+=i)
				a[j]=0;
		}
	}
	while(t--)
	{
		cin>>x;
		if(a[x])
			cout<<"Prime number\n";
		else
			cout<<"Not a prime number\n";
	}
	return 0;
}
