#include <iostream>

int main()
{
    char c;
    std::cin >> c;
    if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        std::cout << "Vowel";
    else
        std::cout << "Consonant";
    return 0;
}
