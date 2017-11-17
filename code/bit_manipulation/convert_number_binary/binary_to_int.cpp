// part of cosmos by opengenus foundation

#include <iostream>
#include <cmath>
using namespace std;

int bin_to_int(int bin)
{
	int number = 0;
	int i=0;
	while(bin != 0)
	{
		number += (bin%10) * pow(2, i);
		i++;
		bin/=10;
	}

	return number;
}

int main()
{
	cout<<bin_to_int(1010)<<endl;

	return 0;
}
