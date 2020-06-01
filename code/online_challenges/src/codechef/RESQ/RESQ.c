#include <stdio.h>
#include <math.h>

int fun(int area) 
{
    int p, j;
    int flag = area - 1;
    for (j = 1; j <= (int)(sqrt(area)); ++j)
        if (area % j == 0) 
        {
            p = abs(((int) area / j) - j);
            if (p < flag)
                flag = p;
        }
    return flag;
}
int main() 
{
    int n, i, area, ans;
    scanf("%d", & n);
    for (i = 0; i < n; ++i) 
    {
        scanf("%d", & area);
        ans = fun(area);
        printf("%d\n", ans);
    }
}
