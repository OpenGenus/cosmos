#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

void flush_stdin()
{
    while(fgetc(stdin) != '\n');
}

void AutoKeyCipher(char** Text, char key, int encrypt)
{
    int textSize, i, nextKey, keyValue, result;
    textSize = strlen((*Text));
    for(i=0;i<textSize;i++)
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
    
    cout << "Enter the Single Key word: ";
    cin >> key;
    
    cout << "Enter the Plain Text: ";
    cin >> plainText;
    
    cout << endl << endl << "The Plain Text is: " << plainText;
    /* 3rd argument decides whither to do 1-Encryption or 0-Decryption. */
    AutoKeyCipher(&plainText, key, 1);
    cout << endl << "The Text after Encryption(Cipher text) is: " << plainText;
    
    AutoKeyCipher(&plainText, key, 0);
    cout << endl << "After Decryption the Text is: " << plainText;
    
    free(plainText);
    return 0;
}

/*
Sample Input:
Enter the Single Key word: j //In A-Z, j will be at 11 index.
Enter the Plain Text: hello

Sample Output:
The Plain Text is: hello
The Text after Encryption(Cipher text) is: qlpwz
After Decryption the Text is: hello
*/

