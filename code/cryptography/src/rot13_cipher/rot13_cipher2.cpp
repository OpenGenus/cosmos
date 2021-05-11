#include <iostream>
#include <string>
#include <cctype>

using namespace std;

/// @brief Run rotation cipher on a string
/// @param text Text to encrypt
/// @param n Amount to shift by
/// @brief Encoded text
std::string rotN(const std::string &text, int n)
{
    std::string output;

    // Loop through input text
    for (auto c : text)
    {
        // Check if character is a letter
        if (isalpha(c))
        {
            // Subtract 'A' if uppercase, 'a' if lowercase
            char sub = (c >= 65 && c <= 90) ? 'A' : 'a';
            // Convert character to alphabet index starting from zero (0 - 25)
            c -= sub;
            // Shift
            c += n;
            // Wrap around
            c %= 26;
            // Convert back into ASCII and add to output
            output += (c + sub);
        }
        else
            output += c;
    }

    return output;
}

int main()
{
    // Example
    cout << rotN("Hello, world!", 13) << endl; // Outputs "Uryyb, jbeyq!"

    return 0;
}
