#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void flush_stdin()
{
    while(fgetc(stdin) != '\n');
}

void AutoKeyCipher(char** Text, char key, int encrypt)
{
    int textSize, i, nextKey, keyValue, result;
    
    textSize = strlen((*Text));
    
    for(i = 0; i < textSize; i++)
    {
        if(isalpha((*Text)[i]))
        {
            (*Text)[i] = toupper((*Text)[i]);
        }
    }
    
    nextKey = toupper(key) - 'A';
    
    for(i = 0; i < textSize; i++)
    {
        if(isalpha((*Text)[i]))
        {
            keyValue = nextKey;
            if(encrypt)
            {
                nextKey = (*Text)[i] - 'A';
                (*Text)[i] = ((*Text)[i] - 'A' + keyValue)%26 + 'A';
            }
            else
            {
                result = ((*Text)[i] - 'A' - keyValue)%26 + 'A';
                (*Text)[i] = result < 'A' ? (result + 26) : (result);
                nextKey = (*Text)[i] - 'A';
            }
        }
    }
}


int main(int argc, char **argv)
{
    int length;
    char key, *plainText;
    
    printf("Enter the Single Key word: ");
    scanf("%c", &key);
    
    printf("Enter the length of Plain Text: ");
    scanf("%d", &length);
    
    plainText = (char*) malloc((length + 1) * sizeof(char));
    flush_stdin();
    
    printf("Enter the Plain Text: ");
    fgets(plainText, length+1, stdin);
    flush_stdin();
    
    printf("\nThe Plain Text is: %s", plainText);
    /* 3rd argument decides whither to do 1-Encryption or 0-Decryption. */
    AutoKeyCipher(&plainText, key, 1);
    printf("\nThe Text after Encryption(Cipher text) is: %s", plainText);
    
    AutoKeyCipher(&plainText, key, 0);
    printf("\nAfter Decryption the Text is: %s", plainText);
    
    free(plainText);
    return 0;
}

/*
Sample Input:

Enter the Single Key word: j //In A-Z, j will be at 11 index.
Enter the length of Plain Text: 5
Enter the Plain Text: hello

Sample Output:
The Plain Text is: hello
The Text after Encryption(Cipher text) is: qlpwz
After Decryption the Text is: hello
*/

