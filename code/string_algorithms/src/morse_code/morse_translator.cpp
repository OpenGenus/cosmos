#include <iostream>
#include <map>

using namespace std;

string wordToMorse(string input, map<string,string> mp, map<string,string>::iterator it);
string morseToWord(string input, map<string,string> mp, map<string,string>::iterator it);

int main() 
{
    map <string,string> key;
    map <string,string> :: iterator it;

    key["A"] = ".-";
    key["B"] = "-...";
    key["C"] = "-.-.";
    key["D"] = "-..";
    key["E"] = ".";
    key["F"] = "..-.";
    key["G"] = "--.";
    key["H"] = "....";
    key["I"] = "..";
    key["J"] = ".---";
    key["K"] = "-.-";
    key["L"] = ".-..";
    key["M"] = "--";
    key["N"] = "-.";
    key["O"] = "---";
    key["P"] = ".--.";
    key["Q"] = "--.-";
    key["R"] = ".-.";
    key["S"] = "...";
    key["T"] = "-";
    key["U"] = "..-";
    key["V"] = "...-";
    key["W"] = ".--";
    key["X"] = "-..-";
    key["Y"] = "-.--";
    key["Z"] = "--..";
    key["1"] = ".----";
    key["2"] = "..---";
    key["3"] = "...--";
    key["4"] = "....-";
    key["5"] = ".....";
    key["6"] = "-....";
    key["7"] = "--...";
    key["8"] = "---..";
    key["9"] = "----.";
    key["0"] = "-----";
    key[".-"] = "A";
    key["-..."] = "B";
    key["-.-."] = "C";
    key["-.."] = "D";
    key["."] = "E";
    key["..-."] = "F";
    key["--."] = "G";
    key["...."] = "H";
    key[".."] = "I";
    key[".---"] = "J";
    key["-.-"] = "K";
    key[".-.."] = "L";
    key["--"] = "M";
    key["-."] = "N";
    key["---"] = "O";
    key[".--."] = "P";
    key["--.-"] = "Q";
    key[".-."] = "R";
    key["..."] = "S";
    key["-"] = "T";
    key["..-"] = "U";
    key["...-"] = "V";
    key[".--"] = "W";
    key["-..-"] = "X";
    key["-.--"] = "Y";
    key["--.."] = "Z";
    key[".----"] = "1";
    key["..---"] = "2";
    key["...--"] = "3";
    key["....-"] = "4";
    key["....."] = "5";
    key["-...."] = "6";
    key["--..."] = "7";
    key["---.."] = "8";
    key["----."] = "9";
    key["-----"] = "0";

    cout << morseToWord(".-- .... -.-- / .. / .- -- / .... . .-. .", key, it) << endl;
    cout << wordToMorse("opengeNuS", key, it) << endl;

	return 0;
}

string wordToMorse(string input, map<string,string> mp, map<string,string>::iterator it) 
{
	string encoded = "", temp = "";
	for(int i = 0; i < input.length(); i++) 
	{
		if(input[i] == ' ')
			encoded += '/';
		else 
		{
			if(islower(input[i]))
				input[i] = toupper(input[i]);
			temp  = input[i];
			it = mp.find(temp);
			encoded += it->second + " ";
		}
	}
	return encoded;
}

string morseToWord(string input, map<string,string> mp, map<string,string>::iterator it) 
{
	input += " ";
	string decoded = "",temp = "";
	for(int i = 0; i < input.length(); i++) 
	{
		if(input[i] != ' ' && input[i] != '/') 
		{
			temp += input[i];
		}
		else if(input[i] == ' ') 
		{
			it = mp.find(temp);
			decoded += it->second;	
			temp = "";
		}
		else if(input[i] == '/')
			decoded += " ";
	}
	return decoded;
}
