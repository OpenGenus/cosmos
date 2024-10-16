// C program to implement Playfair Cipher

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 30

// function to convert the string to lowercase
void toLowerCase(char arr[], int ps)
{
	int i;
	for (i = 0; i < ps; i++) {
		if (arr[i] > 64 && arr[i] < 91)
			arr[i] += 32;
	}
}

// function to remove all spaces in a string
int removeSpaces(char* arr, int ps)
{
	int i, count = 0;
	for (i = 0; i < ps; i++)
		if (arr[i] != ' ')
			arr[count++] = arr[i];
	arr[count] = '\0';
	return count;
}

// function to generate the 5x5 square matrix key
void generateKeyTable(char arr[], int ks, char key_M[5][5])
{
	int i, j, k, flag = 0, *arr1;

	// hashmap to store count of the alphabet
	arr1 = (int*)calloc(26, sizeof(int));
	for (i = 0; i < ks; i++) {
		if (arr[i] != 'j')
			arr1[arr[i] - 97] = 2;
	}

	arr1['j' - 97] = 1;

	i = 0;
	j = 0;

	for (k = 0; k < ks; k++) {
		if (arr1[arr[k] - 97] == 2) {
			arr1[arr[k] - 97] -= 1;
			key_M[i][j] = arr[k];
			j++;
			if (j == 5) {
				i++;
				j = 0;
			}
		}
	}

	for (k = 0; k < 26; k++) {
		if (arr1[k] == 0) {
			key_M[i][j] = (char)(k + 97);
			j++;
			if (j == 5) {
				i++;
				j = 0;
			}
		}
	}
}

// Function to search for the characters of a digraph
// in the key square and return their position
void search(char key_M[5][5], char a, char b, int arr[])
{
	int i, j;

	if (a == 'j')
		a = 'i';
	else if (b == 'j')
		b = 'i';

	for (i = 0; i < 5; i++) {

		for (j = 0; j < 5; j++) {

			if (key_M[i][j] == a) {
				arr[0] = i;
				arr[1] = j;
			}
			else if (key_M[i][j] == b) {
				arr[2] = i;
				arr[3] = j;
			}
		}
	}
}

// function to find the modulus with 5
int mod5(int a)
{
	return (a % 5);
}

// function to make the plain text length to be even
int prepare(char arr[], int n)
{
	if (n % 2 != 0) {
		arr[n++] = 'z';
		arr[n] = '\0';
	}
	return n;
}

// function for assistance in encryption of the data
void encrypt(char arr[], char key_M[5][5], int ps)
{
	int i, arr1[4];

	for (i = 0; i < ps; i += 2) {

		search(key_M, arr[i], arr[i + 1], arr1);

		if (arr1[0] == arr1[2]) {
			arr[i] = key_M[arr1[0]][mod5(arr1[1] + 1)];
			arr[i + 1] = key_M[arr1[0]][mod5(arr1[3] + 1)];
		}
		else if (arr1[1] == arr1[3]) {
			arr[i] = key_M[mod5(arr1[0] + 1)][arr1[1]];
			arr[i + 1] = key_M[mod5(arr1[2] + 1)][arr1[1]];
		}
		else {
			arr[i] = key_M[arr1[0]][arr1[3]];
			arr[i + 1] = key_M[arr1[2]][arr1[1]];
		}
	}
}

// function to encrypt using Playfair Cipher
void encryptByPlayfairCipher(char arr[], char key[])
{
	char ps, ks, key_M[5][5];

	// Key
	ks = strlen(key);
	ks = removeSpaces(key, ks);
	toLowerCase(key, ks);

	// Plaintext
	ps = strlen(arr);
	toLowerCase(arr, ps);
	ps = removeSpaces(arr, ps);

	ps = prepare(arr, ps);

	generateKeyTable(key, ks, key_M);

	encrypt(arr, key_M, ps);
}

// Main function that gets executed first
int main()
{
	char arr[SIZE], key[SIZE];

	// Key to be encrypted
	strcpy(key, "Germany");
	printf("Key: %s\n", key);

	// Plaintext to be encrypted
	strcpy(arr, "Dusseldorf");
	printf("Text to be encrypted: %s\n", arr);

	// encrypt using Playfair Cipher
	encryptByPlayfairCipher(arr, key);

	printf("Cipher: %s\n", arr);

	return 0;
}

// C program to implement Playfair Cipher

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 30

// function to convert the string to lowercase
void toLowerCase(char arr[], int ps)
{
	int i;
	for (i = 0; i < ps; i++) {
		if (arr[i] > 64 && arr[i] < 91)
			arr[i] += 32;
	}
}

// function to remove all spaces in a string
int removeSpaces(char* arr, int ps)
{
	int i, count = 0;
	for (i = 0; i < ps; i++)
		if (arr[i] != ' ')
			arr[count++] = arr[i];
	arr[count] = '\0';
	return count;
}

// function to generate the 5x5 square matrix key
void generateKeyTable(char arr[], int ks, char key_M[5][5])
{
	int i, j, k, flag = 0, *arr1;

	// hashmap to store count of the alphabet
	arr1 = (int*)calloc(26, sizeof(int));
	for (i = 0; i < ks; i++) {
		if (arr[i] != 'j')
			arr1[arr[i] - 97] = 2;
	}

	arr1['j' - 97] = 1;

	i = 0;
	j = 0;

	for (k = 0; k < ks; k++) {
		if (arr1[arr[k] - 97] == 2) {
			arr1[arr[k] - 97] -= 1;
			key_M[i][j] = arr[k];
			j++;
			if (j == 5) {
				i++;
				j = 0;
			}
		}
	}

	for (k = 0; k < 26; k++) {
		if (arr1[k] == 0) {
			key_M[i][j] = (char)(k + 97);
			j++;
			if (j == 5) {
				i++;
				j = 0;
			}
		}
	}
}

// Function to search for the characters of a digraph
// in the key square and return their position
void search(char key_M[5][5], char a, char b, int arr[])
{
	int i, j;

	if (a == 'j')
		a = 'i';
	else if (b == 'j')
		b = 'i';

	for (i = 0; i < 5; i++) {

		for (j = 0; j < 5; j++) {

			if (key_M[i][j] == a) {
				arr[0] = i;
				arr[1] = j;
			}
			else if (key_M[i][j] == b) {
				arr[2] = i;
				arr[3] = j;
			}
		}
	}
}

// function to find the modulus with 5
int mod5(int a)
{
	return (a % 5);
}

// function to make the plain text length to be even
int prepare(char arr[], int n)
{
	if (n % 2 != 0) {
		arr[n++] = 'z';
		arr[n] = '\0';
	}
	return n;
}

// function for assistance in encryption of the data
void encrypt(char arr[], char key_M[5][5], int ps)
{
	int i, arr1[4];

	for (i = 0; i < ps; i += 2) {

		search(key_M, arr[i], arr[i + 1], arr1);

		if (arr1[0] == arr1[2]) {
			arr[i] = key_M[arr1[0]][mod5(arr1[1] + 1)];
			arr[i + 1] = key_M[arr1[0]][mod5(arr1[3] + 1)];
		}
		else if (arr1[1] == arr1[3]) {
			arr[i] = key_M[mod5(arr1[0] + 1)][arr1[1]];
			arr[i + 1] = key_M[mod5(arr1[2] + 1)][arr1[1]];
		}
		else {
			arr[i] = key_M[arr1[0]][arr1[3]];
			arr[i + 1] = key_M[arr1[2]][arr1[1]];
		}
	}
}

// function to encrypt using Playfair Cipher
void encryptByPlayfairCipher(char arr[], char key[])
{
	char ps, ks, key_M[5][5];

	// Key
	ks = strlen(key);
	ks = removeSpaces(key, ks);
	toLowerCase(key, ks);

	// Plaintext
	ps = strlen(arr);
	toLowerCase(arr, ps);
	ps = removeSpaces(arr, ps);

	ps = prepare(arr, ps);

	generateKeyTable(key, ks, key_M);

	encrypt(arr, key_M, ps);
}

// Main function that gets executed first
int main()
{
	char arr[SIZE], key[SIZE];

	// Key to be encrypted
	strcpy(key, "Germany");
	printf("Key: %s\n", key);

	// Plaintext to be encrypted
	strcpy(arr, "Dusseldorf");
	printf("Text to be encrypted: %s\n", arr);

	// encrypt using Playfair Cipher
	encryptByPlayfairCipher(arr, key);

	printf("Cipher: %s\n", arr);

	return 0;
}


// OUTPUT
// Key: Germany
// Text to be encrypted: Dusseldorf
// Cipher: nzoxahntgi

// Code curated by Subhadeep Das(username:- Raven1233)