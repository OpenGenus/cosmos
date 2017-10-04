#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
// Part of Cosmos by OpenGenus Foundation
int main (int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }
    
    int k = atoi(argv[1]);
    
    printf("plaintext: ");
    string p = get_string();
    
    printf("ciphertext: ");
    
    for (int i = 0, type, j = strlen(p); i < j; i++)
    {
        if (!isalpha(p[i]))
        {
            printf("%c", p[i]);
            continue;
        }
        
        type = (isupper(p[i])) ? 'A' : 'a';
        
        printf("%c", (((p[i] - type) + k) % 26) + type);
    }
    
    printf("\n");
    
    return 0;
}
