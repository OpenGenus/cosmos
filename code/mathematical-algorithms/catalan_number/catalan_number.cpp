#include <iostream>
// Part of Cosmos by OpenGenus Foundation
using namespace std;
int main()
{
	int n;
	cin>>n;
	int cat[n+1];
	cat[0]=1;
	cat[1]=1;
	for(int i=2;i<=n;i++)
	{
		cat[i]=0;
		for(int j=0;j<i;j++)
		{
			cat[i]+=cat[j]*cat[i-j-1];
		}
	}
	cout<<cat[n]<<endl;
}
