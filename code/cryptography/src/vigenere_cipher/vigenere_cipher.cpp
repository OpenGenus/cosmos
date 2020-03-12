//C++ code for Vigenere Ciphere
#include <iostream>
#include <string>

class Vigenere
{
public:
    Vigenere(const std::string& key)
    {   //Traverses through the key
        for (size_t i = 0; i < key.size(); ++i)
        {
            if (key[i] >= 'A' && key[i] <= 'Z')     //Check if the character of key is an uppercase alphabet
                this->key += key[i];
            else if (key[i] >= 'a' && key[i] <= 'z')    //Check if the character of key is a lowercase alphabet
                this->key += key[i] + 'A' - 'a';
        }
    }

    //A function to perform encryption
    std::string encrypt(const std::string& text)
    {
        std::string result;
        //Traverses the plaintext
        for (size_t i = 0, j = 0; i < text.length(); ++i)  
        {
            char c = text[i];

            if (c >= 'a' && c <= 'z')       //Check if the character is a lowercase alphabet
                c += 'A' - 'a';             //Converts lowercase to uppercase characters
            else if (c < 'A' || c > 'Z')    //Check if the character is not an alphabet
                continue;

            result += (c + key[j] - 2 * 'A') % 26 + 'A';    //Encryption of character is put into result by adding key to plaintext
            j = (j + 1) % key.length();     //Increment j within length of key
        }

        return result;
    }

    //A function to perform decryption
    std::string decrypt(const std::string& text)
    {
        std::string result;

        //Traverses the ciphertext
        for (size_t i = 0, j = 0; i < text.length(); ++i)
        {
            char c = text[i];

            if (c >= 'a' && c <= 'z')       //Check if the character is a lowercase alphabet
                c += 'A' - 'a';             //Converts lowercase to uppercase characters
            else if (c < 'A' || c > 'Z')    //Check if the character is not an alphabet
                continue;

            result += (c - key[j] + 26) % 26 + 'A';     //Decryption of character is put into result by Subtracting key from ciphertext
            j = (j + 1) % key.length();             //Increment j within length of key
        }

        return result;
    }

private:
    std::string key;
};

int main()
{
    Vigenere cipher{"VIGENERECIPHER"};      //key is VIGENERECIPHER of length 14

    std::string original =
        "Beware the Jabberwock, my son! The jaws that bite, the claws that catch!";     //Plaintext
    std::string encrypted = cipher.encrypt(original);
    std::string decrypted = cipher.decrypt(encrypted);

    std::cout << original << "\n";
    std::cout << "Encrypted: " << encrypted << "\n";
    std::cout << "Decrypted: " << decrypted << "\n";
}
