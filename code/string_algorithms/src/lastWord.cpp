#include <iostream>
#include <string>
using namespace std;


int lengthLastWord(string str) {

	int index = str.find_last_of(' ');
	string lastWord = str.substr(index + 1);
	return lastWord.length();

}


int main()
{
	string str = "Hello welcome to my computer";
	int index = str.find_last_of(' ');

	cout << str << endl;
	cout << "Last word is: " << str.substr(index + 1) << endl;
	cout << "Length of last word is: " << lengthLastWord(str) << endl;

}