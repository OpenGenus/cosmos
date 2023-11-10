#include <stdio.h>
#include <string.h>

int isPalindrome(char *arr)
{
    int length = strlen(arr);
    int i, j;
    for(i = 0, j = length - 1; i < length / 2; ++i, --j) 
    {
        if(arr[i] != arr[j]) 
        {
            return 0;
        }
    }
    return 1;
}

int main() 
{
    printf("%d\n", isPalindrome("terabyte"));
    printf("%d\n", isPalindrome("nitin"));
    printf("%d\n", isPalindrome("gurkirat"));
    printf("%d\n", isPalindrome("lol"));

    
    // Output
    // 0
    // 1
    // 0
    // 1
}