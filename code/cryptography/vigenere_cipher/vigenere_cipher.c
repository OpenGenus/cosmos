// Vigenere Cipher

// Author: Rishav Pandey

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char* argv[])
{
    //check if user give more or less than two arguments.
    if(argc != 2)
    {
        printf("Enter the Valid Key");
        return 1;
    }
    
    else
    {
        
        for(int i =0, n = strlen(argv[1]); i<n ;i++)
        {
            //check weather the key is only alphabet or not
            if(!isalpha(argv[1][i]))
            {
                printf("Enter only Alphabets");
                return 1;
                
            }
        }
    }
    
    printf("plaintext:  ");
    char s[100];
    scanf("%s", s);
    char* k = argv[1];
    
    int klen = strlen(k);
    
    
    printf("ciphertext: ");
    
    for(int i = 0, j = 0, n = strlen(s); i<n ; i++)
    {
        //wrap key for plaintext.
        int key = tolower(k[j % klen]) - 97;
        
        if(isalpha(s[i]))
            {
                    //for upper case letters.
                if(isupper(s[i]))
                {
                    printf("%c",((s[i]-65+key)%26)+65); 
                    
                    //increase key for next char.
                    j++;
                    
                }   
                    //for lower case letters.
                else if(islower(s[i]))
                {
                    printf("%c",((s[i]-97+key)%26)+97); 
                    //for lower case letters.
                    j++; 
                    //increase key for next char.
                    
                }
                    
            }
            
            //for non alphabetical values.
        else
            
        {
            printf("%c",s[i]); 
            
        }
    }
    printf("\n");
    return 0;
}