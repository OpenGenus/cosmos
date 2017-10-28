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

string generate(string data, string key)
{
	int k = key.length();
	string pad_data = data;
	for ( int i = 0 ; i < k-1 ; i++ )
	{
		pad_data += "0";
	}
	string remainder = mod2div(pad_data, key);
	string enocded_data = data + remainder;

	return enocded_data;
}

int main()
{
	string data, key;
	cin >> data >> key;

	string generated = generate(data, key);
	cout << generated << endl;
	cout << key << endl;
}