#include <iostream>
#include <string>
#include<algorithm>
#include <cctype>
using namespace std;

void encrypt() {

	//A string variabe to hold all both small and capital aplhabets.
	string alphabets = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

	//Taking the key in input from user.
	string user_key;
	cout << "Enter 26 digit key : \n";
	cin >> user_key;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Used to flush out \n from buffer.

	//Converted user provded key to upper case and created final key having both upper and lower case letters.
	string upper_case_key = user_key;
	transform(upper_case_key.begin(), upper_case_key.end(), upper_case_key.begin(), ::toupper);
	string final_key = user_key.append(upper_case_key);

	//Printing both both alphabet and key.
	cout << "Aphabet :" << alphabets << endl;
	cout << "Key     :" << final_key << endl;

	//Taking input of plain text
	string ptext;
	cout << "\nEnter plain text to encrypt : ";
	getline(cin, ptext);

	cout << "Encrypted text : ";
	//Loop to encrypt text.
	for (int i = 0; i < ptext.size(); i++) {
		//If anything other tha alphabet entered the print it as it is.
		if (!isalpha(ptext[i])) {
			cout << ptext[i];
			continue;
		}
		char temp = ptext[i];
		int index = alphabets.find(temp);
		cout << final_key.at(index);

	}

}

void decrypt() {
	//Taking the key in input from user.
	string user_key;
	cout << "Enter 26 digit key : \n";
	cin >> user_key;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Used to flush out \n from buffer.

	//A string variabe to hold all both small and capital aplhabets.
	string alphabets = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

	//Converted user provded key to upper case and created final key having both upper and lower case letters.
	string upper_case_key = user_key;
	transform(upper_case_key.begin(), upper_case_key.end(), upper_case_key.begin(), ::toupper);
	string final_key = user_key.append(upper_case_key);


	//Printing both both alphabet and key.
	cout << "Aphabet :" << alphabets << endl;
	cout << "Key     :" << final_key << endl;

	//Swapping key and alphabets so that same code could perform decryption by reversing the process.
	string temp;
	temp = final_key;
	final_key = alphabets;
	alphabets = temp;

	//Taking input of ciphertext
	string ptext;
	cout << "\nEnter ciphertext to decrypt : ";
	getline(cin, ptext);

	cout << "Decrypted text : ";
	//Loop to decrypt text.
	for (int i = 0; i < ptext.size(); i++) {
		//If anything other than alphabet entered the print it as it is.
		if (!isalpha(ptext[i])) {
			cout << ptext[i];
			continue;
		}
		char temp = ptext[i];
		int index = alphabets.find(temp);
		cout << final_key.at(index);

	}
}
int main()
{
	int n;
label:
	cout << "1. Encrypt \n2. Decrypt \n";
	cout << "To enter your choice type 1 or 2 : ";
	cin >> n;
	if (n == 1)
		encrypt();
	else if (n == 2)
		decrypt();
	else {
		cout << "\nWrong choice";
		goto label;
	}
	return 0;
}
