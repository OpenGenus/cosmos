#include <iostream>
// Part of Cosmos by OpenGenus Foundation
using namespace std;
	int main()
{
	int n,m;
	cout<<"Input Size of Square"<<endl;
	cin>>n;
	m=n;
	n*=n;
	cout<<((n*(1+n))/2)/m<<endl;
}
