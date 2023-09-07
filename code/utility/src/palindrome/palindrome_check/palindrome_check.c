#include <stdio.h>
#include <string.h>

#define MAX_STRING_LEN 256

void isPalindrome(char str[]) //Iterative function to check if a string is palindrome
{
    // Start from leftmost and rightmost corners of the string
    int l = 0;
    int h = strlen(str) - 1;
 
    // Keep comparing characters while they are same
    while (h > l)
    {
        if (str[l++] != str[h--])
        {
            printf("%s is Not Palindrome\n", str);
            return;
        }
    }
    printf("%s is palindrome\n", str);
}
 
// Driver program to test above function
int main()
{
    char string[MAX_STRING_LEN];
    printf("Give the string to be checked:\n");
    scanf("%s", string); // Scan the string to be taken
    isPalindrome(string);
    return 0;
}
