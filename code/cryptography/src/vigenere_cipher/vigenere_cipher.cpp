#include <iostream>
#include <string>

class Vigenere
{
public:
    Vigenere(const std::string& key)
    {
        for (size_t i = 0; i < key.size(); ++i)
        {
            if (key[i] >= 'A' && key[i] <= 'Z')
                this->key += key[i];
            else if (key[i] >= 'a' && key[i] <= 'z')
                this->key += key[i] + 'A' - 'a';
        }
    }

    std::string encrypt(const std::string& text)
    {
        std::string result;

        for (size_t i = 0, j = 0; i < text.length(); ++i)
        {
            char c = text[i];

            if (c >= 'a' && c <= 'z')
                c += 'A' - 'a';
            else if (c < 'A' || c > 'Z')
                continue;

            result += (c + key[j] - 2 * 'A') % 26 + 'A';
            j = (j + 1) % key.length();
        }

        return result;
    }

    std::string decrypt(const std::string& text)
    {
        std::string result;

        for (size_t i = 0, j = 0; i < text.length(); ++i)
        {
            char c = text[i];

            if (c >= 'a' && c <= 'z')
                c += 'A' - 'a';
            else if (c < 'A' || c > 'Z')
                continue;

            result += (c - key[j] + 26) % 26 + 'A';
            j = (j + 1) % key.length();
        }

        return result;
    }
    
private:
    std::string key;
};

int main()
{
    Vigenere cipher{"VIGENERECIPHER"};

    std::string original =
            "Beware the Jabberwock, my son! The jaws that bite, the claws that catch!";
    std::string encrypted = cipher.encrypt(original);
    std::string decrypted = cipher.decrypt(encrypted);

    std::cout << original << "\n";
    std::cout << "Encrypted: " << encrypted << "\n";
    std::cout << "Decrypted: " << decrypted << "\n";
}
