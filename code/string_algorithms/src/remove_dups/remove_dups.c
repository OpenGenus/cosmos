#include <stdio.h>

/* Part of Cosmos by OpenGenus Foundation */
void
remove_dups(char *ptr_str)
{
    char *str_temp = ptr_str + 1;
    while (*str_temp != '\0')
    {

        if (*ptr_str != *str_temp)
        {
            ptr_str++;
            *ptr_str = *str_temp;
        }
        str_temp++;

    }
    ptr_str++;
    *ptr_str = '\0';
}

int
main()
{
    char str[256];
    printf("Enter string: ");
    fgets(str, 256, stdin);
    remove_dups(str);
    printf("Resultant string: %s\n", str);
    return (0);
}
