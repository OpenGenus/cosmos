/*
PROBLEM STATEMENT:
Given 2 numbers x and y, you need to find x raise to y.
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FIO ios::sync_with_stdio(0);
ll power(ll a,ll b)
{
	ll res=1;
	while(b!=0)
	{
		if(b%2!=0)
		{
			res=(res*a)%1000000007;
			b--;
		}
		else
		{
			a=(a*a)%1000000007;
			b/=2;
		}
	}
	return res;
}
int main() 
{
	FIO;
        ll number_a,number_b,answer;
        cin >> number_a >> number_b;
        answer = power(number_a,number_b);
        cout << answer;
	return 0;
}
