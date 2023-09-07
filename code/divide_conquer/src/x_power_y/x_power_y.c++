#include<iostream> 
using namespace std; 
int power(int x, unsigned int y) 
{ 
	if (y == 0) 
		return 1; 
	else if (y % 2 == 0) 
		return power(x, y / 2) * power(x, y / 2); 
	else
		return x * power(x, y / 2) * power(x, y / 2); 
} 
int main() 
{ 
	int x ;
	unsigned int y; 
  cout<<"Enter value of x\n";
  cin>>x;
  cout<<"Enter value of y\n";
  cin>>y;
  int val=power(x,y);
  cout<<"x to the power y is: "<<val;
	return 0; 
} 

