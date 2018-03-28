#include <map>
#include <string>

#define VALUE_LENGTH 5 // The length of a value in a key value pair for a baconian cipher

// Part of Cosmos by OpenGenus Foundation
// Typed out map
std::map<char, std::string> cipher = {
{ 'A', "AAAAA" }, { 'B', "AAAAB" }, { 'C', "AAABA" },
{ 'D', "AAABB" }, { 'E', "AABAA" }, { 'F', "AABAB" }, 
{ 'G', "AABBA" }, { 'H', "AABBB" }, { 'I', "ABAAA" }, 
{ 'J', "ABAAB" }, { 'K', "ABABA" }, { 'L', "ABABB" }, 
{ 'M', "ABBAA" }, { 'N', "ABBAB" }, { 'O', "ABBBA" }, 
{ 'P', "ABBBB" }, { 'Q', "BAAAA" }, { 'R', "BAAAB" }, 
{ 'S', "BAABA" }, { 'T', "BAABB" }, { 'U', "BABAA" }, 
{ 'V', "BABAB" }, { 'W', "BABBA" }, { 'X', "BABBB" }, 
{ 'Y', "BBAAA" }, { 'Z', "BBAAB" } 
};

// This function generates the exact map typed above
std::map<char, std::string> createBaconianMap()
{
    std::map<char, std::string> cipher;
    std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string value = "";
    for (int i = 0; i < alphabet.length(); i++) 
    {
        for (int j = 0; j < VALUE_LENGTH; j++)
        {
	    if ((i & (1 << j)) == 0)
                value = 'A' + value;
            else
                value = 'B' + value;
        }
        char key = alphabet[i];
        cipher[key] = value;
        value = "";
    }
    return cipher;
}

std::string encrypt(std::map<char, std::string> &cipher, std::string message)
{
    std::string newMessage = "";
    for (int i = 0; i < message.length(); i++)
    {
        if (message[i] != ' ')
            newMessage.append(cipher[char(toupper(message[i]))]);
        else
            newMessage.append(" ");
    }
    return newMessage;
}

std::string decrypt(std::map <char, std::string> &cipher, std::string message)
{
    std::string newMessage = "";
    std::string currentString = "";
    int currentStringLength = 0;
    for (int i = 0; i < message.length() + 1; i++)
    {
        if (currentStringLength == VALUE_LENGTH)
        {
	    std::map<char, std::string>::iterator it = cipher.begin();
            while (it->second != currentString)
                it++;
            newMessage += it->first;
            currentString = "";
            currentStringLength = 0;
        }
        
        if (message[i] == ' ')
            newMessage.append(" ");   
        else
        {
            currentString += message[i];
            currentStringLength++;
        }
    }
    return newMessage;
}
