#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int a,b,c,d,i,j,sum=0,cnt=0;
	string s;
	vector<long long int>  v;
	s="11000001111110101111010";
	for(i=0;i<s.size();i++)
	{
		if(s[i]=='1')
		{
			sum++;
		}
		else
		{
			v.push_back(sum);
			sum=0;
		}
	}
	sort(v.rbegin(),v.rend());
	cout << v[0] << endl;
}
