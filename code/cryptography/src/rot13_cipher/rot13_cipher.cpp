#include <string>
#include <iostream>
#include <cctype>

std::string rot13(const std::string &text)
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
            c += 13;
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
    std::cout << rot13("Hello, world!") << "\n";  // Outputs "Uryyb, jbeyq!"
    std::cout << rot13("Uryyb, jbeyq!") << "\n";  // Output "Hello, world!"

    return 0;
}
