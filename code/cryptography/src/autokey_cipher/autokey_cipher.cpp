#include <iostream>

std::string autokeycipher(std::string text, char key, int encrypt)
{
    for (int i = 0; i < text.length(); ++i)
    {
        if (isalpha(text[i]))
        {
            text[i] = toupper(text[i]);
        }
    }

    int nextkey, keyvalue, result;
    nextkey = toupper(key) - 'A';

    for (int i = 0; i < text.length(); ++i)
    {
        if (isalpha(text[i]))
        {
            keyvalue = nextkey;
            if (encrypt)
            {
                nextkey = text[i] - 'A';
                text[i] = (text[i] - 'A' + keyvalue) % 26 + 'A';
            }
            else
            {
                result = (text[i] - 'A' - keyvalue) % 26 + 'A';
                text[i] = result < 'A' ? (result + 26) : (result);
                nextkey = text[i] - 'A';
            }
        }
    }
    return text;
}

int main(int argc, char **argv)
{
    char key;
    std::string plaintext;

    std::cout << "Enter the Single Key word: ";
    std::cin >> key;

    std::cout << "Enter the Plain Text: ";
    std::cin >> plaintext;

    std::cout << std::endl
              << "The Plain Text is: " << plaintext;

    /* 3rd argument decides whither to do 1-Encryption or 0-Decryption. */
    std::string ciphertext = autokeycipher(plaintext, key, 1);
    std::cout << std::endl
              << "The Text after Encryption(Cipher text) is: " << ciphertext;

    std::string decryptedtext = autokeycipher(ciphertext, key, 0);
    std::cout << std::endl
              << "After Decryption the Text is: " << decryptedtext;

    return 0;
}

/*
Sample Input:
Enter the Single Key word: L //In A-Z, L will be at 11 index.
Enter the Plain Text: hello

Sample Output:
The Plain Text is: hello
The Text after Encryption(Cipher text) is: slpwz
After Decryption the Text is: hello
*/
