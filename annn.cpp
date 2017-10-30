#include <bits/stdc++.h>
using namespace std;

int main() {
	
int n,k;
cin>>n;
vector <long int >v1(n),v2(n);
long int c=0,sum=0;

for(int i=0;i<n;i++)
{
	cin>>v1[i];
	v2[i]=v1[i];
	c=c+v1[i];
	
	}	

sort(v2.begin(),v2.end());
k=n;
for(int h=0;h<n;)
{
if(k!=2 && k!=3)
{
	sum=sum+c;
	c=c-v2[n-1-h]-v2[n-2-h];
	k=k-2;
	h=h+2;
}
else if(k==3)
{
	sum=sum+v2[0]+v2[1]+v2[2];
	break;
	
}
else
{
	sum=sum+v2[0]+v2[1];
	break;
}
	
	
}


cout<<sum;









}
