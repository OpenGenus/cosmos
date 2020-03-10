//Problem : Sum of Alternate Consecutive d odd numbers
//Input Line 1 states the number of test cases
//Input Line 2 states the range 'Left' and 'Right'
//Input Line 3 states the numerical value of 'd' odd numbers
//Output Line 1 displays the sum of alternate consecutive d odd numbers

/*
Sample Input
1
2
1 10

Sample Output 
13
*/


#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
int test;
cin>>test;
 
while(test > 0)
{
 
	int d;
	cin>>d;
 
	int left,right;
	cin>>left>>right;
	int c = 0;
	int sum = 0;
	int a[1000];
 
	for(c,left; left <= right; left++)
	{
		if(left % 2 == 1)
		{
			a[c] = left;
			c++;
 
		}
 
	}
	int key = d;
	for(int k = 0; k < c; k++)
	{
 
 
	if(k == d)
	{
		k = k-1 + key;
		d = k+1 + key;
 
	continue;
	}
	sum += a[k];
	}
	cout<<sum;
	test--;
}
 
	return 0;
}