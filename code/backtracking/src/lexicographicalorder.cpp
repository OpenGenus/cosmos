#include<bits/stdc++.h>
using namespace std;
void lexico(int currnumprint,int num)
{
	if(currnumprint>num)
	return;
	cout<<currnumprint<<endl;
	for(int i=0;i<=9;i++)
	{
		lexico(currnumprint*10+i,num);
	}
}
int main()
{
	int num;
	cout<<"enter number \n";
	cin>>num;
	for(int i=1;i<=9;i++)
	{
		lexico(i,num);
	}
}
