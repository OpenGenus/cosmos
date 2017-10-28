#include <iostream>
#include <string>
using namespace std;


string xora(string a, string b)
{
	string res = "";
	for ( int i = 1 ; i < b.length() ; i++ )
	{
		if ( a[i] == b[i] )
			res += '0';
		else
			res += '1';
	}
	return res;
}

string mod2div(string divident, string divisor)
{
	int n = divident.length();
	int pick = divisor.length();
	string zero = "";
	for ( int i = 0 ; i < pick ; i++ )
		zero += '0';
	string tmp = divident.substr(0,pick);

	while ( pick < n )
	{
		if ( tmp[0] == '1' )
			tmp = xora(divisor, tmp) + divident[pick];
		else
			tmp = xora(zero, tmp) + divident[pick];
		pick++;
	}

	if ( tmp[0] == '1' )
		tmp = xora(divisor, tmp);
	else
		tmp = xora(zero, tmp);
	return tmp;
}

bool verify(string data, string key)
{
	int k = key.length();

	string pad_data = data;
	for ( int i = 0 ; i < k-1 ; i++ )
	{
		pad_data += "0";
	}

	string remainder = mod2div(pad_data, key);

	for ( int i = 0 ; i < remainder.length() ; i++ )
	{
		if ( remainder[i] == '1' )
			return 0;
	}
	return 1;
}	

int main()
{
	string data, key;
	cin >> data >> key;

	if ( verify(data, key) )
		cout << "CRC Check PASS\n";
	else
		cout << "CRC Check FAIL\n";
}