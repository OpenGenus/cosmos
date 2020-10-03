#include <iostream>
#include <string>
#include <vector>

std::pair<char, std::string> pairing(char alpha, std::string morse_code);
std::string finder(const std::vector<std::pair<char, std::string>> &mp, std::string value);
std::string wordToMorse(const std::vector<std::pair<char, std::string>> &mp, std::string input);
std::string morseToWord(const std::vector<std::pair<char, std::string>> &mp, std::string input);

int main()
{
    std::vector<std::pair<char, std::string>> key;

    key.push_back(pairing('A', ".-"));
    key.push_back(pairing('B', "-..."));
    key.push_back(pairing('C', "-.-."));
    key.push_back(pairing('D', "-.."));
    key.push_back(pairing('E', "."));
    key.push_back(pairing('F', "..-."));
    key.push_back(pairing('G', "--."));
    key.push_back(pairing('H', "...."));
    key.push_back(pairing('I', ".."));
    key.push_back(pairing('J', ".---"));
    key.push_back(pairing('K', "-.-"));
    key.push_back(pairing('L', ".-.."));
    key.push_back(pairing('M', "--"));
    key.push_back(pairing('N', "-."));
    key.push_back(pairing('O', "---"));
    key.push_back(pairing('P', ".--."));
    key.push_back(pairing('Q', "--.-"));
    key.push_back(pairing('R', ".-."));
    key.push_back(pairing('S', "..."));
    key.push_back(pairing('T', "-"));
    key.push_back(pairing('U', "..-"));
    key.push_back(pairing('V', "...-"));
    key.push_back(pairing('W', ".--"));
    key.push_back(pairing('X', "-..-"));
    key.push_back(pairing('Y', "-.--"));
    key.push_back(pairing('Z', "--.."));
    key.push_back(pairing('1', ".----"));
    key.push_back(pairing('2', "..---"));
    key.push_back(pairing('3', "...--"));
    key.push_back(pairing('4', "....-"));
    key.push_back(pairing('5', "....."));
    key.push_back(pairing('6', "-...."));
    key.push_back(pairing('7', "--..."));
    key.push_back(pairing('8', "---.."));
    key.push_back(pairing('9', "---."));
    key.push_back(pairing('0', "-----"));

    std::cout << wordToMorse(key, "shobhit is a programmer") << std::endl;
    std::cout << morseToWord(key, "--- .--. . -. --. . -. ..- ...") << std::endl; // prints OPENGENUS

    return 0;
}
std::pair<char, std::string> pairing(char alpha, std::string morse_code)
{
    return std::make_pair(alpha, morse_code);
}
// returns the corresponding code for both alphabet and numbers & vice versa
std::string finder(const std::vector<std::pair<char, std::string>> &mp, std::string value)
{
    // to know where to search on (first index or second index)
    if (value[0] == '.' || value[0] == '-')
    {
        std::string val = "";
        for (const auto &it : mp)
            if (it.second == value)
            {
                val += it.first;
                return val;
            }
    }
    else
    {
        // it is used because length of any alphabet is 1
        char val = value[0];
        for (const auto &it : mp)
            if (it.first == val)
                return it.second;

    }
    return std::string{};
}
std::string wordToMorse(const std::vector<std::pair<char, std::string>> &mp, std::string input)
{
    std::string tempr, encoded = "";
    for (const auto& elem : input)
    {
        if (elem == ' ')
            encoded += '/';
        else
        {
            tempr = std::toupper(elem);
            tempr = finder(mp, tempr);
            encoded += tempr + " ";
        }
    }
    return encoded;
}
std::string morseToWord(const std::vector<std::pair<char, std::string>> &mp, std::string input)
{
    std::string new_input = input + " ", decoded = "", pseudo_morse = "";
    for (const auto& elem : input)
    {
        if (elem != ' ' && elem != '/')
            pseudo_morse += elem;
        else if (elem == ' ')
        {
            decoded += finder(mp, pseudo_morse);
            pseudo_morse.clear();
        }
        else
        {
            decoded += ' ';
            decoded += finder(mp, pseudo_morse);
            pseudo_morse.clear();
        }

    }
    return decoded;
}
