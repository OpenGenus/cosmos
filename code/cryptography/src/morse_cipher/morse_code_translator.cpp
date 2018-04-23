//
// Created by miszk on 10/4/2017.
//

#include <map>
#include <iostream>
using std::string;
using std::cin;
using std::cout;
using std::endl;

std::map<std::string,
         string> dictionary =
{ {"A", ".-"}, { "B", "-..."}, { "C", "-.-."}, { "D", "-.."}, { "E", "."}, { "F", "..-."},
  { "G", "--."}, { "H", "...."}, { "I", ".."}, { "J", ".---"}, { "K", "-.-"}, { "L", ".-.."},
  { "M", "--"}, { "N", "-."}, { "O", "---"}, { "P", ".--."}, { "Q", "--.-"}, { "R", ".-."},
  { "S", "..."}, { "T", "-"}, { "U", "..-"}, { "V", "...-"}, { "W", ".--"}, { "X", "-..-"},
  { "Y", "-.--"}, { "Z", "--.."}, { "1", ".----"}, { "2", "..---"}, { "3", "...--"},
  { "4", "....-"}, { "5", "....."}, { "6", "-...."}, { "7", "--..."}, { "8", "---.."},
  { "9", "----."}, { "0", "-----"}, { "}, {", "--..--"}, { ".", ".-.-.-"}, { "?", "..--.."},
  { "/", "-..-."}, { "-", "-....-"}, { "(", "-.--."}, { ")", "-.--.-"}};

// Function to encrypt the string according to the morse code chart
string encrytp(string message)
{
    string encrypted = "";
    string to_string;

    for (char c : message)
    {
        //check if char is a letter
        if (c != ' ')
        {
            //add morse letter (first make it uppercase letter 'cause we'll search for it in our dictionary)
            to_string = toupper(c);
            encrypted += dictionary.find(string(to_string))->second;
            //add a space to separate morse letters
            encrypted += " ";
        }
        else
            encrypted += " ";
    }

    return encrypted;
}


// Function to decrypt the string from morse to english
string decrypt (string message)
{
    string morse_letter = "";
    string decrypted = "";

    for (char i : message)
    {
        // check for space or the end of current morse letter
        if (i == ' ')
        {

            if (morse_letter.length() != 0)
            {
                // it's the end of morse letter
                //search for key in dictionary
                for (auto o : dictionary)
                    if (o.second == morse_letter)
                    {
                        decrypted += o.first;
                        break;
                    }
                morse_letter = "";
            }
            else
                //it's just a space -- we copy it
                decrypted += " ";
        }
        else
            morse_letter += i;
    }
    return decrypted;
}


int main()
{

    string msg = "alice killed bob";
    string morse_msg = ".- .-.. .. -.-. .  -.- .. .-.. .-.. . -..  -... --- -... ";
    cout << encrytp(msg) << endl << decrypt(morse_msg) << endl;

    return 0;
}
