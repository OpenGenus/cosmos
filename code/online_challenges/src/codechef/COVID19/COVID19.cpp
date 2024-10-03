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

		int smallest=10,largest=0,infected=1;

		for(int i=1;i<n;i++)
		{
			if(x[i]-x[i-1]<=2)
				infected++;
			else
			{
				largest=max(largest,infected);
				smallest=min(smallest,infected);
				infected=1;
			}
		}

		if(infected!=0)
		{
			largest=max(largest,infected);
			smallest=min(smallest,infected);
		}

		smallest=min(smallest,largest);
		cout<<smallest<<" "<<largest<<"\n";
	}
	return 0;
}
