#include <iostream>
#include <algorithm>
using namespace std;

string reverseIt(char* str)
{
	string st(str);
	reverse(st.begin(), st.end());
	return st;
}

int main(int argc, char* argv[])
{
	cout<<"Reversing "<<argc - 1<<" strings"<<endl;
	for (int i = 1; i < argc; i++)
	{
		cout<<"Original : "<<argv[i]<<"\tReversed : "<<reverseIt(argv[i])<<endl;
	}
	return 0;
}