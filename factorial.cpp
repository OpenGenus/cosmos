//C++ program to print the factorial of a number. Time complexity= O(n)


#include<iostream>
#include<stdlib.h>

using namespace std;

void factorial(long long int n)	//function to print the factorial of a number
{
	long long int fac=1;
	for(long long int i=0;i<n;i++)					//while loop which runs for n times
	{
		fac=fac*(i+1);		//fac=1 after first iteration. fac=1*2 after second iteration... fac=n! after nth iteration 
	}
	cout<<endl<<fac;
}



int main()
{
	long long int a;
	cin>>a;
	factorial(a);			//factorial function called with a as parameter
	return(0);
}
