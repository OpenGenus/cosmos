#include <iostream>

//Part of Cosmos by OpenGenus Foundation
void removeDups(char *pStr)
{
    char *strTemp = pStr + 1;
    while (*strTemp != '\0')
    {

        if (*pStr != *strTemp)
        {
            pStr++;
            *pStr = *strTemp;
        }
        strTemp++;

    }
    pStr++;
    *pStr = '\0';
}

int main()
{
    char str[256];
    std::cout << "Enter string: " << std::endl;
    std::cin.getline(str, 256);
    removeDups(str);
    std::cout << "Resultant string: " << str << std::endl;
    return 0;
}
