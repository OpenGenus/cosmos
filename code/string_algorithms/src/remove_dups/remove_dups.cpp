#include <iostream>

//Part of Cosmos by OpenGenus Foundation
void removeDups(std::string &str)
{
    std::string resStr;
    resStr.push_back(str.front());
    for (std::string::iterator it = str.begin() + 1; it != str.end(); ++it)
        if (*it != resStr.back())
            resStr.push_back(*it);

    std::swap(str, resStr);
}

int main()
{
    std::string str;
    std::cout << "Enter string: " << std::endl;
    std::getline(std::cin, str);
    removeDups(str);
    std::cout << "Resultant string: " << str << std::endl;
    return 0;
}
