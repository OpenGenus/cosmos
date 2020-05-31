// Play Fair Cipher in C++

// Link to the Article(Explanation): https://iq.opengenus.org/play-fair-cipher/
#include <iostream>
#include <cstdlib>
#define dim 5 //dimension 5x5

std::string resulttext;
char matrix[dim][dim], choosechar(int a, int b);
bool chooseindex(char l, int &a, int &b);
void formmatrix(std::string k, bool ij);

//e_d: Encryption or Decryption(true/false)
std::string play_fair(std::string key, std::string text, bool ij, int e_d)
{
    formmatrix(key, ij);
    for (std::string::iterator i = text.begin(); i != text.end(); ++i)
    {
        *i = toupper(*i);
        if (*i < 65 || *i > 90)
            continue;
        if (*i == 'J' && ij)
            *i = 'I';
        else if (*i == 'Q' && !ij)
            continue;
        resulttext += *i;
    }
    if (e_d)
    {
        std::string temptext = "";
        size_t len = resulttext.length();
        for (size_t x = 0; x < len; x += 2)
        {
            temptext += resulttext[x];
            if (x + 1 < len)
            {
                if (resulttext[x] == resulttext[x + 1])
                    temptext += 'X';
                temptext += resulttext[x + 1];
            }
        }
        resulttext = temptext;
    }
    if (resulttext.length() & 1)
        resulttext += 'X';

    int a, b, c, d;
    std::string tempresult = "";
    for (std::string::const_iterator i = resulttext.begin(); i != resulttext.end(); ++i)
    {
        if (chooseindex(*i++, a, b))
            if (chooseindex(*i, c, d))
            {
                if (a == c)
                {
                    tempresult += choosechar(a, b + e_d);
                    tempresult += choosechar(c, d + e_d);
                }
                else if (b == d)
                {
                    tempresult += choosechar(a + e_d, b);
                    tempresult += choosechar(c + e_d, d);
                }
                else
                {
                    tempresult += choosechar(c, b);
                    tempresult += choosechar(a, d);
                }
            }
    }
    resulttext = tempresult;
    return resulttext;
}

char choosechar(int a, int b)
{
    return matrix[(b + dim) % dim][(a + dim) % dim];
}

bool chooseindex(char character, int &a, int &b)
{
    for (int y = 0; y < dim; ++y)
        for (int x = 0; x < dim; ++x)
            if (matrix[y][x] == character)
            {
                a = x;
                b = y;
                return true;
            }
    return false;
}

void formmatrix(std::string key, bool ij)
{
    if (key.length() < 1)
        key = "";
    key += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string tempKey = "";
    for (std::string::iterator i = key.begin(); i != key.end(); ++i)
    {
        *i = toupper(*i);
        if (*i < 65 || *i > 90)
            continue;
        if ((*i == 'J' && ij) || (*i == 'Q' && !ij))
            continue;
        if (tempKey.find(*i) == -1)
            tempKey += *i;
    }
    copy(tempKey.begin(), tempKey.end(), &matrix[0][0]);
}

int main(int argc, char *argv[])
{
    std::string key = "harry", plaintext = "my name is ravi", encryptedtext, decryptedtext;

    /*
    //Custom Input:
    cout << "Enter The Key: ";
    getline(cin, key);
    cout << "\nEnter the Plain Text to Encrypt: ";
    getline(cin, plaintext);
    */
    std::cout << "\nPlain Text is : " << plaintext;
    encryptedtext = play_fair(key, plaintext, true, 1);
    std::cout << "\n\nEncrypted Text is : " << encryptedtext;
    decryptedtext = play_fair(key, encryptedtext, true, -1);
    decryptedtext = decryptedtext.substr(0, decryptedtext.length() / 2);
    std::cout << "\nDecrypted Text is: " << decryptedtext;

    return 0;
}

/*
Sample Output:

Plain Text is : my name is ravi
Encrypted Text is : SFKBLFMOYRUK
Decrypted Text is: MYNAMEISRAVI
*/
