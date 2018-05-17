/*
 * Part of Cosmos by OpenGenus Foundation.
 * Program to check if a given string is a valid IPv4 address or not.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
 
#define DELIM "."
 
/* return 1 if string contain only digits, else return 0 */
int 
valid_digit(char *ip_str)
{
    while (*ip_str) {
        if (*ip_str >= '0' && *ip_str <= '9')
            ++ip_str;
        else
            return (0);
    }
    return (1);
}
 
/* return 1 if IP string is valid, else return 0 */
int 
is_valid_ip(char* ip_str)
{
    int i, num, dots = 0;
    char *ptr;

    if (ip_str == NULL)
        return (0);

    /* See following link for strtok()
       http://pubs.opengroup.org/onlinepubs/009695399/functions/strtok_r.html */
    ptr = strtok(ip_str, DELIM);
 
    if (ptr == NULL)
        return (0);

    while (ptr) {
 
        /* after parsing string, it must contain only digits */
        if (!valid_digit(ptr))
            return (0);
 
        num = atoi(ptr);
 
        /* check for valid IP */
        if (num >= 0 && num <= 255) {
            /* parse remaining string */
            ptr = strtok(NULL, DELIM);
            if (ptr != NULL)
                ++dots;
        } else
            return (0);
    }
 
    /* valid IP string must contain 3 dots */
    if (dots != 3)
        return (0);
    return (1);
}

/* main: for testing */
int 
main(void)
{
    char ip_correct[] = "172.31.255.255";
    char ip_incorrect[] = "192.168.2.300";
    assert(is_valid_ip(ip_correct));
    assert(!is_valid_ip(ip_incorrect));
    return (0);
}
