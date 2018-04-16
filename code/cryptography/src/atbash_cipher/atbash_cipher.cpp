#include <iostream>
#include <string>
#include <cctype>
using namespace std;

//Atbash Cipher modified for English

string atbash(string s);
int main()
{
    string s;
    cout << "Enter message to encrypt/decrypt: ";
    getline(cin, s);
    cout << endl << atbash(s) << endl;
}

string atbash(string s)
{
    string newstr = "";
    for (size_t i = 0; i < s.length(); i++)
    {
        if (!isalpha(s[i]))
            newstr += s[i];
        else if (isupper(s[i]))
            newstr += (char)('Z' - (s[i] - 'A'));
        else
            newstr += (char)('z' - (s[i] - 'a'));
    }
    return newstr;
}
