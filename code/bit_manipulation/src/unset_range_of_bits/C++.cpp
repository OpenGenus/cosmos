#include<iostream>
using namespace std;


int main(){
	
	int n,i,j;
	
	cout<<"\n Enter a number";
	cin>>n;
	
	//unset bit from i to j
	cout<<"\n Enter range ";
	cin>>j>>i;
	
	
	
	int a,b;
	
	a=-1<<(i+1);
	b=(1<<j)-1;
	
	int mask= a|b;
	
	int ans=n&mask;
	
	cout<<"\n New number generated after clearing bits from "<<j<<" to "<<i<<" : "<<ans;
	
}

/*
Input
Enter a number
31
Enter range 
1 
3
New number generated after clearing bits from 1 to 3 : 17
*/

