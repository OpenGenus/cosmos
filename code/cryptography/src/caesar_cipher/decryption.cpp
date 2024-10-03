#include <iostream>

using namespace std;

int main()
{
    char message[100], ch;
    int i, key;

    cout << "Enter a message to decrypt: ";
    cin.getline(message, 100);
    cout << "Enter key: ";
    cin >> key;

    //Traverses the ciphertext
    for (i = 0; message[i] != '\0'; ++i)
    {
        ch = message[i];

        if (ch >= 'a' && ch <= 'z')     //Checks if the character of ciphertext is a lowercase alphabet
        {
            ch = ch - key;              //Performs decryption

            if (ch < 'a')                     //If character goes below lowercase a
                ch = ch + 'z' - 'a' + 1;      //then we bring it within the range of lowercase a to z

            message[i] = ch;
        }
        else if (ch >= 'A' && ch <= 'Z')    //Checks if the character of ciphertext is a uppercase alphabet
        {
            ch = ch - key;                  //Performs decryption

            if (ch > 'a')                   //If character goes above lowercase a
                ch = ch + 'Z' - 'A' + 1;    //then we bring it within the range of uppercase A to Z

            message[i] = ch;
        }
    }

    cout << "Decrypted message: " << message;

    return 0;
}
