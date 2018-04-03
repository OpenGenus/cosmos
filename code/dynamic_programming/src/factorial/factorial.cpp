#include <iostream>

int factorial(int n)
{
	if (n == 0 || n == 1)
		return 1;
	else
		return n * factorial(n - 1);
}

int main()
{
	int n;
	std::cout<<"Enter a Whole Number: ";
	std::cin>>n;
	std::cout<<n<<"! = "<<factorial(n)<<"\n";

	return 0;
}
