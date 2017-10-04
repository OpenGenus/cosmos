#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

bool isalphastr (string);

int main (int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./vigenere k\n");
        return 1;
    }
    else 
    {
        if(!isalphastr(argv[1]))
        {
            printf("Usage: ./vigenere k\n");
            return 1;
        }
    }
    
    printf("plaintext: ");
    string p = get_string();
    
    string k = argv[1];
    
    printf("ciphertext: ");
    
    int offset, k_len = strlen(k);
    
    for (int i = 0; i < k_len; i++)
    {
        char type = (isupper(k[i])) ? 'A' : 'a';
        k[i] -= type;
    }
    
    for (int i = 0, j = 0, p_len = strlen(p); i < p_len; i++)
    {
        offset = j % k_len;
        
        if (!isalpha(p[i]))
        {
            printf("%c", p[i]);
            continue;
        }
        
        char type = (isupper(p[i])) ? 'A' : 'a';
        printf("%c", (((p[i] - type) + k[offset]) % 26) + type);
        
        j++;
    }
    
    printf("\n");
    return 0;
}

bool isalphastr(string key)
{
    for (int i = 0, j = strlen(key); i < j; i++)
    {
        if (!isalpha(key[i]))
        {
            return false;
        }
    }
    
    return true;
}
