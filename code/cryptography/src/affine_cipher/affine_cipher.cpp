/* Part of Cosmos by OpenGenus Foundation */
#include <iostream>
#include <string>

/*
 * Affine Cipher: each alphabet letter is maped by a linear function to its numeric equivalent
 * and converted to letter again.
 *
 * Let x, y, a, b ∈ Z(26)
 * >> Encryption: Eĸ(x) = y ≡ a * x + b mod 26
 * >> Decryption: Dĸ(y) = x ≡ a-¹ * ( y - b) mod 26
 *
 * with the key ĸ = (a,b), which has the restriction: gcd(a, 26) = 1.
 *
 */

/*
 * getChar returns the char letter in alphabet with the modulo's position
 * in the ring
 */
char getChar(int n)
{
    char a = 'a';
    int n_ = n % 26;
    if (n_ < 0)
        n_ += 26;             // It's necessary because e.i. -1 % 26 = -1. (In Python it works better)
    return a + n_;
}

/*
 * a and b are the ĸey pair (a, b)
 * Recall: Encryption: Eĸ(x) = y ≡ a * x + b mod 26
 */
void crypter(std::string *plain_text, int a, int b)
{
    for (auto &letter:*plain_text)
    {
        int letter_ = letter - 97;         // 97 is the 'a' position in char
        letter = getChar((a * letter_) + b);
    }
}

/*
 *  Recall: Decryption: Dĸ(y) = x ≡ a-¹ * ( y - b) mod 26
 */
void decrypter(std::string *cipher_text, int a, int b)
{
    // Supose that (a) is inversible. Let's find (a)-¹
    // There is a number in the open-closed range [0, 26) such that a-¹ * (invertor) ≡  1 mod 26
    int invertor = 0;
    for (auto i(0ul); i < 26; i++)
        if ( (a * i) % 26 == 1)
        {
            invertor = i;
            break;
        }

    for (auto &letter:*cipher_text)
    {
        int letter_ = letter - 97;
        letter = getChar(invertor * (letter_ - b) % 26);
    }
}

int main(void)
{
    int a = 3, b = 6;     // Remember that gcd(a, 26) must be equals to 1.

    std::string text = "palavraz";

    std::cout << ">>> Original plain text: " << text << std::endl;
    // Encryption pass
    std::cout << ">>>     Encryption function with the key pair (" << a << ", " << b << ")" <<
        std::endl;
    crypter(&text, a, b);
    std::cout << ">>> Generated cipher text: " << text << std::endl;

    // Decryption pass
    std::cout << ">>>     Decryption function with the key pair (" << a << ", " << b << ")" <<
        std::endl;
    decrypter(&text, a, b);
    std::cout << ">>> Decrypted plain text: " << text << std::endl;
}
