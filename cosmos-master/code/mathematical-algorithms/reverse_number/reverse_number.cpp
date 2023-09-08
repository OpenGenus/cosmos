#include<iostream>>
using namespace std;
// Part of Cosmos by OpenGenus Foundation
int reverse_number(int n)
{
    int ans=0,temp=n,mult=1,count=0;
    while(temp!=0)
    {
        count++;
        temp/=10;
    }
    for(int i=0 ; i<count-1 ; i++)mult*=10;
    while(n!=0)
    {
        ans+=(n%10)*mult;
        n/=10;
        mult/=10;
    }
    return ans;
}

int main()
{
	int n;
	cin>>n;
	cout<<reverse_number(n);

	return 0;
}
