#include <iostream>
#include <math.h>
using namespace std;

#define textLen 3 //Change the length of Plain Text here
#define ASCII_difference 31

double Encrypted[textLen][1], Decrypted[textLen][1], key[textLen][textLen], cipherKey[textLen][textLen], message[textLen][1], ar[textLen][textLen];

void Encryption();
void Decryption();
void getData();
void FindingInverse();

int main()
{
	getData();
	Encryption();
	Decryption();
}

int charConversion(char input_char)
{
	return (input_char & ASCII_difference);
}

void Encryption()
{
	int i, j, k;
	for (i = 0; i < textLen; i++)
	{
		for (j = 0; j < 1; j++)
		{
			for (k = 0; k < textLen; k++)
			{
				Encrypted[i][j] = Encrypted[i][j] + key[i][k] * message[k][j];
			}
		}
	}
	cout << "\nEncrypted Text is: ";
	for (i = 0; i < textLen; i++)
	{
		cout << (char)(fmod(Encrypted[i][0], 26) + 97);
	}
}

void Decryption()
{
	int i, j, k;

	FindingInverse();
	for (i = 0; i < textLen; i++)
	{
		for (j = 0; j < 1; j++)
		{
			for (k = 0; k < textLen; k++)
			{
				Decrypted[i][j] = Decrypted[i][j] + cipherKey[i][k] * Encrypted[k][j];
			}
		}
	}

	cout << "\nDecrypted Text is: ";
	for (i = 0; i < textLen; i++)
	{
		cout << (char)(fmod(Decrypted[i][0], 26) + 97);
	}

	cout << "\n";
}

void getData()
{
	int i, j;
	char msg[textLen];

	cout << "Enter the Key in Text(It should be inversible):\n";
	char text[textLen][textLen];
	for (int i = 0; i < textLen; i++)
	{
		for (j = 0; j < textLen; j++)
		{
			cin >> text[i][j];
		}
	}

	for (i = 0; i < textLen; i++)
	{
		for (j = 0; j < textLen; j++)
		{
			if ((text[i][j] >= 65 && text[i][j] <= 90) || (text[i][j] >= 97 && text[i][j] <= 122))
			{
				key[i][j] = charConversion(text[i][j]) - 1;
			}
			ar[i][j] = key[i][j];
		}
	}

	cout << endl
		 << "Equivalent Matrix: " << endl;
	for (i = 0; i < textLen; i++)
	{
		for (j = 0; j < textLen; j++)
		{
			cout << ar[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl
		 << endl;

	cout << "\nEnter the Plain Text that you want to Encrypt: ";
	cin >> msg;

	for (i = 0; i < textLen; i++)
	{
		message[i][0] = msg[i] - 97;
	}
}

//Finding Inverse Matrix for Decryption
void findingInverse()
{
	int i, j, k;
	double p, q;

	for (i = 0; i < textLen; i++)
	{
		for (j = 0; j < textLen; j++)
		{
			if (i == j)
				cipherKey[i][j] = 1;
			else
				cipherKey[i][j] = 0;
		}
	}

	for (k = 0; k < textLen; k++)
	{
		for (i = 0; i < textLen; i++)
		{
			p = ar[i][k];
			q = ar[k][k];

			for (j = 0; j < textLen; j++)
			{
				if (i != k)
				{
					ar[i][j] = ar[i][j] * q - p * ar[k][j];
					cipherKey[i][j] = cipherKey[i][j] * q - p * cipherKey[k][j];
				}
			}
		}
	}
	for (i = 0; i < textLen; i++)
	{
		for (j = 0; j < textLen; j++)
		{
			cipherKey[i][j] = cipherKey[i][j] / ar[i][i];
		}
	}

	/*
	cout << "\n\nInverse Matrix is:\n";
	for (i = 0; i < textLen; i++)
	{
		for (j = 0; j < textLen; j++) {
			cout << cipherKey[i][j] << " ";
		}
		cout << "\n";
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
