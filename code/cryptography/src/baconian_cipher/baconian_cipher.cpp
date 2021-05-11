#include <map>
#include <string>

// Part of Cosmos by OpenGenus Foundation
// This function generates a baconian map
std::map<char, std::string> createBaconianMap()
{
    std::map<char, std::string> cipher;
    std::string static alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string value;
    for (std::size_t i = 0; i < alphabet.length(); ++i)
    {
        for (std::size_t j = 0; j < 5; ++j)
            ((i & (1 << j)) == 0) ? value = 'A' + value : value = 'B' + value;
        char key = alphabet[i];
        cipher[key] = value;
        value.clear();
    }

    return cipher;
}

std::string encrypt(std::map<char, std::string>& cipher, std::string message)
{
    std::string newMessage;
    for (std::size_t i = 0; i < message.length(); ++i)
        (message[i] !=
         ' ') ? newMessage.append(cipher[char(toupper(message[i]))]) : newMessage.append(" ");

    return newMessage;
}

std::string decrypt(std::map <char, std::string>& cipher, std::string message)
{
    std::string newMessage;
    std::string currentString;
    int currentStringLength = 0;
    for (std::size_t i = 0; i < message.length() + 1; ++i)
    {
        if (currentStringLength == 5)
        {
            std::map<char, std::string>::iterator it = cipher.begin();
            while (it->second != currentString)
                ++it;
            newMessage += it->first;
            currentString.clear();
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
