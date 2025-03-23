#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int t;
    scanf("%d", & t);
    while (t--) 
    {
        int n, c, m;
        scanf("%d %d %d", & n, & c, & m);
        int ch = n / c;
        int wr = n / c;
        int sum = ch;
        while (wr >= m) 
        {
            ch = ch / m;
            sum += ch;
            wr = wr % m;
            wr += ch;
            ch = wr;
        }
        printf("%d\n", sum);
    }
}
