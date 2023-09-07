#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <math.h>

int main()
{
    char s[100];
    scanf("%[^\n]", s);
    int l = strlen(s);
    int r = (int) floor(sqrt(l));
    float m = sqrt(l) - r;
    if (m > 0.5)
        r = r + 1;
    int c = (int) ceil(sqrt(l));
    char a[r][c];
    int i, j;
    for (i = 0; i < r; ++i)
    {
        for (j = 0; j < c; ++j)
            a[i][j] = ' ';
    }
    int k = 0, f = 0;
    for (i = 0; i < r; ++i)
    {
        for (j = 0; j < c; ++j)
        {
            a[i][j] = s[k];
            ++k;
            if (k == (l))
                f = 1;
            if (f == 1)
                break;
        }
        if (f == 1)
            break;
    }
    for (i = 0; i < c; ++i)
    {
        for (j = 0; j < r; ++j)
        {
            if (a[j][i] != ' ')
                printf("%c", a[j][i]);
        }
        printf(" ");
    }
}
