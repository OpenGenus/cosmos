// Play Fair Cipher in C

// Link to the Article(Explanation): https://iq.opengenus.org/play-fair-cipher/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

void matrix(char key[], int keysize, char matrixx[5][5])
{
    int i, j, flag = 0, *temp;
    temp = (int *)calloc(26, sizeof(int));
    for (i = 0; i < keysize; ++i)
    {
        if (key[i] != 'j')
            temp[key[i] - 97] = 2;
    }
    temp['j' - 97] = 1;
    i = 0;
    j = 0;
    for (int k = 0; k < keysize; ++k)
    {
        if (temp[key[k] - 97] == 2)
        {
            temp[key[k] - 97] -= 1;
            matrixx[i][j] = key[k];
            j++;
            if (j == 5)
            {
                i++;
                j = 0;
            }
        }
    }
    for (int k = 0; k < 26; ++k)
    {
        if (temp[k] == 0)
        {
            matrixx[i][j] = (char)(k + 97);
            j++;
            if (j == 5)
            {
                i++;
                j = 0;
            }
        }
    }
}

void choosechar(char matrixx[5][5], char a, char b, int arr[])
{
    if (a == 'j')
        a = 'i';
    else if (b == 'j')
        b = 'i';

    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            if (matrixx[i][j] == a)
            {
                arr[0] = i;
                arr[1] = j;
            }
            else if (matrixx[i][j] == b)
            {
                arr[2] = i;
                arr[3] = j;
            }
        }
    }
}

int mod(int a)
{
    return (a % 5);
}

int removing(char *plain, int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
        if (plain[i] != ' ')
            plain[count++] = plain[i];
    plain[count] = '\0';
    return count;
}

void playfair(char text[], char key[], int e_d)
{
    char keysize, textsize, matrixx[5][5];
    keysize = strlen(key);
    textsize = strlen(text);
    keysize = removing(key, keysize);
    textsize = removing(text, textsize);

    matrix(key, keysize, matrixx);

    int a[4];
    for (int i = 0; i < textsize; i += 2)
    {
        choosechar(matrixx, text[i], text[i + 1], a);
        if (a[0] == a[2] && e_d)
        {
            text[i] = matrixx[a[0]][mod(a[1] + 1)];
            text[i + 1] = matrixx[a[0]][mod(a[3] + 1)];
        }
        else if (a[1] == a[3] && e_d)
        {
            text[i] = matrixx[mod(a[0] + 1)][a[1]];
            text[i + 1] = matrixx[mod(a[2] + 1)][a[1]];
        }
        else if (a[0] == a[2] && !e_d)
        {
            text[i] = matrixx[a[0]][mod(a[1] - 1)];
            text[i + 1] = matrixx[a[0]][mod(a[3] - 1)];
        }
        else if (a[1] == a[3] && !e_d)
        {
            text[i] = matrixx[mod(a[0] - 1)][a[1]];
            text[i + 1] = matrixx[mod(a[2] - 1)][a[1]];
        }
        else
        {
            text[i] = matrixx[a[0]][a[3]];
            text[i + 1] = matrixx[a[2]][a[1]];
        }
    }
}

int main()
{
    char plaintext[MAX], key[MAX];
    strcpy(key, "harry");

    strcpy(plaintext, "my name is ravi");
    printf("\nPlain text: %s\n", plaintext);

    playfair(plaintext, key, 1); //3rd argument is for Encryption
    printf("\nEncrypted Text(Cipher Text) is: %s\n", plaintext);

    playfair(plaintext, key, 0); //3rd argument is for Decryption
    printf("\nDecrypted text: %s\n", plaintext);

    return 0;
}

/*
Sample Output:

Plain text: my name is ravi

Encrypted Text(Cipher Text) is: sfkblfmoyruk

Decrypted text: mynameisravi
*/
