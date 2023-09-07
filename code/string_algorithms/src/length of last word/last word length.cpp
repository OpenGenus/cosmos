#include<bits/stdc++.h>
using namespace std;

int main()
{
		//Declaring string
	string str;			
	getline(cin,str);		//Input of string
	int l=str.length();		//Assigning length of string in variable l
	int count=0;
	for(int i=l-1;i>=0;i--)				// traversing the string from back
	{	
		if(str[i]==' ')  		//If the character is a space break from the loop  
		break;
		count++;				//Increment the count
	}
	cout<<"The length of last word is "<<count;
}
