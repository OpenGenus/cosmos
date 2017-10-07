#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isalphastr (char*);

int main (void)
{
  char k[100] = "ovaltine";
  char p[100] = "Meet me at 11:00 AM sharp.";
  
    if(!isalphastr(k))
    {
        printf("The Key should be strictly alphabetical.\n");
        return 1;
    }
    
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

int isalphastr(char key[])
{
    for (int i = 0, j = strlen(key); i < j; i++)
    {
        if (!isalpha(key[i]))
        {
            return 0;
        }
    }
    
    return 1;
}
