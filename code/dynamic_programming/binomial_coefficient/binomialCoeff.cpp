#include<iostream>
#include<vector>
using namespace std;

long long int binCoef(int n, int k)
{
	if(n<0 || k<0 || n<k)
	return -1;
	vector<int> c(k+1);
	c[0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=min(i,k);j>0;j--)
		{
			c[j]=c[j]+c[j-1];
			
		}
	}
	return c[k];
	
}
int min(int a,int b)
{
	if(a<b)
	return a;
	else
	return b;
}
int main()
{   int n,k;
	cout<<"enter the values of n and k\n";
	cin>>n>>k;
	cout<<"binomial co-efficient is:"<<binCoef(n,k);
	return 0;
}
