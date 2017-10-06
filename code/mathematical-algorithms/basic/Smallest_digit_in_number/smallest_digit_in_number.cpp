#include<iostream>
using namespace std;
int smallest_digit(int n)
{
    int min=n%10; //assume that last digit is the smallest
    n/=10; //to start from the second last digit
    while(n!=0)
    {
        if(min>n%10)
            min=n%10;
        n/=10;
    }
    return min;

}
int main()
{
	int n;
	cin>>n;
	cout<<smallest_digit(n);
	return 0;
}
