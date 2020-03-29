#include <iostream>
#include <math.h>

#define textlen 3 //Change the length of Plain Text here
#define ascii_difference 31

double encrypted[textlen][1], decrypted[textlen][1], key[textlen][textlen], cipherkey[textlen][textlen], message[textlen][1], ar[textlen][textlen];

void encryption();
void decryption();
void getdata();
void findinginverse();

int main()
{
	getdata();
	encryption();
	decryption();
}

int charconversion(char input_char)
{
	return (input_char & ascii_difference);
}

void encryption()
{
	for (int i = 0; i < textlen; ++i)
	{
		for (int j = 0; j < 1; ++j)
		{
			for (int k = 0; k < textlen; ++k)
			{
				encrypted[i][j] = encrypted[i][j] + key[i][k] * message[k][j];
			}
		}
	}
	std::cout << "\nEncrypted Text is: ";
	for (int i = 0; i < textlen; ++i)
	{
		std::cout << (char)(fmod(encrypted[i][0], 26) + 97);
	}
}

void decryption()
{
	findinginverse();
	for (int i = 0; i < textlen; ++i)
	{
		for (int j = 0; j < 1; ++j)
		{
			for (int k = 0; k < textlen; ++k)
			{
				decrypted[i][j] = decrypted[i][j] + cipherkey[i][k] * encrypted[k][j];
			}
		}
	}

	std::cout << "\nDecrypted Text is: ";
	for (int i = 0; i < textlen; ++i)
	{
		std::cout << (char)(fmod(decrypted[i][0], 26) + 97);
	}

	std::cout << "\n";
}

void getdata()
{
	char msg[textlen];

	std::cout << "Enter the Key in Text(It should be inversible):\n";
	char text[textlen][textlen];
	for (int i = 0; i < textlen; ++i)
	{
		for (int j = 0; j < textlen; ++j)
		{
			std::cin >> text[i][j];
		}
	}

	for (int i = 0; i < textlen; ++i)
	{
		for (int j = 0; j < textlen; ++j)
		{
			if ((text[i][j] >= 65 && text[i][j] <= 90) || (text[i][j] >= 97 && text[i][j] <= 122))
			{
				key[i][j] = charconversion(text[i][j]) - 1;
			}
			ar[i][j] = key[i][j];
		}
	}

	std::cout << std::endl
			  << "Equivalent Matrix: " << std::endl;
	for (int i = 0; i < textlen; ++i)
	{
		for (int j = 0; j < textlen; ++j)
		{
			std::cout << ar[i][j] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl
			  << std::endl;

	std::cout << "\nEnter the Plain Text that you want to Encrypt: ";
	std::cin >> msg;

	for (int i = 0; i < textlen; ++i)
	{
		message[i][0] = msg[i] - 97;
	}
}

//Finding Inverse Matrix for Decryption
void findinginverse()
{
	double p, q;

	for (int i = 0; i < textlen; ++i)
	{
		for (int j = 0; j < textlen; ++j)
		{
			if (i == j)
				cipherkey[i][j] = 1;
			else
				cipherkey[i][j] = 0;
		}
	}

	for (int k = 0; k < textlen; ++k)
	{
		for (int i = 0; i < textlen; ++i)
		{
			p = ar[i][k];
			q = ar[k][k];

			for (int j = 0; j < textlen; ++j)
			{
				if (i != k)
				{
					ar[i][j] = ar[i][j] * q - p * ar[k][j];
					cipherkey[i][j] = cipherkey[i][j] * q - p * cipherkey[k][j];
				}
			}
		}
	}
	for (int i = 0; i < textlen; ++i)
	{
		for (int j = 0; j < textlen; ++j)
		{
			cipherkey[i][j] = cipherkey[i][j] / ar[i][i];
		}
	}

	//This is to print Inverse Matrix.
	/*
	cout << "\n\nInverse Matrix is:\n";
	for (i = 0; i < textlen; ++i)
	{
		for (j = 0; j < textlen; ++j) {
			std::cout << cipherkey[i][j] << " ";
		}
		std::cout << "\n";
	}
	*/
}

/*
Test-Case: 1
Input:

Enter the Key in Text(It should be inversible): babceadfg
Enter the Plain Text that you want to Encrypt: fnc

Output:
Equivalent Matrix:
1 0 1
2 4 0
3 5 6

Encrypted Text is: hko
Decrypted Text is: fnc

Test-Case: 2
Input:

Enter the Key in Text(It should be inversible): gybnqkurp
Enter the Plain Text that you want to Encrypt: act

Output:
Equivalent Matrix:
6 24 1
13 16 10
20 17 15

Encrypted Text is: poh
Decrypted Text is: act
*/
