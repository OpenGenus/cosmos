#include<stdio.h>
#include<string.h>

int main() 
{
    int t;
    scanf("%d\n", & t);
    while (t--) 
    {
        char a[1000005];
        gets(a);
        int c = 0, i = 0, ans = 0;
        while (a[i] != '\0') 
        {
            if (a[i] == '<') 
            {
                ++c;
            } 
            else 
            {
                --c;
            }
            if (c == 0) 
            {
                ans = i + 1;
            } else if (c < 0)
                break;
            ++i;
        }
        printf("%d\n", ans);
    }
}
