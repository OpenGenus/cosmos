// part of cosmos from opengenus foundation

#include <iostream>
#include <algorithm>
using namespace std;

bool is_lapindrome(string _str_)
{
	int len = _str_.length();
	int mid = len/2;
	int delim = len%2 == 0 ? mid : mid + 1;

	string first = _str_.substr(0, mid);
	string second = _str_.substr(delim);

	sort(first.begin(), first.end());
	sort(second.begin(), second.end());

	return first == second;

}

int main()
{
	if(is_lapindrome("abccba"))
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;

	if(is_lapindrome("test_no_lapin"))
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;

	return 0;
}
