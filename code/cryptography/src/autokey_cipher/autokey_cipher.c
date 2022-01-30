#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void flush_stdin()
{
    while (fgetc(stdin) != '\n')
        ;
}

void autokeycipher(char **text, char key, int encrypt)
{
    int textsize;

    textsize = strlen((*text));

    for (int i = 0; i < textsize; ++i)
    {
        if (isalpha((*text)[i]))
        {
            (*text)[i] = toupper((*text)[i]);
        }
    }

    int nextkey, keyvalue, result;
    nextkey = toupper(key) - 'A';

    for (int i = 0; i < textsize; ++i)
    {
        if (isalpha((*text)[i]))
        {
            keyvalue = nextkey;
            if (encrypt)
            {
                nextkey = (*text)[i] - 'A';
                (*text)[i] = ((*text)[i] - 'A' + keyvalue) % 26 + 'A';
            }
            else
            {
                result = ((*text)[i] - 'A' - keyvalue) % 26 + 'A';
                (*text)[i] = result < 'A' ? (result + 26) : (result);
                nextkey = (*text)[i] - 'A';
            }
        }
    }
}

int main(int argc, char **argv)
{
    char key, *plaintext;

    printf("Enter the Single Key word: ");
    scanf("%c", &key);

    int length;
    printf("Enter the length of Plain Text: ");
    scanf("%d", &length);

    plaintext = (char *)malloc((length + 1) * sizeof(char));
    flush_stdin();

    printf("Enter the Plain Text: ");
    fgets(plaintext, length + 1, stdin);
    flush_stdin();

    printf("\nThe Plain Text is: %s", plaintext);
    /* 3rd argument decides whither to do 1-Encryption or 0-Decryption. */
    autokeycipher(&plaintext, key, 1);
    printf("\nThe Text after Encryption(Cipher text) is: %s", plaintext);

    autokeycipher(&plaintext, key, 0);
    printf("\nAfter Decryption the Text is: %s", plaintext);

    free(plaintext);
    return 0;
}

/*
Sample Input:
Enter the Single Key word: L //In A-Z, L will be at 11 index.
Enter the length of Plain Text: 5
Enter the Plain Text: hello
Sample Output:
The Plain Text is: hello
The Text after Encryption(Cipher text) is: slpwz
After Decryption the Text is: hello
*/
