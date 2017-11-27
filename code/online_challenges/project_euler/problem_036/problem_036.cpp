#include <iostream>
#include <string>

std::string convertBase2(int number);
bool isPalindrome(const std::string& str);

int main()
{
    int sum = 0;
    
    for (int i = 1; i < 1000000; ++i)
    {
        if (isPalindrome(std::to_string(i)) && isPalindrome(convertBase2(i)))
        {
            sum += i;
        }
    }
    std::cout << sum << "\n";
}

std::string convertBase2(int number)
{
    std::string result;
    
    while (number > 0)
    {
        int currentBit = number % 2;
        int currentQuotient = number / 2;
        result += std::to_string(currentBit);
        number = currentQuotient;
    }
    
    return std::string{ result.rbegin(), result.rend() };
}

bool isPalindrome(const std::string& str)
{
    return str == std::string{ str.rbegin(), str.rend() };
}