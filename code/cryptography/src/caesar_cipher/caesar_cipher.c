// A C program to illustrate Caesar Cipher Technique

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//argc gives the number of arguments and argv[1] gives the key of the cipher
int main(int argc, char* argv[])
{
    if(argc == 2)
    {
        int r = atoi(argv[1]);  //Converts key from string type to integer type and stores in r
        printf("plaintext: ");
        char s[100];            //Stores plaintext
        scanf("%s", s);
        
        printf("ciphertext: \n");
        
        //Traverses through all characters of plaintext
        for(int i = 0; i < strlen(s); i++)
        {
            if(isalpha(s[i]))           //Checks if the character is an alphabet
            {
                if(isupper(s[i]))       //Checks if the character is an uppercase alphabet
                {
                    printf("%c",((s[i] - 65 + r) % 26) + 65);   //Performs encryption
                }
                
                if(islower(s[i]))       //Checks if the character is an lowercase alphabet
                {  
                    printf("%c",((s[i] - 97 + r) % 26) + 97);   //Performs encryption
                }
            }
            
            else
            
                printf("%c",s[i]);  //Simply prints the character if it is not an alphabet
            
        }
        printf("\n");
        return 0;
    }
    
    else        //If key is not given as argument argv[1]
    {
        printf("Invalid key Entered.\n");
        
        return 1;

    }
}
