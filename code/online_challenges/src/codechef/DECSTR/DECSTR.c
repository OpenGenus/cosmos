#include<stdio.h>

int main() 
{
    int t;
    scanf("%d", & t);
    while (t--) 
    {
        int i, k;
        scanf("%d", & k);
        int a = k / 25;
        int b = k % 25;
        if (b != 0) 
        {
            for (i = 97 + b; i >= 97; i--)
                printf("%c", i);
        }
        while (a--) 
        {
            for (i = 122; i >= 97; i--)
                printf("%c", i);
        }
        printf("\n");
    }
    return 0;
}
