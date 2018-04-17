#include <iostream>
#include <string>
#include <map>

std::string integerToRoman(int number);

int main()
{
    int number;

    std::cout << "Enter a number: ";
    std::cin >> number;

    std::cout << "\nYour number: " << number << "\n";
    std::cout << "Your number in Roman Numerals: " << integerToRoman(number) << "\n";
}

std::string integerToRoman(int number)
{
    static std::map<int, std::string> romanNumerals
    {
        {1000, "M"},
        {900, "CM"},
        {500, "D"},
        {400, "CD"},
        {100, "C"},
        { 90, "XC"},
        { 50, "L"},
        { 40, "XL"},
        { 10, "X"},
        { 9, "IX"},
        { 5, "V"},
        { 4, "IV"},
        { 1, "I"}
    };

    std::string result;

    for (auto it = romanNumerals.rbegin(); it != romanNumerals.rend(); ++it)
        while (number >= it->first)
        {
            result += it->second;
            number -= it->first;
        }

    return result;
}
