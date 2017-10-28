#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
	string data, key;
	cin >> data >> key;

	int num = 0;
	for ( int i = 0 ; argv[1][i] != '\0' ; i++ )
	{
		int d = argv[1][i]-48;
		num = num * 10 + d;
	}

	int n = data.length();
	int r = num % n;
	if ( data[r] == '0' )
		data[r] = '1';
	else
		data[r] = '0';
	cout << data << endl;
	cout << key << endl;	
}