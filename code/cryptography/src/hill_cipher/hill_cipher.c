#include <stdio.h>
#include <math.h>
#define textlen 3 // Plain text length
#define ascii_difference 31

double encrypted[textlen][1], decrypted[textlen][1], key[textlen][textlen], cipherkey[textlen][textlen], message[textlen][1], ar[textlen][textlen];

void encryption();
void decryption();
void getdata();
void findinversematrix();

void main()
{
	getdata();
	encryption();
	decryption();
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
	printf("\nEncrypted Text is: ");
	for (int i = 0; i < textlen; ++i)
	{
		printf("%c", (char)(fmod(encrypted[i][0], 26) + 97));
	}
}

void decryption()
{
	findinversematrix();
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

	printf("\nDecrypted Text is: ");
	for (int i = 0; i < textlen; ++i)
	{
		printf("%c", (char)(fmod(decrypted[i][0], 26) + 97));
	}
	printf("\n");
}

int charconvert(char input_char)
{
	return (input_char & ascii_difference);
}

void getdata()
{
	char msg[textlen], text[textlen][textlen];

	//Here, Inversible means, it should be multiplicative inverse of the plain text.
	//If plain text is of 3 letters, then key should be 3*3(textlen*textlen).
	printf("Enter the Key in Text(It should be inversible): \n");
	for (int i = 0; i < textlen; ++i)
	{
		for (int j = 0; j < textlen; ++j)
		{
			scanf("%c", &text[i][j]);
		}
	}

	//Converting Key text to ASCII values
	for (int i = 0; i < textlen; ++i)
	{
		for (int j = 0; j < textlen; ++j)
		{
			if ((text[i][j] >= 65 && text[i][j] <= 90) || (text[i][j] >= 97 && text[i][j] <= 122))
			{
				key[i][j] = charconvert(text[i][j]) - 1;
			}
			ar[i][j] = key[i][j];
		}
	}

	printf("\nEquivalent Matrix: \n");
	for (int i = 0; i < textlen; ++i)
	{
		for (int j = 0; j < textlen; ++j)
		{
			printf("%.0f ", ar[i][j]);
		}
		printf("\n");
	}

	//Plain Text
	printf("\nEnter the Plain Text that you want to Encrypt: ");
	scanf("%s", msg);
	for (int i = 0; i < textlen; ++i)
	{
		message[i][0] = msg[i] - 97;
	}
}

//Finding Inverse Matrix for Decryption
void findinversematrix()
{
	float p, q;
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
	/*
	printf("\n\nInverse Matrix is:\n");
	for (int i = 0; i < textlen; i++)
	{
		for (int j = 0; j < textlen; j++)
		{
			printf("%d ", cipherkey[i][j]);
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
