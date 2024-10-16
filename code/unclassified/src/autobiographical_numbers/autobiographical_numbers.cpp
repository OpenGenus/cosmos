// Part of OpenGenus Cosmos
#include <iostream>
#include <string>
#include <unordered_map>

int main()
{    
    std::string s2 = "22535320";				// Input string
    // string s2 = "72100001000";               // Uncomment this for a "TRUE" answer example.
    
    std::unordered_map<int, int> indexCounter;
    std::unordered_map<int, int> eleCounter;
    
    int index = 0;
    for (char c : s2)
    {
        indexCounter[index] = (c - '0');	// c - '0' converts the char to a proper integer.
        index++;
    }

    for (char c : s2)
        eleCounter[(c - '0')]++;			// c - '0' converts the char to a proper integer.

    for (auto &par : indexCounter)
    {
        if (eleCounter[par.first] != par.second)
        {
            std::cout << "false" << std::endl;
            return 0;
            // return false;
        }
    }
    // return true;
    std::cout << "true" << std::endl;
}
