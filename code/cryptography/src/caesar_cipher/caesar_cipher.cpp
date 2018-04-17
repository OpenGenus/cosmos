// Part of Cosmos by OpenGenus Foundation

// A C++ program to illustrate Caesar Cipher Technique
#include <iostream>
using namespace std;

// returns the encrypted text
string caesarcipher(string text, int s)
{
    string result = "";

    // traverse text
    for (size_t i = 0; i < text.length(); i++)
    {
        //Takes care of spaces
        if (int(text[i]) == 32)
        {
            result += char(32);
            continue;
        }

        // Encrypt Uppercase letters
        if (isupper(text[i]))
            result += char(int(text[i] + s - 65) % 26 + 65);

        // Encrypt Lowercase letters
        else
            result += char(int(text[i] + s - 97) % 26 + 97);
    }

    // Return the resulting string
    return result;
}

int main()
{
    string text;
    cout << "\nEnter string to encrypt\n";
    getline(cin, text);
    int s;
    cout << "\nEnter no of shifts:\n";
    cin >> s;
    cout << "\nText : " << text;
    cout << "\nShift: " << s;
    text = caesarcipher(text, s);
    cout << "\nEncrypted: " << text;
    cout << "\nDecrypted: " << caesarcipher(text, 26 - s);
    return 0;
}
