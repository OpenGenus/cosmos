#include <iostream>
#include <string>

int main()
{
    std::string plaintext = "DEFENDTHEEASTWALLOFTHECASTLE";
    std::string key = "HOWDOESTHEDUCKKNOWTHATSAIDVI";
    std::string ciphertext;
    
    for (size_t i = 0; i < plaintext.size(); i++)
    {
        if (isalpha(plaintext[i]) && isalpha(key[i]))
        {
            int plaintextIndex = toupper(plaintext[i]) - 'A';
            int keyIndex = toupper(key[i]) - 'A';
            
            int resultIndex = (plaintextIndex + keyIndex) % 26;
            
            ciphertext += char(resultIndex + 'A');
        }
    }
    
    std::cout << ciphertext << '\n';    //  prints 'KSBHBHLALIDMVGKYZKYAHXUAAWGM'
}
