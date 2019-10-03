#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main(int argc, char* argv[])
{
    if(argc == 2)
    {
        int r = atoi(argv[1]);
        printf("plaintext: ");
        char s[100];
        scanf("%s", s);
        
        printf("ciphertext: \n");
        
        for(int i = 0; i < strlen(s); i++)
        {
            if(isalpha(s[i]))
            {
                if(isupper(s[i]))
                {
                    printf("%c",((s[i] - 65 + r) % 26) + 65);
                }
                
                if(islower(s[i]))
                {
                    printf("%c",((s[i] - 97 + r) % 26) + 97);
                }
            }
            
            else
            
                printf("%c",s[i]);
            
        }
        printf("\n");
        return 0;
    }
    
    else
    {
        printf("Invalid key Entered.\n");
        
        return 1;

    }
}
