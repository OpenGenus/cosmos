#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n,i,j,m,q,c;
	cin>>n;
	int x[n];
	for(i=0;i<n;i++)
	cin>>x[i];
	sort(x,x+n);
	cin>>q;
	for(i=0;i<q;i++)
	{
		cin>>m;
		c=upper_bound(x,x+n,m)-x;
		cout<<c<<endl;
	}
}
