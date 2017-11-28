#include <bitset>
#include <iostream>
#include <string>

std::string convertBase2(int number);
bool isPalindrome(const std::string& str);

int main()
{
    int sum = 0;
    
    for (int i = 1; i < 1000000; ++i)
    {
        std::string currentBinaryString = std::bitset<32>(i).to_string();
        currentBinaryString.erase(0, currentBinaryString.find('1')); // Remove leading zeroes
        if (isPalindrome(std::to_string(i)) && isPalindrome(currentBinaryString))
            sum += i;
    }
    std::cout << sum << "\n";
}

bool isPalindrome(const std::string& str)
{
    return str == std::string{ str.rbegin(), str.rend() };
}