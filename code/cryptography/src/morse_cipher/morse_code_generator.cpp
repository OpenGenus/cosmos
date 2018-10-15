//C++ implemention of morse code generator
#include <iostream>
using namespace std;
#include <map>                     //For map data structure

// Encryption Function
void encryption(string msg)
{
    // Decalaring map structure and Defination of map
    map<char, string> encrypt;
    encrypt['A'] = ".-"; encrypt['B'] = "-..."; encrypt['C'] = "-.-."; encrypt['D'] = "-..";
    encrypt['E'] = "."; encrypt['F'] = "..-."; encrypt['G'] = "--."; encrypt['H'] = "....";
    encrypt['I'] = ".."; encrypt['J'] = ".---"; encrypt['K'] = "-.-"; encrypt['L'] = ".-..";
    encrypt['M'] = "--"; encrypt['N'] = "-."; encrypt['O'] = "---"; encrypt['P'] = ".--.";
    encrypt['Q'] = "--.-"; encrypt['R'] = ".-."; encrypt['S'] = "..."; encrypt['T'] = "-";
    encrypt['U'] = "..-"; encrypt['V'] = "...-"; encrypt['W'] = ".--"; encrypt['X'] = "-..-";
    encrypt['Y'] = "-.--"; encrypt['Z'] = "--..";
    encrypt['1'] = ".----"; encrypt['2'] = "..---"; encrypt['3'] = "...--"; encrypt['4'] = "....-";
    encrypt['5'] = "....."; encrypt['6'] = "-...."; encrypt['7'] = "--...";
    encrypt['8'] = "---.."; encrypt['9'] = "----."; encrypt['0'] = "-----";

    string cipher;
    for (size_t i = 0; i < msg.size(); i++)
    {
        if (msg[i] != ' ')
            cipher = cipher + encrypt[msg[i]] + " ";
        else
            cipher = cipher + "  ";
    }
    cout << cipher;
}
//Driver program
int main()
{
    string key = "CONVERT THIS TO MORSE CODE";
    //Calling Function
    encryption(key);
    return 0;
}
