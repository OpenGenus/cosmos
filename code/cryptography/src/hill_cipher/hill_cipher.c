#include <stdio.h>
#include <math.h>
#define textLen 3 // Plain text length
#define ASCII_difference 31

double encrypted[textLen][1], decrypted[textLen][1], key[textLen][textLen], cipherKey[textLen][textLen], message[textLen][1], ar[textLen][textLen];

void Encryption();
void Decryption();
void getData();
void findInverseMat();

void main()
{
	getData();
	Encryption();
	Decryption();
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
				encrypted[i][j] = encrypted[i][j] + key[i][k] * message[k][j];
			}
		}
	}
	printf("\nEncrypted Text is: ");
	for (i = 0; i < textLen; i++)
	{
		printf("%c", (char)(fmod(encrypted[i][0], 26) + 97));
	}
}

void Decryption()
{
	int i, j, k;

	findInverseMat();
	for (i = 0; i < textLen; i++)
	{
		for (j = 0; j < 1; j++)
		{
			for (k = 0; k < textLen; k++)
			{
				decrypted[i][j] = decrypted[i][j] + cipherKey[i][k] * encrypted[k][j];
			}
		}
	}

	printf("\nDecrypted Text is: ");
	for (i = 0; i < textLen; i++)
	{
		printf("%c", (char)(fmod(decrypted[i][0], 26) + 97));
	}
	printf("\n");
}

int charConvert(char input_char)
{
	return (input_char & ASCII_difference);
}

void getData()
{
	int i, j;
	char msg[textLen], text[textLen][textLen];

	//Here, Inversible means, it should be multiplicative inverse of the plain text.
	//If plain text is of 3 letters, then key should be 3*3(textLen*textLen).
	printf("Enter the Key in Text(It should be inversible): \n");
	for (int i = 0; i < textLen; i++)
	{
		for (j = 0; j < textLen; j++)
		{
			scanf("%c", &text[i][j]);
		}
	}

	//Converting Key text to ASCII values
	for (i = 0; i < textLen; i++)
	{
		for (j = 0; j < textLen; j++)
		{
			if ((text[i][j] >= 65 && text[i][j] <= 90) || (text[i][j] >= 97 && text[i][j] <= 122))
			{
				key[i][j] = charConvert(text[i][j]) - 1;
			}
			ar[i][j] = key[i][j];
		}
	}

	printf("\nEquivalent Matrix: \n");
	for (i = 0; i < textLen; i++)
	{
		for (j = 0; j < textLen; j++)
		{
			printf("%.0f ", ar[i][j]);
		}
		printf("\n");
	}

	//Plain Text
	printf("\nEnter the Plain Text that you want to Encrypt: ");
	scanf("%s", msg);
	for (i = 0; i < textLen; i++)
	{
		message[i][0] = msg[i] - 97;
	}
}

//Finding Inverse Matrix for Decryption
void findInverseMat()
{
	int i, j, k;
	float p, q;
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
	printf("\n\nInverse Matrix is:\n");
	for (i = 0; i < textLen; i++)
	{
		for (j = 0; j < textLen; j++)
		{
			printf("%d ", cipherKey[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	*/
}
//End of Code

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
