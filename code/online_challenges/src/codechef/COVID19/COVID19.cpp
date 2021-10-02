#include<bits/stdc++.h>
using namespace std;

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		std::vector<int> x(n);
		for(int &i:x)
			cin>>i;

		int mn=10,mx=0,curr=1;

		for(int i=1;i<n;i++)
		{
			if(x[i]-x[i-1]<=2)
				curr++;
			else
			{
				mx=max(mx,curr);
				mn=min(mn,curr);
				curr=1;
			}
		}

		if(curr!=0)
		{
			mx=max(mx,curr);
			mn=min(mn,curr);
		}

		mn=min(mn,mx);
		cout<<mn<<" "<<mx<<"\n";
	}
	return 0;
}